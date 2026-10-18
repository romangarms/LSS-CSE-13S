// Goal: print
//   line(3.5) = 8.00
//   line(-2) = -3.00
//
// Fill in line() so it returns the y value of the straight line with slope M
// and y-intercept B (the constants below). main() is done: it calls line()
// and prints what it returns.
//
// Hints:
//   Think back to the slope-intercept form of a line from algebra.
//   x comes in as a parameter. M and B are globals, so line() can use them
//   without them being passed in.
//   Work out line(3.5) by hand first so you know what you're aiming for.
#include <stdio.h>

double M = 2; // slope (a constant: line() reads it but never changes it)
double B = 1; // y-intercept

double line(double x)
{
    return 0.0; // replace this line with your own code
}

// Do not modify this function.
int main(void)
{
    printf("line(3.5) = %.2f\n", line(3.5));
    printf("line(-2) = %.2f\n", line(-2));
    return 0;
}
