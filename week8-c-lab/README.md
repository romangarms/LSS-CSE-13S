# Week 8 C Lab

Practice for asgn7 (Surfin' U.S.A.). First, a web page that shows how a graph is stored and how
depth-first search tries every route. Then a maze program: a 2D array with `calloc()` and
`free()`, and a recursive search that marks, explores, and unmarks.

Runs in your Codespace (or any Linux terminal with `clang`).

```bash
git clone https://github.com/romangarms/LSS-CSE-13S.git   # skip if you already cloned it
cd LSS-CSE-13S && git pull
cd week8-c-lab
```

## Warm-up: Alissa's Road Trip (`road-trip/`)
Open it in your browser:
[Alissa's Road Trip](https://htmlpreview.github.io/?https://github.com/romangarms/LSS-CSE-13S/blob/main/week8-c-lab/road-trip/index.html).
Or open it from your Codespace:
```bash
cd road-trip && python3 -m http.server 8000     # then open the forwarded port 8000
```
1. **Load the map:** read the edges of a `.graph` file one line at a time and watch the roads
   and the adjacency matrix fill in.
2. **Road trip:** drive Alissa around yourself. Visit every beach once, get home, use the least gas.
3. **Watch DFS:** step through depth-first search and see it check each town's roads in order,
   back up, and try every route.

## Part 1: Build and free the maze, with your tutor (`maze/`)
`maze.c` stores the maze as `char **cells`: an array of row pointers, and each row is its own
array, just like the adjacency matrix in asgn7's `graph_create()`. Write `maze_create()` and
`maze_free()` together with your tutor.
```bash
cd maze
clang -Wall -Werror maze.c -o maze && ./maze
```
When Part 1 works, the program prints the maze, `0 routes to the exit`, and the `free` lines,
ending with `m is NULL`.

## Part 2: Find every route, on your own (`maze/`)
Write `explore()`. It's the `dfs()` pseudocode from section 5.1 of the asgn7 spec, on a grid:
mark the cell, try up, right, down, and left, then unmark it so other routes can use it.
```bash
clang -Wall -Werror maze.c -o maze && ./maze
./maze > got.txt && diff -us expected.txt got.txt     # "identical" means it works
```

## Stretch (if you finish early)
- Comment out the line in `explore()` that puts the cell back. How many routes does it find
  now, and why?
- Print only the shortest route at the end. Hint: when you find a new best, copy the cells into
  a second `Maze` (asgn7 does the same thing with `path_copy()`). Remember to free it too.

## Start over
From `week8-c-lab/`, this undoes your edits and removes files you created:
```bash
git checkout -- . && git clean -fd .
```
