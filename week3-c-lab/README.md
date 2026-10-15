# Week 3 C Lab

Practice for CSE 13S week 3: compiling and running C, `printf`, variables, `if`, `while`, and `for`,
plus three short asgn2 warm-ups.
Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week3-c-lab
```

## Compile and run
```bash
clang hello.c -o hello    # compile hello.c into a program named hello
./hello                   # run it
```
Recompile after every change, or `./hello` runs the old program.

Dr. Veenstra's advice is to "read with a C compiler": copy `hello.c` (`cp hello.c try.c`) and write
tiny programs to check what you think C does.

## Level 1: Predict the output (`1-predict/`)
Six tiny programs. **Without compiling**, write the line you think each one prints in `predictions.txt`.
Then check yourself:
```bash
cd 1-predict
bash check.sh
```
For any you got wrong, change the program and re-run it until you can explain what happened.

## Level 2: Fix the programs (`2-fixme/`)
Six programs, each with one classic C bug. The comment at the top says what it *should* print.
Compile and run each one, and read every error **and warning**:
```bash
cd 2-fixme
clang 01_semicolon.c -o 01_semicolon && ./01_semicolon
bash check.sh            # see which ones you've fixed
```
Goal: `6 / 6 programs fixed`.

## Level 3: asgn2 warm-ups (`3-asgn2-prep/`)
Three short challenges using pieces of asgn2: a function that returns a double, reading a command
like `set N 12` and calling the right function, and a `for` loop next to `pow`. Each file's comment
shows the goal output; fill in the marked part.
```bash
cd 3-asgn2-prep
clang -lm line.c -o line && ./line
bash check.sh            # checks all three
```
Use `-lm` (the math library) like asgn2 does. Without it, `pow` gives "undefined reference to `pow'".
Goal: `3 / 3 challenges done`.

## Pair activity: Python to C (`4-python-to-c/`)
Five short Python programs, each with an empty `.c` file next to it. Translate each one into C so it
prints exactly the same thing.
1. **Think:** translate a program on your own, without compiling.
2. **Pair:** compare with your partner's. Which differences matter?
3. **Check:** compile and run.
```bash
cd 4-python-to-c
python3 countdown.py     # see what it prints
bash check.sh            # compares each Python program with your C version
```
Goal: `5 / 5 translated`.

## Start over
From `week3-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
