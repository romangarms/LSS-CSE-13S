#include <stdio.h>

int main(void) {
    int i = 0;
    while (i < 3) {
        printf("%d ", i);
        i = i + 1;
    }
    printf("then i is %d\n", i);
    return 0;
}
