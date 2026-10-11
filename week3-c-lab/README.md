# Week 3 C Lab

Hands-on practice for CSE 13S week 3: compiling and running C, `printf`, variables, `if`, `while`, and `for`.
Everything runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week3-c-lab
```

## Compile and run, the way the course does it
```bash
clang hello.c -o hello    # compile (and link) hello.c into a program named hello
./hello                   # run it
```
If you change the `.c` file, compile again before you run: `./hello` runs the old program until you do.

Dr. Veenstra's advice is to "read with a C compiler": write tiny programs to check what you think C does.
`hello.c` is here for that. Copy it (`cp hello.c try.c`) and experiment.

## Level 1: Predict the output (`1-predict/`)
Six tiny programs. For each one, read the code and write the line you think it prints in
`predictions.txt`. **Don't compile first.** Then check yourself:
```bash
cd 1-predict
bash check.sh
```
For any you got wrong, change the program and re-run it until you can explain what happened.

## Level 2: Fix the programs (`2-fixme/`)
Six short programs, each with one classic C bug. The comment at the top says what it *should* print.
Compile and run each one yourself first, and read every error **and warning** clang prints:
```bash
cd 2-fixme
clang 01_semicolon.c -o 01_semicolon && ./01_semicolon
bash check.sh            # see which ones you've fixed
```
Goal: `6 / 6 programs fixed`.

## Bonus: Write your own (`3-bonus/`)
Write programs from scratch. Each file has an empty `main`; fill it in so it prints its triangle using
`for` loops. Each `printf` may print only one character: `"#"`, `" "`, or `"\n"`.

`left.c`
```
#
##
###
####
#####
```

`right.c`
```
    #
   ##
  ###
 ####
#####
```

`middle.c`
```
    #
   ###
  #####
 #######
#########
```

Check your work (it checks all three):
```bash
cd 3-bonus
bash check.sh
```
Goal: `3 / 3 triangles done`. Hint: a row is some spaces, then some `#`, then `"\n"`. How many of each does row 1 need? Row 5?

## Pair activities (pick any)
These work best with a partner. Each person thinks on their own first, then you compare.

### Python to C (`4-python-to-c/`)
Four short Python programs, each with an empty `.c` file next to it. Translate each one into C so it
prints exactly the same thing.
1. **Think:** pick a program and translate it on your own (no compiling yet).
2. **Pair:** compare your C with your partner's. Where are they different? Which differences matter?
3. **Check:** compile and run.
```bash
cd 4-python-to-c
python3 countdown.py     # see what it prints
bash check.sh            # compares each Python program with your C version
```
Goal: `4 / 4 translated`.

### Stump your partner
Each partner secretly writes a tiny program, `cp hello.c stump.c`, that prints **one line** and is
**10 lines or shorter** inside `main`. Only use what's been covered so far: `int` variables, `printf` with `%d`,
`if`, `while`, `for`, and functions. Give every variable a value before you use it.

Trade programs, read your partner's, and write down what you think it prints. Then compile and run it.
Whoever wrote the program explains why it prints what it does.

## Start over
From `week3-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
