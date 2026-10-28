// Should print:
//   Votes:
//       3 -- chips
//       1 -- cookies
//       2 -- fruit
#include <stdio.h>

const char *snack_name[3] = { "chips", "cookies", "fruit" };

// votes[i] is how many votes snack i got. It's a global, so every function can use it.
int votes[3];

// Adds up the ballots into votes[]. Each ballot is a snack number from 0 to 2.
void count_votes(const int ballots[], int num_ballots) {
    int votes[3] = { 0 };
    for (int i = 0; i < num_ballots; i++) {
        votes[ballots[i]]++;
    }
}

// Do not modify this function.
void print_votes(void) {
    printf("Votes:\n");
    for (int i = 0; i < 3; i++) {
        printf("    %d -- %s\n", votes[i], snack_name[i]);
    }
}

// Do not modify this function.
int main(void) {
    int ballots[6] = { 0, 2, 1, 0, 0, 2 };
    count_votes(ballots, 6);
    print_votes();
    return 0;
}
