// Should print:  age 19: too young to rent a car
#include <stdio.h>

int main(void) {
    int age = 19;
    printf("age %d: ", age);
    if (age >= 25); {
        printf("can rent a car\n");
        return 0;
    }
    printf("too young to rent a car\n");
    return 0;
}
