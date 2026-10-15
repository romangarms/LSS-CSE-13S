// Should print: PV = 0.00, PMT = 5.00
#include <stdio.h>
#include <string.h>

int main(void) {
    double PV = 0;
    double PMT = 0;
    char name[] = "PMT";

    if (strcmp(name, "PV")) {
        PV = 5;
    } else if (strcmp(name, "PMT")) {
        PMT = 5;
    }
    printf("PV = %.2f, PMT = %.2f\n", PV, PMT);
    return 0;
}
