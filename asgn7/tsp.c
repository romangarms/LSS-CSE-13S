/*
*
* CSE 13S - Fall 2026 - Assignment 7
*
* tsp.c
*
*/

#include "graph.h"
#include "path.h"
#include "vertices.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *help =
"Usage: tsp [options]\n"
"\n"
"-i infile    Specify the input file path containing the cities and edges\n"
"             of a graph. If not specified, the default input should be\n"
"             set as stdin.\n"
"\n"
"-o outfile   Specify the output file path to print to. If not specified,\n"
"             the default output should be set as stdout.\n"
"\n"
"-d           Specifies the graph to be directed.\n"
"\n"
"-h           Prints out a help message describing the purpose of the\n"
"             graph and the command-line options it accepts, exiting the\n"
"             program afterwards.\n";

/*
*   def dfs(graph G, vertex v, path *current_path, path *shortest_path):
*       mark v as visited
*       put v in the current_path
*
*       if the current_path contains all vertices of G:
*           // Base Case
*           if G contains an edge (v2, START_VERTEX):
*               add START_VERTEX to the current_path
*               if the shortest_path is empty
*                       or the current_path is shorter than it:
*                   copy the current_path to the shortest_path
*               remove START_VERTEX from the current_path
*       else
*           // Recursive Step
*           for every one of v's edges (v, v2):
*               if (v2 is not visited):
*                   dfs(G, v2, current_path, shortest_path)
*
*       remove v from the current_path
*       mark v as unvisited
*/
void dfs(Graph *G, int v, Path *curr, Path *shortest, FILE *outfile) {
    // TODO
}


/*
* Purpose:      Traveling Salesman Problem
*
*               Read an input description of an undirected graph, find its
*               shortest cycle, and print it.
*
*               -h              If present, print a help message and exit.
*               -i filename     If present, read filename instead of stdin.
*               -o filename     If present, write filename instead of stdout.
*               -d              If present, input specifies a directed graph.
*
*               If either of the -i or -o command-line options is repeated,
*               then use the last filename given.
*
* Parameters:   Standard argc, argv.
*
* Returns:      1 on error, 0 otherwise.
*/
int main(int argc, char **argv) {
    return 0;  // TODO
}

