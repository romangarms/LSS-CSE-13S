/*
*
* CSE 13S - Fall 2026 - Assignment 7
*
* graph.c
*
*/

#include "graph.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
    int num_vertices;  // The number of vertices in this graph.
    bool is_directed;  // true (1) if this is a directed graph.
    bool *was_visited; // Has vertex v been visited? Use: g->was_visited[v]
    char **names;      // The name of vertex v. Use: g->names[v]
    int **weights;     // The weight of the edge v1-v2. Use: g->weights[v1][v2]
} Graph;

Graph *graph_create(int num_vertices, bool is_directed) {
    Graph *g = calloc(1, sizeof(Graph));
    g->num_vertices = num_vertices;
    g->is_directed = is_directed;

    // use calloc() to initialize everything with zeroes
    g->was_visited = calloc(num_vertices, sizeof(bool));
    g->names = calloc(num_vertices, sizeof(char *));

    // allocate g->weights with a pointer to each row
    g->weights = calloc(num_vertices, sizeof(g->weights[0]));

    // allocate each row in the adjacency matrix
    for (int v = 0; v < num_vertices; ++v) {
        g->weights[v] = calloc(num_vertices, sizeof(g->weights[0][0]));
    }

    return g;
}

void graph_free(Graph **gp) {
    // TODO
}

int graph_num_vertices(const Graph *g) {
    return 0; // TODO
}

void graph_add_vertex(Graph *g, const char *name, int v) {
    assert(0 <= v && v < g->num_vertices);

    // if the vertex already has a name, replace it
    if (g->names[v]) {
        free(g->names[v]);
    }

    g->names[v] = strdup(name);
    
}

const char *graph_get_vertex_name(const Graph *g, int v) {
    return NULL; // TODO
}

char **graph_get_names(const Graph *g) {
    return NULL; // TODO
}

void graph_add_edge(Graph *g, int start, int end, int weight) {
    // TODO
}

int graph_get_weight(const Graph *g, int start, int end) {
    return 0;  // TODO
}

void graph_visit_vertex(Graph *g, int v) {
    // TODO
}

void graph_unvisit_vertex(Graph *g, int v) {
    // TODO
}

bool graph_was_visited(const Graph *g, int v) {
    return false; // TODO
}

void graph_print(const Graph *g) {
    // Optional TODO
}

/*
* Purpose:      Create a new graph, and read an input file in this format:
*               (See Section 2.4 of the assignment PDF for more details.)
*
* 4
* Asgard
* Elysium
* Olympus
* Shangri-La
* 4
* 0 3 5
* 3 2 4
* 2 1 10
* 1 0 2
*
* Parameters:   f:              An open FILE * pointer.
*               is_directed:    true if this is a directed graph.
*
* Returns:      A pointer to the new graph.
*/
Graph *graph_read(FILE *f, bool is_directed) {
    return NULL; // TODO
}


