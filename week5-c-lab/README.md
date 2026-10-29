# Week 5 C Lab

Practice for this week's quiz and for asgn4 (Left, Center, Right). Three levels:
- **Level 1:** debug a program with `printf` (arrays as sets of ints, a `const` table).
- **Level 2:** write a sign-up validator (`getchar()`, the chars of a string, `strchr()`,
  a set of chars, and `#define`, `const` and `enum`).
- **Level 3:** write a `Makefile` for a finished program split across several files, like asgn4.

Runs in your Codespace (or any Linux terminal with `clang` and `make`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week5-c-lab
```

Compile everything the asgn way. `-Wall` turns on warnings for common mistakes, and `-Werror`
turns those warnings into errors, so the program won't build until they're fixed.

## Level 1: Debug it (`1-debug/`)
`lotto.c` checks lottery tickets against a draw, using arrays as sets of numbers. It compiles,
but the results are wrong because of **4 bugs**. The rules, the correct result, and what should
always be true are at the top of the file.
```bash
cd 1-debug
clang -Wall -Werror lotto.c -o lotto && ./lotto
```
Add `printf()` lines so the program shows what it's doing, and call `print_set()` to see what a
set holds. Find the first line of output that breaks a rule, fix that bug, and run it again.
Take the prints out when you're done.

## Level 2: Sign up (`2-write/`)
`signup.c` asks for a username and a password, like a real sign-up page, and keeps asking until
both follow the rules. `main()` is done. You write three functions: `read_line()` (reads a line
with `getchar()`), `is_valid_username()` and `check_password()` (length, allowed chars, an
uppercase letter, a digit, a special char from `special[]`, and enough different chars).
The rules are at the top of the file.
```bash
cd 2-write
clang -Wall -Werror signup.c -o signup && ./signup       # type your answers, Ctrl-D quits
./signup < tries.txt | diff expected.txt -               # no output means every answer matches
```

## Level 3: Write a Makefile (`3-make/`)
`3-make/` holds a finished rock-paper-scissors program split across three `.c` files, like asgn4:
`main.c`, `moves.c` and `randi.c` (the same random number generator as asgn4), plus three headers.
All the C is done. Your job is to write the `Makefile` from scratch.

Create a file named `Makefile` (capital M) in `3-make/` so that typing `make` runs these four
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
cd 3-make
make
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
From `week5-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
