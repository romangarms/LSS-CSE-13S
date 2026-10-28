// Should print:
//   north: 2
//   east: 2
//   south: 2
//   west: 2
//
// spins[] holds big random numbers (0 to 999999). Each one should be turned into a
// direction number from 0 to 3, so every direction gets picked sometimes.
#include <stdio.h>

const char *direction_name[4] = { "north", "east", "south", "west" };

// Turns a big random number into a direction from 0 to 3.
int direction_of_spin(int spin) {
    return spin % 3;
}

// Do not modify this function.
int main(void) {
    // The first 8 numbers that asgn4's randi() gives with seed 0.
    int spins[8] = { 211327, 653794, 122201, 347348, 516035, 191062, 631229, 511336 };
    int count[4] = { 0 };
    for (int i = 0; i < 8; i++) {
        count[direction_of_spin(spins[i])]++;
    }
    for (int d = 0; d < 4; d++) {
        printf("%s: %d\n", direction_name[d], count[d]);
    }
    return 0;
}
