// Goal: print
//   N = 0, I = 0.00
//   N = 12, I = 0.03
//   N = 0, I = 0.00
//   unknown command: jump
//
// set_variable() and clear() are already written, and they change the global
// variables N and I. Fill in handle() so it reads the command string and calls
// the right one, like asgn2's tvm_process_command():
//   a set command, like "set N 12": set that variable to that number
//   "clear": clear both variables
//   anything else: print "unknown command: " and the command
//
// Hints:
//   Lecture 9 has both tools you need: sscanf() and strcmp(). Section 5 of
//   the asgn2 spec suggests which one to try first.
//   sscanf() returns how many % fields it matched. How many fields does a
//   set command have?
//   sscanf() stores into variables. Lecture 9 says which kinds need a & in
//   front and which don't.
//   strcmp() returns 0 when the two strings are the same.
//   name and value are already declared for you to use.
#include <stdio.h>
#include <string.h>

double N = 0; // number of periods
double I = 0; // interest rate

void set_variable(char *name, double value)
{
    if (strcmp(name, "N") == 0)
    {
        N = value;
    }
    else if (strcmp(name, "I") == 0)
    {
        I = value;
    }
    else
    {
        printf("invalid variable name: %s\n", name);
    }
}

void clear(void)
{
    N = 0;
    I = 0;
}

void handle(char *command)
{
    char name[10];
    double value = 0;

    // your code here
}

int main(void)
{
    // initial print
    printf("N = %.0f, I = %.2f\n", N, I);

    // command 1
    handle("set N 12");
    handle("set I 0.03");
    printf("N = %.0f, I = %.2f\n", N, I);

    // command 2
    handle("clear");
    printf("N = %.0f, I = %.2f\n", N, I);

    // try invalid command
    handle("jump");
    return 0;
}
