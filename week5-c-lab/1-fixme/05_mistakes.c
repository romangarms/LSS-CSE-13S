// Should print:  3 wrong guesses
//
// This one may already print the right thing with plain  clang 05_mistakes.c
// Compile it the asgn3 way instead, and fix what the compiler says:
//   clang -Wall -Werror 05_mistakes.c -o 05_mistakes
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const char *word = "cat";
    const char *guesses = "xcayz";
    int wrong;

    for (int i = 0; guesses[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; word[j] != '\0'; j++) {
            if (word[j] == guesses[i]) {
                found = true;
            }
        }
        if (!found) {
            wrong++;
        }
    }
    printf("%d wrong guesses\n", wrong);
    return 0;
}
