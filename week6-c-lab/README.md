# Week 6 C Lab

Practice for asgn5 (Data Compression): reading and writing files in C. Two levels:
- **Level 1:** fix the file calls in a tiny program: `fopen` modes, the `fgetc` loop and
  `EOF`, `fputc`, `fclose`.
- **Level 2:** write a new program from scratch that reads a file and writes a report, with
  the error handling asgn5 asks for: the `argc`/`argv` check, `NULL` checks, `stderr` and `exit(1)`.

Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week6-c-lab
```

## Level 1: Fix the file calls (`1-debug/`)
`redact` copies `note.txt` to `note.out` and turns every digit into `*`. The copying part is
one `if` and is correct. The **3 bugs** are all in the file calls. The correct result is at
the top of `redact.c`. Compare the calls with asgn5's `read_file_example.c` and
`write_file_example.c`.
```bash
cd 1-debug
clang -Wall -Werror redact.c -o redact
./redact && cat -A note.out
diff -us expected.txt note.out              # "identical" means it works
```

## Level 2: Write a file report (`2-write/`)
`report` reads a text file and writes how many chars, lines and digits it has to another
file. You write all of `main()`, including the error handling: a usage message, a message
when a file can't be opened, and `exit(1)`. Your fixed `redact.c` shows the file calls.
The rules and the correct result are at the top of `report.c`.
```bash
cd 2-write
clang -Wall -Werror report.c -o report
./report shopping.txt -o report.out && diff -us expected.txt report.out
./report shopping.txt report.out; echo $?          # should print the usage message, then 1
./report nope.txt -o report.out; echo $?           # should print an error, then 1
```

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
