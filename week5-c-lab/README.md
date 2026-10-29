# Week 5 C Lab

Practice for asgn3 (Hangman): comparing chars like `'a'` and `'z'`, searching a string,
using an array as a set of letters (`seen[c - 'a']`), reading input with `getchar()` and `EOF`,
checking `argc` and a string's length, and compiling with `-Wall -Werror`.
Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week5-c-lab
```

Compile everything the asgn3 way. `-Wall` turns on warnings for common mistakes, and `-Werror`
turns those warnings into errors, so the program won't build until they're fixed:
```bash
clang -Wall -Werror 01_uppercase.c -o 01_uppercase
```

## Level 1: Find the error (`1-fixme/`)
Five programs, each with one bug. The comment at the top says what it *should* print.
Compile and run each one, and read every error:
```bash
cd 1-fixme
clang -Wall -Werror 01_uppercase.c -o 01_uppercase && ./01_uppercase
```
Fix the one bug, recompile, and run it again until the output matches the comment.
`04_three_letters` asks you to type letters, so run it in the terminal and type them.

## Level 2: Write it (`2-write/`)
Three short challenges. The comment at the top of each file shows the goal and which part to fill in.
- `letters.c`: which letters a phrase uses and which it skips, printed in alphabetical order,
  like `./letters "hello world"`. Uses an array as a set.
- `count.c`: type a line and it sorts each char into a type (lowercase, uppercase, digit,
  space or other) and counts them. Press Ctrl-D to quit.
- `username.c`: checks a username from the command line (length and allowed characters),
  printing error messages that are `#define`d like asgn3's `hangman_strings.h`.
```bash
cd 2-write
clang -Wall -Werror letters.c -o letters && ./letters "hello world"
echo $?                  # exit code: 1 after an error, 0 otherwise
```

## asgn4 prep (Levels 5 and 6)
Practice for asgn4 (Left, Center, Right): debugging a game simulation with `printf`, and building
a program from several `.c` files with a `Makefile`.

### Level 5: Debug it (`5-cookies-debug/`)
`cookies.c` simulates a little game: four friends pass cookies around a table, using a die,
an `enum` of actions and a lookup array, like asgn4. It compiles, but the final result is wrong
because of **4 bugs**. The rules, the correct result, and what should always be true are at the top of the file.
```bash
cd 5-cookies-debug
clang -Wall -Werror cookies.c -o cookies && ./cookies
```
Add `printf()` lines so the program shows what happens on every turn (whose turn, the roll,
the action), and call `print_table()` after each turn. Read the trace from the top, find the first
turn where a rule breaks, fix that bug, and run it again. Take the prints out when you're done.

### Level 6: Write a Makefile (`6-make/`)
`6-make/` holds a finished rock-paper-scissors program split across three `.c` files, like asgn4:
`main.c`, `moves.c` and `randi.c` (the same random number generator as asgn4), plus three headers.
All the C is done. Your job is to write the `Makefile` from scratch.

Create a file named `Makefile` (capital M) in `6-make/` so that typing `make` runs these four
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
cd 6-make
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
