// Goal: print
//   robot says: hello
//   at (0.0, 0.0)
//   at (3.0, -1.5)
//   at (5.0, -1.5)
//   at (5.0, -1.5)
//   at (0.0, 0.0)
// then print "line 6: invalid command" to stderr and stop with exit code 1.
//
// main() runs a short script of commands. Fill in handle() so it supports:
//   move DX DY   move the robot by DX and DY (both can be decimals)
//   say WORD     make the robot say one word
//   reset        put the robot back at (0, 0)
//   a blank line does nothing
//   anything else is an error: print "line N: invalid command" to stderr, then exit(1)
// move(), say() and reset() are already written. handle() only decides which one to call.
//
// Hints:
//   Lecture 9 and section 5 of the asgn2 spec cover the tools: sscanf, strcmp, fprintf, exit.
//   Check what sscanf returns for "move 1". Is that a valid move?
//   If you know C++: sscanf's & is "address of", not a reference. And sscanf needs a
//   different % code for a double than printf uses. Which one?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double x = 0;
double y = 0;

void move(double dx, double dy)
{
    x = x + dx;
    y = y + dy;
}

void say(char *word)
{
    printf("robot says: %s\n", word);
}

void reset(void)
{
    x = 0;
    y = 0;
}

void handle(char *command, int line_number)
{
    double dx = 0;
    double dy = 0;
    char word[20];

    // your code here
}

int main(void)
{
    char *script[] = {"say hello", "move 3 -1.5", "move 2 0", "", "reset", "move 1"};

    for (int i = 0; i < 6; ++i)
    {
        handle(script[i], i + 1);
        printf("at (%.1f, %.1f)\n", x, y);
    }
    return 0;
}
