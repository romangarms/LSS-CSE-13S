// Goal: print
//   line(3.5) = 8.00
//   line(-2) = -3.00
//
// Fill in line() so it returns y = M * x + B, using the constants below.
// main() is done: it calls line() and prints what it returns.
#include <stdio.h>

double M = 2;    // slope (a constant: line() reads it but never changes it)
double B = 1;    // y-intercept

double line(double x) {
    return 0.0;    // replace this line with your own code
}

int main(void) {
    printf("line(3.5) = %.2f\n", line(3.5));
    printf("line(-2) = %.2f\n", line(-2));
    return 0;
}
