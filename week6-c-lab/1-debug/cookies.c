// Cookie table: a tiny game simulation with 4 bugs.
//
// The rules:
//   - 4 friends sit in a circle: Ana (0), Ben (1), Cal (2), Dee (3). Each starts with 2 cookies.
//   - They take turns in order: Ana, Ben, Cal, Dee, then back to Ana. 16 turns in all.
//   - A friend with no cookies skips their turn (they don't roll).
//   - Otherwise they roll a die (0 to 5) and look the roll up in action_of_roll[]:
//       KEEP        nothing happens
//       GIVE_LEFT   give 1 cookie to the friend on the left  (next higher number; after Dee comes Ana)
//       GIVE_RIGHT  give 1 cookie to the friend on the right (next lower number; before Ana comes Dee)
//       EAT         eat 1 cookie
//
// Should print:
//   Ana: 0   Ben: 4   Cal: 1   Dee: 1   eaten: 2   total: 8
//
// It compiles with clang -Wall -Werror, but it prints the wrong result. There are 4 bugs.
// Things that must always be true while the game runs:
//   - every friend gets 4 turns: Ana on turns 1, 5, 9, 13, Ben on 2, 6, 10, 14, and so on
//   - a friend with 0 cookies doesn't roll, and nobody ever has fewer than 0 cookies
//   - one turn moves at most 1 cookie, and it goes to the neighbor the action names
//
// Debug it with printf():
//   Print the turn number and whose turn it is, then the roll and the action
//   (action_name[action] gives its name), then call print_table() after each turn.
//   Run it and read the trace from the top. On which turn does something above first break?
//   Fix that one bug, run it again, and repeat.
// Run it with   clang -Wall -Werror cookies.c -o cookies && ./cookies
#include <stdio.h>

#define NUM_FRIENDS 4
#define NUM_TURNS   16
#define SEED        7

typedef enum { KEEP, GIVE_LEFT, GIVE_RIGHT, EAT } Action;

const char *friend_name[NUM_FRIENDS] = { "Ana", "Ben", "Cal", "Dee" };
const char *action_name[4] = { "KEEP", "GIVE_LEFT", "GIVE_RIGHT", "EAT" };

const Action action_of_roll[6] = { KEEP, KEEP, GIVE_LEFT, GIVE_LEFT, GIVE_RIGHT, EAT };

int cookies[NUM_FRIENDS];
int eaten = 0;

// Do not modify. The same random numbers as asgn4's randi(): 0 to 999999.
unsigned long current_random = SEED;
int next_random(void) {
    current_random = (9821 * current_random + 211327) % 1000000;
    return (int) current_random;
}

// Do not modify. Prints everyone's cookies, the cookies eaten, and the total.
// You can call it anywhere while debugging.
void print_table(void) {
    int total = eaten;
    for (int i = 0; i < NUM_FRIENDS; i++) {
        printf("%s: %d   ", friend_name[i], cookies[i]);
        total += cookies[i];
    }
    printf("eaten: %d   total: %d\n", eaten, total);
}

void take_turn(int friend) {
    if (cookies[friend] >= 0) {
        int roll = next_random() % 6;
        Action action = action_of_roll[roll];
        switch (action) {
        case KEEP:
            break;
        case GIVE_LEFT:
            cookies[friend]--;
            cookies[(friend + 1) % NUM_FRIENDS]++;
        case GIVE_RIGHT:
            cookies[friend]--;
            cookies[(friend + 1) % NUM_FRIENDS]++;
            break;
        case EAT:
            cookies[friend]--;
            eaten++;
            break;
        }
    }
}

int main(void) {
    for (int i = 0; i < NUM_FRIENDS; i++) {
        cookies[i] = 2;
    }
    int friend = 0;
    for (int turn = 1; turn <= NUM_TURNS; turn++) {
        take_turn(friend);
        friend = (friend + 1) % (NUM_FRIENDS - 1);
    }
    print_table();
    return 0;
}
