// Should print:
//   player 1 has the most chips (7)
//
// This one doesn't compile yet. Read the error: -Wall caught a real bug.
#include <stdio.h>

// Returns the number of the player with the most chips.
int most_chips(const int chips[], int num_players) {
    int best = 0;
    for (int i = 1; i < num_players; i++) {
        if (chips[i] > chips[i]) {
            best = i;
        }
    }
    return best;
}

// Do not modify this function.
int main(void) {
    int chips[4] = { 3, 7, 2, 5 };
    int p = most_chips(chips, 4);
    printf("player %d has the most chips (%d)\n", p, chips[p]);
    return 0;
}
