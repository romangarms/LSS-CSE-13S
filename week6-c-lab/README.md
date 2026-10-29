# Week 6 C Lab

Practice for asgn4 (Left, Center, Right): debugging a game simulation with `printf`, and building
a program from several `.c` files with a `Makefile`.
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

## Level 2: Write a Makefile (`2-make/`)
`2-make/` holds a finished rock-paper-scissors program split across three `.c` files, like asgn4:
`main.c`, `moves.c` and `randi.c` (the same random number generator as asgn4), plus three headers.
All the C is done. Your job is to write the `Makefile` from scratch.

Create a file named `Makefile` (capital M) in `2-make/` so that typing `make` runs these four
commands, in this order:
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

When it builds, check that the program works the way asgn4 section 5.5 does:
```bash
./rps 5 1 > got.txt
diff -us expected_5_1.txt got.txt
```
Then see what make does when nothing changed, and when one file changed:
```bash
make              # run it again right away: what does it say?
touch moves.c     # pretend you edited moves.c
make              # which commands run this time?
make clean        # are the .o files and rps gone?
```

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created (including your `Makefile`s):
```bash
git checkout -- . && git clean -fdX .
```
