// Goal: print
//   3 pizzas, 4 people: 6.00 slices each
//   2 pizzas, 3 people: 5.33 slices each
// then print "people must be a positive integer" to stderr and stop with exit code 1.
//
// share() already does the math. Add checks at the top of share() so that bad input
// stops the program, the way asgn2 reports errors:
//   pizzas must be positive          -> "pizzas must be positive"
//   people must be a positive integer -> "people must be a positive integer"
// Errors go to stderr (not stdout), and the program exits with code 1.
//
// Hints:
//   Section 5 of the asgn2 spec says how ceil() can tell whether a double is a whole number.
//   Try it in bash afterwards:  ./pizza 2> /dev/null   and then   echo $?
//   What's the difference between return and exit() inside share()?
//   Compile with -lm:   clang -lm pizza.c -o pizza
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void share(double pizzas, double people)
{
    // your checks here

    printf("%.0f pizzas, %.0f people: %.2f slices each\n", pizzas, people, pizzas * 8 / people);
}

int main(void)
{
    share(3, 4);
    share(2, 3);
    share(1, 2.5);
    share(5, 2);
    return 0;
}
