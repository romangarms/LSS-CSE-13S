// Should print:
//   A: yes
//   m: no
//   Z: yes
//   7: no
//   ?: no
#include <stdbool.h>
#include <stdio.h>

// Returns true if c is an uppercase letter, 'A' through 'Z'.
bool is_uppercase_letter(char c) {
    return c >= 'A' || c <= 'Z';
}

int main(void) {
    char tests[] = "AmZ7?";
    for (int i = 0; tests[i] != '\0'; i++) {
        printf("%c: %s\n", tests[i], is_uppercase_letter(tests[i]) ? "yes" : "no");
    }
    return 0;
}
