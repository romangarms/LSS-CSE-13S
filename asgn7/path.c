/*
*
* CSE 13S - Fall 2026 - Assignment 7
*
* path.c
*
*/

#include "path.h"

#include <assert.h>
#include <stdlib.h>

typedef struct path {
    int total_weight;
    Stack *vertices;
} Path;

Path *path_create(int capacity) {
    return NULL; // TODO
}

void path_free(Path **pp) {
    // TODO
}

int path_num_vertices(const Path *p) {
    return 0; // TODO
}

int path_distance(const Path *p) {
    return 0; // TODO
}

/*
* Purpose:      Add an item to the path.
*
*                   Path Before:    [0] --> [3] --> [5]
*
*                   Call:           path_add(p, 7, G);
*
*                   Path After:     [0] --> [3] --> [5] --> [7]
*
*               Uses graph G to get the weight from node [5] to node [7].
*
*               Also update the total_weight (total distance) of the path,
*               based on the weight from the current last item of the path
*               and the item that we are adding.
*
* Parameters:   The path, item to add, and the graph (for the edge weights).
*
* Returns:      Nothing.
*/
void path_add(Path *p, int v, const Graph *G) {
    // TODO
}

/*
* Purpose:      Remove the last item of the path.
*
*                   Path Before:    [0] --> [3] --> [5] --> [7]
*
*                   Call:           path_remove(p, G);
*
*                   Path After:     [0] --> [3] --> [5]
*
*                   Returns:        7
*
*               Uses graph G to get the weight from node [5] to node [7].
*
*               Also update the total_weight (total distance) of the path,
*               based on the weight from the current last item of the path
*               and the item that we are adding.
*
* Parameters:   The path and the graph (for the edge weights).
*
* Returns:      The item that was removed.
*/
int path_remove(Path *p, const Graph *G) {
    return 0; // TODO
}

bool path_peek(const Path *p, int *val) {
    return false; // TODO
}

void path_copy(Path *dst, const Path *src) {
    // TODO
}

/*
* Purpose:      Print the current path.
* Parameters:   Path, file to print to, and the graph (for the city names).
* Returns:      Nothing.
*/
void path_print(const Path *p, FILE *f, const Graph *g) {
    // TODO
}

