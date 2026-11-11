# Week 7 C Lab

Practice for asgn6 (unique): the three hard parts of a tree in C. You'll allocate nodes with
`calloc()`, walk the tree with recursion, and free every node in the right order.

Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week7-c-lab
```

## Family tree (`family.c`)
Each `Person` points to their `mom` and `dad`, so a family tree is a binary tree, like asgn6's
`Node` with `left` and `right`. `main()` is written for you: it builds Sam's family and calls
your functions. You write three of them, in order:

1. `person_new()`: allocate a `Person` with `calloc()`.
2. `count_people()`: count everyone in the tree with recursion.
3. `free_family()`: free every `Person`, printing `free NAME` just before each `free()`.

```bash
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
