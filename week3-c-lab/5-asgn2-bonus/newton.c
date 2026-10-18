// Goal: print
//   sqrt(2) = 1.414214
//   sqrt(81) = 9.000000
// then print "did not converge" to stderr and stop with exit code 1 (there's no real sqrt(-4)).
//
// asgn2 computes N and I with Newton's method. This is the same idea on a smaller problem:
// finding x where f(x) = x*x - target is 0, which is the square root of target.
// Each step improves the guess:   next x = x - f(x) / f'(x)
//
// Fill in newton():
//   take at most 100 steps
//   stop early once a step changes x by less than 1e-8
//   if the steps never got that small, print "did not converge" to stderr and exit(1)
//
// Hints:
//   Compare this with the newton_raphson_N pseudocode in section 6.2 of the asgn2 spec.
//   A step can be negative. Which <math.h> function from section 5 helps?
//   You'll need the size of the last step after the loop ends, so where should it be declared?
//   Compile with -lm:   clang -lm newton.c -o newton
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double target;

double f(double x)
{
    return x * x - target;
}

double f_prime(double x)
{
    return 2 * x;
}

double newton(void)
{
    double x = 1; // starting guess

    // your code here

    return x;
}

int main(void)
{
    target = 2;
    printf("sqrt(2) = %.6f\n", newton());
    target = 81;
    printf("sqrt(81) = %.6f\n", newton());
    target = -4;
    printf("sqrt(-4) = %.6f\n", newton());
    return 0;
}
