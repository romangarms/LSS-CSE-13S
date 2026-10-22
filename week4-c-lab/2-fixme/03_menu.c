// Should print:  you picked banana
#include <stdio.h>

int main(void) {
    char choice = 'b';
    switch (choice) {
    case 'a':
        printf("you picked apple\n");
        break;
    case 'b':
        printf("you picked banana\n");
    case 'c':
        printf("you picked cherry\n");
        break;
    default:
        printf("not on the menu\n");
    }
    return 0;
}
