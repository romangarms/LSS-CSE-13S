# Week 6 C Lab

Practice for asgn5 (Data Compression): reading and writing files in C. Two levels:
- **Level 1:** fix the file calls in a short program: `fopen` modes, `NULL` checks, the
  `fgetc` loop and `EOF`, `fputc`, `fclose`.
- **Level 2:** write those calls yourself in a program that copies a file in ALL CAPS.

Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week6-c-lab
```

## Level 1: Fix the file calls (`1-debug/`)
`redact` copies a text file and turns every digit into `*`. The copying part is one `if` and
is correct. The **4 bugs** are all in the file calls. The correct result is at the top of
`redact.c`. Compare the calls with asgn5's `read_file_example.c` and `write_file_example.c`.
```bash
cd 1-debug
clang -Wall -Werror redact.c -o redact
./redact note.txt -o note.out && cat -A note.out
diff -us expected.txt note.out              # "identical" means it works
./redact nope.txt -o note.out; echo $?      # should print an error, then 1
```

## Level 2: Shout (`2-write/`)
`shout` copies a text file in uppercase and prints how many chars and lines it copied. The
usage check is done. You write the three TODO parts of `main()` in `shout.c`: open the files,
copy the chars, and close the files. The rules and the correct result are at the top of the file.
```bash
cd 2-write
clang -Wall -Werror shout.c -o shout
./shout poem.txt -o poem.out && diff -us expected.txt poem.out   # "identical" means it works
./shout nope.txt -o poem.out; echo $?          # should print an error, then 1
```

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
