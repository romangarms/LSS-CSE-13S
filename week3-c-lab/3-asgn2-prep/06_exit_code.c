// Should print "line 3: I must be positive" as an error (to stderr),
// print nothing else, and exit with exit code 1.
#include <stdio.h>
#include <stdlib.h>

void set_I(double value, int line_number) {
    if (value <= 0) {
        fprintf(stderr, "line %d: I must be positive\n", line_number);
        exit(0);
    }
}

int main(void) {
    set_I(-0.03, 3);
    printf("I is set\n");
    return 0;
}
