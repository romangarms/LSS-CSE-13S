// Run this one with arguments:   ./p5 cat "big dog" 42
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("%d %s %s %c\n", argc, argv[0], argv[2], argv[1][0]);
    return 0;
}
