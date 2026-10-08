# Week 2 Bash Lab

Hands-on practice for CSE 13S week 2: Linux file commands, bash scripting, and exit codes. Everything runs in your Codespace (or any Linux terminal).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git
cd LSS-CSE-13S/week2-bash-lab
```

There are two levels. Start with level 1, or jump to level 2 if you're comfortable in the terminal.

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
Goal: `6 / 6 scripts fixed`.

## Start over
From `week2-bash-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fd .
```
