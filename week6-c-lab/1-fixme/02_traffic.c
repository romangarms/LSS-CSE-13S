// Should print:
//   RED: stop
//   YELLOW: slow down
//   GREEN: go
#include <stdio.h>

typedef enum { RED, YELLOW, GREEN } Light;

// An enum value is just a number (RED is 0, YELLOW is 1, GREEN is 2),
// so it can be used as an array index.
const char *light_name[3] = { "RED", "YELLOW", "GREEN" };

// Prints what a driver should do at this light.
void print_action(Light light) {
    switch (light) {
    case RED:
        printf("stop\n");
        break;
    case YELLOW:
        printf("slow down\n");
    case GREEN:
        printf("go\n");
        break;
    }
}

// Do not modify this function.
int main(void) {
    for (Light light = RED; light <= GREEN; light++) {
        printf("%s: ", light_name[light]);
        print_action(light);
    }
    return 0;
}
