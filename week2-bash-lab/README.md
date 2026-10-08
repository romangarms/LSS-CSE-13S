# Week 2 Bash Lab

Hands-on practice for CSE 13S: Linux file commands, bash scripting, exit codes, and asgn1-style testing. Everything runs in your Codespace (or any Linux terminal).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git
cd LSS-CSE-13S/week2-bash-lab
```

There are three levels. Start with level 1, or jump ahead if you're comfortable in the terminal. Level 3 is the closest to asgn1.

## Level 1: Scavenger hunt (`1-hunt/`)
Practice `cd`, `ls -a`, `pwd`, `cp`, `mv`, `chmod`, and `$?`.
```bash
cd 1-hunt
cat start.txt
```
Follow the clues. The prize is a secret word **and** a secret number.

## Level 2: Fix the scripts (`2-fixme/`)
Six short scripts, each with one classic bash bug. The comment at the top of each script says
what it *should* do. Before you edit, **predict** what it will print. Then run it, fix it, and check:
```bash
cd 2-fixme
bash 01_variable.sh      # try each one
bash check.sh            # see which ones you've fixed
```
Goal: `8 / 8 checks passing`.

## Level 3: Test detective (`3-detective/`)
Practice for asgn1. `max A B` should print the larger of two integers and exit with code 0.
On bad input (wrong number of arguments, or something that isn't an integer), it should print
`usage: max A B` to **stderr** and exit with code 1.

`reference/max` is a correct version. `mystery/` holds seven versions, and some of them are buggy.
Your job is to write tests that catch the buggy ones. Don't read the mystery code; find the bugs by testing.
```bash
cd 3-detective
cat tests/test_3_7.sh                       # the example test
cp tests/test_3_7.sh tests/test_9_10.sh     # make your own and edit it
bash run_tests.sh                           # run every test against every version
```
A test that fails the **correct** reference is marked INVALID and doesn't count. That's the
same rule asgn1 uses, so your tests have to be right about correct behavior.

## Start over
From `week2-bash-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fd .
```
