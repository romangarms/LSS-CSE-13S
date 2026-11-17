// maze: find every route from S to E, and the shortest one, with depth-first search.
// Same ideas as asgn7: a 2D array made with calloc(), and visit / recurse / unvisit.
//
// Part 1 (with your tutor)  maze_create() and maze_free()
// Part 2 (on your own)      explore()
//
// The correct result is in expected.txt: the maze, all 4 routes, the shortest (14 steps),
// then the free lines. Until Part 1 works, the program crashes (main uses the Maze).
//
// Hints: maze_create() works like graph_create() in asgn7's graph.c. Free the inside of
// the struct before the struct itself. explore() is the dfs() pseudocode in asgn7
// section 5.1, on a grid: mark, try every direction, unmark.
#include <stdio.h>
#include <stdlib.h>

// Do not modify this type.
typedef struct s_maze Maze;

struct s_maze {
    int rows;       // number of rows
    int cols;       // number of columns
    char **cells;   // cells[r][c] is '#' (wall), ' ' (open), 'S', 'E', or '.' (on the route)
};

// Write this (Part 1).
// Returns a new Maze on the heap. Allocate the array of row pointers, then each row,
// like graph_create(). Make each row cols + 1 chars long so it ends in '\0' and can be
// printed with %s. Copy the characters of layout[r] into row r.
Maze *maze_create(const char *layout[], int rows, int cols) {
    return NULL;
}

// Write this (Part 1).
// Frees everything maze_create() allocated, then sets the caller's pointer to NULL.
// Print a line just before each free():  "free row R"  for each row, then "free cells",
// then "free maze".
void maze_free(Maze **mp) {
}

// Do not modify this function.
void print_maze(const Maze *m) {
    for (int r = 0; r < m->rows; r++) {
        printf("%s\n", m->cells[r]);
    }
}

// Write this (Part 2).
// Explores from cell (r, c), having taken `steps` steps to get here.
//   - A wall '#' or a cell already on this route '.': give up on this cell.
//   - The exit 'E': add 1 to *routes, print "Route N: S steps" and the maze,
//     and update *best if this route is shorter (or it's the first one).
//   - Anything else: mark the cell '.', explore up, right, down, left (in that order),
//     then put back whatever the cell held before.
// The maze has walls all around its edge, so r and c never leave the grid.
void explore(Maze *m, int r, int c, int steps, int *routes, int *best) {
}

// Do not modify main().
int main(void) {
    const char *layout[] = {
        "#########",
        "#S  #   #",
        "# # # # #",
        "#   #   #",
        "## ## # #",
        "#     #E#",
        "#########",
    };
    Maze *m = maze_create(layout, 7, 9);
    printf("The maze:\n");
    print_maze(m);

    int routes = 0;
    int best = 0;
    explore(m, 1, 1, 0, &routes, &best);
    printf("%d routes to the exit. Shortest: %d steps.\n", routes, best);

    maze_free(&m);
    printf("m is %s\n", m == NULL ? "NULL" : "not NULL");
    return 0;
}
