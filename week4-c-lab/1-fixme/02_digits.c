// Should print:  abc123 has 3 digits
#include <ctype.h>
#include <stdio.h>

int main(void) {
    char s[] = "abc123";
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 0 && s[i] <= 9) {
            count++;
        }
    }
    printf("%s has %d digits\n", s, count);
    return 0;
}
