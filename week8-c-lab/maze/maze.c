// maze: find every route from S to E, and the shortest one, with depth-first search.
// Same ideas as asgn7: a 2D array on the heap, and visit / recurse / unvisit.
//
// Write the 3 functions marked "Write this", in order. Each one has pseudocode inside.
//   Part 1 (with your tutor)  maze_create()  and  maze_free()
//   Part 2 (on your own)      explore()
//
// The correct result is in expected.txt: the maze, all 4 routes (the shortest is 14 steps),
// then the free lines, ending with "m is NULL".
// Until maze_create() works, the program crashes (main uses the Maze it returns).
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
// Returns a new Maze on the heap, holding a copy of layout. (Like asgn7's graph_create().)
Maze *maze_create(const char *layout[], int rows, int cols) {
    // calloc one Maze, and set its rows and cols
    // calloc the array of row pointers: rows of them, each a char *
    // for each row r:
    //     calloc row r: cols + 1 chars (the +1 is room for the '\0', so it prints with %s)
    //     for each column c:
    //         copy layout[r][c] into the cell
    // return the Maze
    return NULL;
}

// Write this (Part 1).
// Frees everything maze_create() allocated, then sets the caller's pointer to NULL.
// Free the inside first: once the Maze is freed, you can't read m->cells anymore.
void maze_free(Maze **mp) {
    // for each row r:
    //     print "free row R", then free that row
    // print "free cells", then free the array of row pointers
    // print "free maze", then free the Maze itself
    // set *mp to NULL
}

// Do not modify this function.
void print_maze(const Maze *m) {
    for (int r = 0; r < m->rows; r++) {
        printf("%s\n", m->cells[r]);
    }
}

// Write this (Part 2).
// Explores from cell (r, c), after taking `steps` steps to get here. (Like asgn7's dfs().)
// The maze has walls all around its edge, so r and c never leave the grid.
void explore(Maze *m, int r, int c, int steps, int *routes, int *best) {
    // here = the char in the cell at row r, column c
    //
    // if here is a wall '#' or already on this route '.':
    //     return                                  (can't go this way)
    //
    // if here is the exit 'E':
    //     add 1 to *routes
    //     print "Route N: S steps" (N = *routes, S = steps), then print_maze(m)
    //     if *best is 0 (first route) or steps < *best:
    //         *best = steps
    //     return
    //
    // mark the cell '.'                           (like graph_visit_vertex())
    // explore up    (r - 1, c)  with steps + 1
    // explore right (r, c + 1)  with steps + 1
    // explore down  (r + 1, c)  with steps + 1
    // explore left  (r, c - 1)  with steps + 1
    // put `here` back in the cell                 (like graph_unvisit_vertex())
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
