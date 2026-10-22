// A tiny calculator that reads its numbers and operator from the command line.
//
// Goal:
//   ./calc 3 + 4      prints   3.00 + 4.00 = 7.00
//   ./calc 10 / 4     prints   10.00 / 4.00 = 2.50
//   ./calc 6 x 7      prints   6.00 x 7.00 = 42.00
//   ./calc 6 ^ 7      prints   unknown operator: ^            to stderr, exit code 1
//   ./calc 3 +        prints   usage: ./calc NUMBER OP NUMBER  to stderr, exit code 1
// Check an exit code with   echo $?   right after running it.
//
// Part 1: fill in calculate() with a switch on op. It handles + - x and /.
//         For any other op, print the "unknown operator" message and exit(1).
// Part 2: in main(), fill in the argc check before anything uses argv.
//
// Hints:
//   How many things are in argv for  ./calc 3 + 4 ? Does that count include ./calc?
//   op is one char. In a case label, is a char written with ' or with "?
//   Lecture 10 shows what happens in a switch when a case has no break.
//   Why x and not * for multiply? Try   echo *   in this folder and see what the shell does with it.
#include <stdio.h>
#include <stdlib.h>

double calculate(double a, char op, double b) {
    // Part 1: your code here
    return 0;
}

int main(int argc, char *argv[]) {
    // Part 2: your code here

    // Do not modify the rest of main.
    double a = 0;
    double b = 0;
    if (sscanf(argv[1], "%lf", &a) != 1 || sscanf(argv[3], "%lf", &b) != 1) {
        fprintf(stderr, "not a number\n");
        exit(1);
    }
    char op = argv[2][0];
    printf("%.2f %c %.2f = %.2f\n", a, op, b, calculate(a, op, b));
    return 0;
}
