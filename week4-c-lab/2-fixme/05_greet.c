// Should print, when run as   ./05_greet Sammy
//   hello, Sammy!
// and when run with no name, as   ./05_greet
//   usage: ./05_greet NAME
// (then stop with exit code 1, so  echo $?  shows 1)
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 1) {
        fprintf(stderr, "usage: %s NAME\n", argv[0]);
        return 1;
    }
    printf("hello, %s!\n", argv[1]);
    return 0;
}
