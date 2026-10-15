// Should print: 2 matched: PV is -10000.00
#include <stdio.h>

int main(void) {
    char name[10];
    double value = 0;

    int matched = sscanf("set PV -10000", "set %s %lf", name, value);
    printf("%d matched: %s is %.2f\n", matched, name, value);
    return 0;
}
