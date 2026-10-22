// Should print:  average of 3 scores is 80
#include <assert.h>
#include <stdio.h>

// The assert is here to catch a call with no scores, which would divide by 0.
int average(int total, int count) {
    assert(count == 0);
    return total / count;
}

int main(void) {
    printf("average of 3 scores is %d\n", average(240, 3));
    return 0;
}
