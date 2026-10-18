// Should print:  212F is 100C
#include <stdio.h>

int main(void) {
    int fahr = 212;
    int celsius = 5 / 9 * (fahr - 32);
    printf("%dF is %dC\n", fahr, celsius);
    return 0;
}
