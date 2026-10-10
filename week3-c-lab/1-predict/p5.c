#include <stdio.h>

int main(void) {
    for (int i = 10; i > 0; i = i - 3) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
