<p align="center">
  <img src="push_swap_100_visualizer.gif" alt="Push Swap Visualizer (100 numbers)" width="900">
</p>

# push_swap – 42 School Project

`push_swap` is an algorithmic sorting project from **42 School**. The goal is to sort a stack of integers using a **limited set of operations**, while producing the **smallest possible number of moves**.

This project is not about sorting fast.
It’s about sorting **smart**.

---

## 🧠 Overview

The program receives a list of integers and sorts them using **two stacks**:

* **Stack A** – main stack (initial data)
* **Stack B** – auxiliary stack

Only a restricted set of operations is allowed. Every printed instruction counts, so optimization is critical.

---

## ⚙️ Allowed Operations

* `sa`, `sb`, `ss` – swap the first two elements
* `pa`, `pb` – push top element between stacks
* `ra`, `rb`, `rr` – rotate stack up
* `rra`, `rrb`, `rrr` – reverse rotate stack

No cheating. No shortcuts.

---

## 🧩 Algorithm

This implementation is based on the **Turk Algorithm**, optimized for:

* **≤ 700 moves** for 100 numbers
* **≤ 5500 moves** for 500 numbers

Key ideas:

* Chunk-based pushing to stack B
* Cost calculation for each move
* Smart rotations (combined `rr` / `rrr` when possible)
* Final alignment of stack A

The visualizer above shows the algorithm sorting **100 numbers** in real time.

---

## 🚀 Usage

```bash
./push_swap 3 2 5 1 4
```

To test with many numbers:

```bash
ARG=$(shuf -i 1-1000 -n 100)
./push_swap $ARG | wc -l
```

---

## 🛠️ Build

```bash
git clone <repo-url>
cd push_swap
make
```

---

## 👀 Visualizer

A real **42 push_swap visualizer** was used to generate the GIF shown above, running the algorithm with **100+ numbers**.

Visualizers help validate:

* Correctness
* Efficiency
* Absence of infinite loops

---

## 📌 Notes

* Input is fully validated (duplicates, non-numeric values, overflow)
* No memory leaks
* Silent when input is already sorted

This project is a deep dive into **algorithmic optimization, decision-making, and performance tuning**.

---

## 🧪 Language

* C — 96.4%
* Makefile — 3.4%
