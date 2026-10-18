// Should print:  3 2 1 liftoff!
#include <stdio.h>

int main(void) {
    int i = 3;
    while (i > 1) {
        printf("%d ", i);
        i = i - 1;
    }
    printf("liftoff!\n");
    return 0;
}
