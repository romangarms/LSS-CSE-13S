// Goal: print
//   setting N to 12.00
//   clearing everything
//   unknown command: jump
//
// set_variable() and clear() are already written. Fill in handle() so it reads
// the command string and calls the right one, like asgn2's tvm_process_command():
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

void set_variable(char *name, double value) {
    printf("setting %s to %.2f\n", name, value);
}

void clear(void) {
    printf("clearing everything\n");
}

void handle(char *command) {
    char name[10];
    double value = 0;

    // your code here
}

int main(void) {
    handle("set N 12");
    handle("clear");
    handle("jump");
    return 0;
}
