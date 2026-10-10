#include <stdio.h>

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int main(void) {
    int n = 7;
    printf("%d ", min(n, 4));
    printf("%d ", min(min(9, n), 8));
    printf("%d\n", n < 3 || n > 6);
    return 0;
}
