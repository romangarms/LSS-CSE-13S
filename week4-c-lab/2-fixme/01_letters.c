// Should print:  [h][e][l][l][o]
#include <stdio.h>
#include <string.h>

int main(void) {
    char word[20] = "hello";
    for (int i = 0; i < sizeof(word); i++) {
        printf("[%c]", word[i]);
    }
    printf("\n");
    return 0;
}
