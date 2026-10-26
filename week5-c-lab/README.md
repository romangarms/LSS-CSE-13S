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

## Start over
From `week5-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
