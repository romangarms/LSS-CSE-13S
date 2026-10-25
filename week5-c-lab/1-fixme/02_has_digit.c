// Should print:
//   abc: no
//   4ever: yes
//   r2d2: yes
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Returns true if any char in s is a digit, '0' through '9'.
bool has_digit(const char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int main(void) {
    const char *tests[] = { "abc", "4ever", "r2d2" };
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", tests[i], has_digit(tests[i]) ? "yes" : "no");
    }
    return 0;
}
