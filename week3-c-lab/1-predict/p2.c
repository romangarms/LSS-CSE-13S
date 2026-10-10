#include <stdio.h>

int main(void) {
    if (-1) printf("A ");
    if (0) printf("B ");
    if (3 > 2) printf("C ");
    printf("%d\n", 3 > 2);
    return 0;
}
