# Week 6 C Lab

Practice for asgn4 (Left, Center, Right): building a program from several `.c` files with a
`Makefile`, `enum` types, `const` lookup arrays, turning `randi()` numbers into a range with `%`,
going around a circle of players, and global arrays.
Runs in your Codespace (or any Linux terminal with `clang` and `make`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week6-c-lab
```

## Level 1: Debug it (`1-debug/`)
`cookies.c` simulates a little game: four friends pass cookies around a table, using a die,
an `enum` of actions and a lookup array, like asgn4. It compiles, but the final result is wrong
because of **4 bugs**. The rules, the correct result, and what should always be true are at the top of the file.
```bash
cd 1-debug
clang -Wall -Werror cookies.c -o cookies && ./cookies
```
Add `printf()` lines so the program shows what happens on every turn (whose turn, the roll,
the action), and call `print_table()` after each turn. Read the trace from the top, find the first
turn where a rule breaks, fix that bug, and run it again. Take the prints out when you're done.

## Level 2: Rock, paper, scissors (`2-rps/`)
A program split across three `.c` files, like asgn4: `main.c` (given), `moves.c` (you write it)
and `randi.c` (the same random number generator as asgn4).

**Part A: write a `Makefile`.** Create a file named `Makefile` (capital M) in `2-rps/` so that
typing `make` runs these four commands, in this order:
```
clang -c -Wall -Werror main.c
clang -c -Wall -Werror moves.c
clang -c -Wall -Werror randi.c
clang main.o moves.o randi.o -o rps
```
- Each `.o` file depends on its `.c` file *and* on the headers (`.h`) it includes.
  Put the headers in a `HEADERS` variable, like in lecture.
- The commands under a rule must start with a real **tab**, not spaces.
- Add a `clean` rule that deletes `rps` and the `.o` files, so `make clean` starts fresh.

When it works, `make` builds `rps`, and `./rps 5 1` stops with a failed `assert`. That's expected:
`moves.c` isn't written yet. Now try:
```bash
make              # run it again right away: what does it say?
touch moves.c     # pretend you edited moves.c
make              # which commands run this time?
```

**Part B: write `moves.c`.** Fill in the four functions; the comment above each one says what it
does. Add `assert()` tests for `winner()` in `run_tests()` in `main.c`. After each edit just type
`make`. Then check your output against the expected files, the way asgn4 section 5.5 does:
```bash
./rps 5 1 > got.txt
diff -us expected_5_1.txt got.txt
./rps 20 784 > got.txt
diff -us expected_20_784.txt got.txt
```

## Level 3 (bonus): Hot potato (`3-bonus-potato/`)
A whole game simulation for if you finish early. The rules are at the top of `potato.c`.
There's no `Makefile`: write one (the program is called `potato`, built from `main.c`,
`potato.c` and `randi.c`). Then write the three functions in `potato.c`, including your own
header comment for `play_potato()` (asgn4 grades these). Compare with the expected files:
```bash
./potato 3 1 > got.txt   && diff -us expected_3_1.txt got.txt
./potato 5 784 > got.txt && diff -us expected_5_784.txt got.txt
./potato 8 42 > got.txt  && diff -us expected_8_42.txt got.txt
```

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created (including your `Makefile`s):
```bash
git checkout -- . && git clean -fdX .
```
