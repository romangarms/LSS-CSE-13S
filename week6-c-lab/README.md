# Week 6 C Lab

Practice for asgn5 (Data Compression). Two levels, basics first:
- **Level 1:** write a program that copies a file in ALL CAPS: open two files with `fopen`
  (and check for `NULL`), loop with `fgetc`/`fputc` until `EOF`, then `fclose`.
- **Level 2:** debug an encoder and a decoder with `printf`: `fopen`/`fgetc`/`fputc`/`fclose`,
  `argv` and `strcmp`, a lookup table, and an escape char (like asgn5's 15 nibble).
  Everything they read and write is plain text.

Runs in your Codespace (or any Linux terminal with `clang` and `make`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week6-c-lab
```

## Level 1: Shout (`1-write/`)
`shout` copies a text file in uppercase and prints how many chars and lines it copied, using
the same file calls as asgn5's `read_file_example.c` and `write_file_example.c`. The usage
check is done. You write the three TODO parts of `main()` in `shout.c`: open the files, copy
the chars, and close the files. The rules and the correct result are at the top of the file.
```bash
cd 1-write
clang -Wall -Werror shout.c -o shout
./shout poem.txt -o poem.out && diff -us expected.txt poem.out   # "identical" means it works
./shout nope.txt -o poem.out; echo $?          # should print an error, then 1
```

## Level 2: Debug it (`2-debug/`)
`encode` writes a text file in "number code": common letters become digits (`meet` becomes
`m337`), and a real digit gets a `#` in front (`10` becomes `#1#0`). `decode` turns the code
back into the original text. They work like asgn5's compress and decompress, but the files
are plain text you can read. They compile, but there are **4 bugs**: 2 in `encode.c` and 2 in
`decode.c`. How each program works, the correct result, and what should always be true are at
the top of each file. The `Makefile` is done: look at how `all` makes both programs.
```bash
cd 2-debug
make
./encode note.txt -o note.code && cat note.code
diff -us expected.code note.code             # "identical" means encode works
./decode expected.code -o note.out && diff -us note.txt note.out
./decode cut.code -o cut.out && cat -A cut.out
```
Add `printf()` lines so each program shows what it's doing (each char it reads and what it
writes), find the first value that breaks a rule, fix that bug, run `make` and try again.
Take the prints out when you're done.

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
