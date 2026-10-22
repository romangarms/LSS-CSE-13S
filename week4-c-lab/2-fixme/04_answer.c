// Should print:  you said yes
#include <stdio.h>

int main(void) {
    char answer = 'y';
    if (answer == "y") {
        printf("you said yes\n");
    } else {
        printf("you said no\n");
    }
    return 0;
}
