# Week 4 C Lab

Practice for the CSE 13S quiz on Lecture 10: `assert()`, `argc` and `argv`, chars and strings,
the `is...` functions like `isdigit()`, `strlen()` vs `sizeof`, and `switch`.
Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week4-c-lab
```

Compile and run the same way as week 3:
```bash
clang p1.c -o p1 && ./p1
```

Levels 1 and 2 each have one program per quiz topic.

## Level 1: Predict the output (`1-predict/`)
Six tiny programs. **Without compiling**, write what you think each one prints in `predictions.txt`.
Then compile and run each one to check yourself. `p5` needs arguments:
```bash
cd 1-predict
clang p5.c -o p5 && ./p5 cat "big dog" 42
```
For any you got wrong, change the program and re-run it until you can explain what happened.

## Level 2: Find the error (`2-fixme/`)
Six programs, each with one bug. The comment at the top says what it *should* print.
Compile and run each one, and read every error **and warning**:
```bash
cd 2-fixme
clang 01_letters.c -o 01_letters && ./01_letters
```
Fix the one bug, recompile, and run it again until the output matches the comment.

## Level 3: Write it (`3-write/`)
Two short challenges. The comment at the top of each file shows the goal and which part to fill in.
- `calc.c`: a calculator that reads its input from the command line, like `./calc 6 x 7`,
  using `argc`, `argv` and a `switch`.
- `words.c`: two string functions, `count_digits()` and `shout()`. `main()` tests them with
  `assert()`, so a failed test tells you its line number.
```bash
cd 3-write
clang calc.c -o calc && ./calc 3 + 4
echo $?                  # exit code: 1 after an error, 0 otherwise
clang words.c -o words && ./words
```

## Start over
From `week4-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
