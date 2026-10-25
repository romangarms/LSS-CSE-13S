// Should print:  letters used: dehlorw
//
// seen[] is a set of letters (Lecture 12, "Using an Array as a Set"):
// seen[0] is for 'a', seen[1] is for 'b', ... seen[25] is for 'z'.
#include <stdio.h>

int main(void) {
    const char *phrase = "hello world";
    int seen[26] = { 0 };

    for (int i = 0; phrase[i] != '\0'; i++) {
        char c = phrase[i];
        if (c >= 'a' && c <= 'z') {
            seen[c - 'a'] = 1;
        }
    }

    printf("letters used: ");
    for (int i = 0; i < 26; i++) {
        if (seen[i]) {
            printf("%c", i);
        }
    }
    printf("\n");
    return 0;
}
