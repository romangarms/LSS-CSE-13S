// Predict everything this prints, not just the first line.
#include <assert.h>
#include <stdio.h>

int main(void) {
    int x = 3;
    assert(x > 0);
    printf("one\n");
    x = x - 5;
    assert(x > 0);
    printf("two\n");
    return 0;
}
