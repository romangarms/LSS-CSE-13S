#include <stdio.h>

int main(void) {
    char grade = 'B';
    switch (grade) {
    case 'A':
        printf("great ");
    case 'B':
        printf("good ");
    case 'C':
        printf("okay ");
        break;
    default:
        printf("hmm ");
    }
    printf("done\n");
    return 0;
}
