#include <stdio.h>
#include <string.h>

int main(void) {
    char word[10] = "cat";
    char name[] = "Sammy";
    printf("%zu %zu ", sizeof(word), strlen(word));
    printf("%zu %zu\n", sizeof(name), strlen(name));
    return 0;
}
