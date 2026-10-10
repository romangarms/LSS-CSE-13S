#include <stdio.h>

int main(void) {
    int x = 3, y = 4;
    x = y;
    y = x;
    printf("%d %d\n", x, y);
    return 0;
}
