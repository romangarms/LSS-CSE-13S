// Should print: N = 12
#include <stdio.h>

double N = 0;    // global: every function can see it

void set_N(double value) {
    double N = value;
}

int main(void) {
    set_N(12);
    printf("N = %.0f\n", N);
    return 0;
}
