
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)/includes

SRC = errors.c helper_func_1.c helper_func_2.c main.c push.c reverse_rotate.c rotate_both.c rotate.c s_split.c simple_sort.c sort.c subordinate_func.c swap.c utils.c
OBJ = $(SRC:.c=.o)

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
