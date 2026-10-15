// Should print: PV = 373563.90
// This is equation (2) from asgn2: the loan a $2,300/month payment supports.
//
//                  1 - (1 + I)^-N
//   PV = -PMT  x  ----------------  -  FV x (1 + I)^-N
//                        I
#include <math.h>
#include <stdio.h>

int main(void) {
    double N = 360;
    double I = 0.005208;
    double PMT = -2300;
    double FV = 0;

    double PV = -PMT * 1 - pow(1 + I, -N) / I - FV * pow(1 + I, -N);
    printf("PV = %.2f\n", PV);
    return 0;
}
