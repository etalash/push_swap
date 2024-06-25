/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:07 by stalash           #+#    #+#             */
/*   Updated: 2024/06/11 19:33:10 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_extract_word(const char *s, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	len = ft_word_length(s, c);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**ft_extract_words(const char *s, char c, int word_count, \
								int *current_position)
{
	char	**words;
	int		i;

	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		words[i] = ft_extract_word(s, c);
		if (!words[i])
		{
			while (i-- > 0)
				free(words[i]);
			free(words);
			return (NULL);
		}
		(*current_position)++;
		s += ft_word_length(s, c);
		i++;
	}
	words[word_count] = NULL;
	return (words);
}

char	**s_split(char const *s, char c)
{
	char		**empty;
	int			word_count;
	static int	current_position = 0;

	if (!s || !*s)
	{
		empty = (char **)malloc(1 * sizeof(char *));
		if (empty)
			empty[0] = NULL;
		return (empty);
	}
	word_count = ft_word_count(s, c);
	if (word_count == 0)
	{
		empty = (char **)malloc(1 * sizeof(char *));
		if (empty)
			empty[0] = NULL;
		return (empty);
	}
	current_position = 0;
	return (ft_extract_words(s, c, word_count, &current_position));
}