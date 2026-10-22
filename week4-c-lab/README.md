# Week 4 C Lab

Practice for the CSE 13S quiz on Lecture 10: `assert()`, `argc` and `argv`, chars and strings,
the `is...` functions like `isdigit()`, `strlen()` vs `sizeof`, and `switch`.
Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week4-c-lab
```

## Level 1: Find the error (`1-fixme/`)
Six programs, each with one bug, one for each quiz topic. The comment at the top says what it
*should* print. Compile and run each one, and read every error **and warning**:
```bash
cd 1-fixme
clang 01_letters.c -o 01_letters && ./01_letters
```
Fix the one bug, recompile, and run it again until the output matches the comment.

## Level 2: Write it (`2-write/`)
Three short challenges. The comment at the top of each file shows the goal and which part to fill in.
- `banner.c`: prints a name in a box of stars, like `./banner Sammy`, but only if the name fits
  in a `char name[10]`. Uses both `sizeof` and `strlen`.
- `words.c`: two string functions, `count_digits()` and `shout()`. `main()` tests them with
  `assert()`, so a failed test tells you its line number.
- `calc.c`: a calculator that reads its input from the command line, like `./calc 6 x 7`,
  using `argc`, `argv` and a `switch`.
```bash
cd 2-write
clang banner.c -o banner && ./banner Sammy
echo $?                  # exit code: 1 after an error, 0 otherwise
```

## Start over
From `week4-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
