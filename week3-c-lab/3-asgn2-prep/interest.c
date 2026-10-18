// Goal: print   loop: 1092.73   pow: 1092.73
// money starts at $1000 and earns 3% interest a year for 3 years.
// 1. Write a for loop that adds one year of interest to money each time.
// 2. Get the same answer in a single expression with pow(), and put it where
//    0.0 is in the printf.
//
// Hints:
//   Growing by 3% is the same as multiplying by what number?
//   pow(x, n) from <math.h> computes x to the power n.
//   Compile with -lm:   clang -lm interest.c -o interest
#include <math.h>
#include <stdio.h>

int main(void)
{
    double money = 1000;

    // your code here: the for loop

    printf("loop: %.2f   pow: %.2f\n", money, 0.0); // replace 0.0 with your pow() answer
    return 0;
}
