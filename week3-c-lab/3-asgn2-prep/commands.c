// Goal: print
//   N = 12, I = 0.03
//   N = 0, I = 0.00
//   unknown command: jump
//
// set_variable() and clear() are already written, and they change the global
// variables N and I. Fill in handle() so it reads the command string and calls
// the right one, like asgn2's tvm_process_command():
//   "set N 12"  ->  call set_variable("N", 12)
//   "clear"     ->  call clear()
//   anything else: print "unknown command: " and the command
//
// Hints:
//   sscanf(command, "set %s %lf", name, &value) returns 2 when command looks
//   like "set NAME NUMBER". It stores the name and number in name and value.
//   strcmp(command, "clear") returns 0 when command is exactly "clear".
#include <stdio.h>
#include <string.h>

double N = 0;    // number of periods
double I = 0;    // interest rate

void set_variable(char *name, double value) {
    if (strcmp(name, "N") == 0) {
        N = value;
    } else if (strcmp(name, "I") == 0) {
        I = value;
    } else {
        printf("invalid variable name: %s\n", name);
    }
}

void clear(void) {
    N = 0;
    I = 0;
}

void handle(char *command) {
    char name[10];
    double value = 0;

    // your code here
}

int main(void) {
    handle("set N 12");
    handle("set I 0.03");
    printf("N = %.0f, I = %.2f\n", N, I);

    handle("clear");
    printf("N = %.0f, I = %.2f\n", N, I);

    handle("jump");
    return 0;
}
