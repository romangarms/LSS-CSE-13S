// Robot commander: a tiny version of asgn2's command loop.
//
// main() is already written, just like asgn2's tvm.c: it reads one line at a time
// from the keyboard (or from a file) and hands each line to handle_command().
// Run it and type commands. Press ctrl+D to stop.
//
//   clang robot.c -o robot
//   ./robot                  type commands yourself
//   ./robot < commands.txt   or run the sample file
//
// Commands the robot should understand:
//   move DX DY   move by DX and DY (decimals are fine), then print where it is now
//   say WORD     print   robot says: WORD
//   scan         print   robot is at (X, Y)
//   reset        go back to (0.0, 0.0)
//   (blank line) do nothing
//   anything else: print  line N: invalid command  to stderr and exit with code 1
//
// Part 1: fill in handle_command() so each command calls the right function.
// Part 2: the robot lives on a grid from -10 to 10 in both directions. In move(),
//         if a move would leave the grid, print  line N: robot can't leave the grid
//         to stderr and exit with code 1, without moving.
//
// Example (what you type is after the >, the rest is the robot):
//   > say hi
//   robot says: hi
//   > move 3 -1.5
//   at (3.0, -1.5)
//   > scan
//   robot is at (3.0, -1.5)
//   > fly
//   line 4: invalid command
// (The > is only in this example; the program doesn't print it.)
//
// Hints:
//   Section 5 of the asgn2 spec suggests an order for trying sscanf and strcmp.
//   What does sscanf return for "move 1"? Should that count as a move?
//   If you know C++: & here means "address of", not a reference. And sscanf needs
//   a different % code for a double than printf does. Which one?
//   After an error, check the exit code with   echo $?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double x = 0;
double y = 0;

void move(double dx, double dy, int line_number)
{
    // Part 2: your grid check here

    x = x + dx;
    y = y + dy;
    printf("at (%.1f, %.1f)\n", x, y);
}

void say(char *word)
{
    printf("robot says: %s\n", word);
}

void scan(void)
{
    printf("robot is at (%.1f, %.1f)\n", x, y);
}

void reset(void)
{
    x = 0;
    y = 0;
}

void handle_command(char *command, int line_number)
{
    double dx = 0;
    double dy = 0;
    char word[20];

    // Part 1: your code here
}

// Cuts a line off at its '\n' (copied from asgn2's tvm.c).
void truncate_at_newline(char *s)
{
    int j = 0;
    while (s[j] != '\0' && s[j] != '\n')
    {
        ++j;
    }
    s[j] = '\0';
}

int main(void)
{
    char command[40];
    int line_number = 0;

    while (fgets(command, sizeof(command), stdin) != NULL)
    {
        ++line_number;
        truncate_at_newline(command);
        handle_command(command, line_number);
    }
    return 0;
}
