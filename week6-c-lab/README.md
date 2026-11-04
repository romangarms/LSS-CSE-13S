# Week 6 C Lab

Practice for asgn5 (Data Compression). Two levels:
- **Level 1:** debug an encoder and a decoder with `printf`: `fopen`/`fgetc`/`fputc`/`fclose`,
  `argv` and `strcmp`, a lookup table, and an escape char (like asgn5's 15 nibble).
  Everything they read and write is plain text.
- **Level 2:** write a small ADT like asgn5's nibbler: a struct that wraps a `FILE *`,
  `calloc`/`free`, `->`, and a field that remembers what happened on the last call.

Runs in your Codespace (or any Linux terminal with `clang` and `make`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week6-c-lab
```

## Level 1: Debug it (`1-debug/`)
`encode` writes a text file in "number code": common letters become digits (`meet` becomes
`m337`), and a real digit gets a `#` in front (`10` becomes `#1#0`). `decode` turns the code
back into the original text. They work like asgn5's compress and decompress, but the files
are plain text you can read. They compile, but there are **4 bugs**: 2 in `encode.c` and 2 in
`decode.c`. How each program works, the correct result, and what should always be true are at
the top of each file. The `Makefile` is done: look at how `all` makes both programs.
```bash
cd 1-debug
make
./encode note.txt -o note.code && cat note.code
diff -us expected.code note.code             # "identical" means encode works
./decode expected.code -o note.out && diff -us note.txt note.out
./decode cut.code -o cut.out && cat -A cut.out
```
Add `printf()` lines so each program shows what it's doing (each char it reads and what it
writes), find the first value that breaks a rule, fix that bug, run `make` and try again.
Take the prints out when you're done.

## Level 2: Write a line writer (`2-write/`)
`numlines` copies a text file and puts a line number in front of every line. `numlines.c`,
`linewriter.h` and the `Makefile` are done. You write the three functions in `linewriter.c`:
`lw_open()`, `lw_putc()` and `lw_close()`. They work like asgn5's `nib_open()`,
`nib_put_nibble()` and `nib_close()`, but for line numbers. The rules are at the top of the file.
```bash
cd 2-write
make && ./numlines todo.txt -o todo.out
diff -us expected.txt todo.out             # "identical" means it works
./numlines todo.txt -o nofolder/todo.out; echo $?   # should print an error, then 1
```
Until `lw_open()` is written it returns `NULL`, so `numlines` says it can't open the output file.

## Start over
From `week6-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
