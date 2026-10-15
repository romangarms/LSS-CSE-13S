// Goal: print   loop: 1092.73   pow: 1092.73
// $1000 earning 3% a year for 3 years is 1000 x 1.03 x 1.03 x 1.03.
// 1. Use a for loop (try ++year) to multiply money by 1.03 three times.
// 2. Compute the same thing with pow(), from <math.h>: 1000 * pow(1.03, 3).
// Compile with -lm:   clang -lm interest.c -o interest
#include <math.h>
#include <stdio.h>

int main(void) {
    double money = 1000;

    // your code here: the for loop

    printf("loop: %.2f   pow: %.2f\n", money, 0.0);    // replace 0.0 with your pow() answer
    return 0;
}
