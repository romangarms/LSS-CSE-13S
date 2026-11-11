# Week 7 C Lab

Practice for asgn6 (unique): the three hard parts of a tree in C. First a demo with one struct
(`calloc()`, `->`, `free()`), then a family tree on your own: allocate nodes, walk the tree with
recursion, and free every node in the right order.

Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week7-c-lab
```

## Warm-up: Tree Cards (`tree-cards/`)
A web page where you build a binary search tree one card at a time, then search it, print it in
order, and free it. Open it in your browser:
[Tree Cards](https://htmlpreview.github.io/?https://github.com/romangarms/LSS-CSE-13S/blob/main/week7-c-lab/tree-cards/index.html).
Or open it from your Codespace:
```bash
cd tree-cards && python3 -m http.server 8000     # then open the forwarded port 8000
```

## Part 1: Demo with your tutor (`1-demo/`)
`pet.c` makes one struct on the heap, uses it, and frees it. Write it together with your tutor:
`pet_new()` with `calloc()`, `main()` using `->`, then `pet_free()`. The correct result is at the
top of the file.
```bash
cd 1-demo
clang -Wall -Werror pet.c -o pet && ./pet
```

## Part 2: Family tree on your own (`2-solo/`)
Each `Person` points to their `mom` and `dad`, so a family tree is a binary tree, like asgn6's
`Node` with `left` and `right`. `main()` is written for you: it builds Sam's family and calls
your functions. You write three of them, in order:

1. `person_new()`: allocate a `Person` with `calloc()`, like `pet_new()`.
2. `count_people()`: count everyone in the tree with recursion.
3. `free_family()`: free every `Person`, printing `free NAME` just before each `free()`.

```bash
cd 2-solo
clang -Wall -Werror family.c -o family && ./family
./family > got.txt && diff -us expected.txt got.txt     # "identical" means it works
```
The program crashes until Part 1 works, because `main()` uses the pointers `person_new()` returns.

## Stretch (if you finish early)
- Write `int generations(Person *p)`: how many generations the tree goes back. Sam's goes back
  4 (Sam, Ana, Cora, Fay). Add one `printf()` to `main()` to show it.
- asgn6's `tree_free()` takes a `Tree **` so it can set the caller's pointer to `NULL`. Change
  `free_family()` to take a `Person **pp`, and set `*pp = NULL` after freeing. Call it as
  `free_family(&sam);` and check that `sam` is `NULL` afterward.

## Start over
From `week7-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
