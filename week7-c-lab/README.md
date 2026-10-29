# Week 7 C Lab

Practice for the next CSE 13S quiz: using an array as a set of ints, `strchr()`, and the three
ways to give a constant value a name. (Sets of chars, `getchar()` and getting at the chars of a
string are in the week 4 and week 5 labs.)
Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week7-c-lab
```

Three short challenges. The comment at the top of each file shows the goal and which part to fill in.
Compile with `-Wall -Werror`, like the assignments.

- `dice.c`: two functions about die rolls, `has_repeat()` and `count_missing()`, each using an
  array as a set of the numbers 1 to 6. `main()` tests them with `assert()`.
- `secret.c`: two string functions, `has_any()` and `censor()`, that use `strchr()` to ask
  "is this char in that string?". Also tested with `assert()`.
- `steps.c`: a working program full of bare numbers. Give them names with `#define`, `const`
  and `enum`, without changing what it prints.

```bash
clang -Wall -Werror dice.c -o dice && ./dice
```

For `steps.c`, save the output before you change anything, then compare after each change:
```bash
clang -Wall -Werror steps.c -o steps && ./steps > before.out
# ...edit steps.c, then:
clang -Wall -Werror steps.c -o steps && ./steps | diff before.out -   # no output means no change
```

## Start over
From `week7-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fdX .
```
