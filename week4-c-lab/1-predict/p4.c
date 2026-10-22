#include <ctype.h>
#include <stdio.h>

int main(void) {
    char s[] = "R2-D2 go!";
    int digits = 0;
    int letters = 0;
    int other = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            digits++;
        } else if (isalpha(s[i])) {
            letters++;
        } else {
            other++;
        }
    }
    printf("%d %d %d %c\n", digits, letters, other, toupper(s[6]));
    return 0;
}
