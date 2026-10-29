// A lottery ticket checker. It compiles, but the results are wrong because of 4 bugs.
//
// The rules:
//   - The draw is 6 different numbers from 1 to 49. Each ticket also picks 6 numbers.
//   - A ticket that picks the same number twice is invalid.
//   - A valid ticket wins prize[m], where m is how many of its numbers are in the draw.
//
// The correct result:
//   Draw: 7 13 22 31 40 49
//   Ana: 6 matches, wins $1000000
//   Ben: 3 matches, wins $5
//   Cal: invalid ticket (13 picked twice)
//   Dee: 0 matches, wins $0
//   Eve: 2 matches, wins $0
//   Total paid: $1000005
//
// What should always be true:
//   - After mark_draw(), the winning set holds exactly the 6 drawn numbers.
//   - Checking one ticket never changes the answer for the next ticket.
//
// Hints:
//   Don't stare at the code. Add printf() lines so the program shows what it's doing,
//   and call print_set() to see what a set holds. Find the first line of output that
//   breaks a rule, fix that bug, and run it again.
//   seen[] and winning[] are sets of ints (Lecture 12, "Using an Array as a Set").
//   What index does the number 22 use?
#include <stdbool.h>
#include <stdio.h>

#define MAX_NUMBER 49
#define PICKS      6

// prize[m] is the prize for m matches, from 0 matches up to 6.
const int prize[PICKS + 1] = { 0, 0, 5, 50, 1000, 1000000 };

int seen[MAX_NUMBER + 1];

// Do not modify this function. Prints every number in the set.
void print_set(const char *label, const int set[]) {
    printf("    %s: {", label);
    for (int n = 1; n <= MAX_NUMBER; n++) {
        if (set[n]) {
            printf(" %d", n);
        }
    }
    printf(" }\n");
}

// Puts every drawn number into the winning set.
void mark_draw(const int draw[], int winning[]) {
    for (int i = 0; i < PICKS; i++) {
        winning[i] = 1;
    }
}

// Returns the first number the ticket picks twice, or 0 if every pick is different.
int repeated_pick(const int ticket[]) {
    for (int i = 0; i < PICKS; i++) {
        int n = ticket[i];
        if (seen[n]) {
            return n;
        }
        seen[n] = 1;
    }
    return 0;
}

// Returns how many of the ticket's numbers are in the winning set.
int count_matches(const int ticket[], const int winning[]) {
    int matches = 0;
    for (int i = 0; i < PICKS - 1; i++) {
        if (winning[ticket[i]]) {
            matches++;
        }
    }
    return matches;
}

// Checks one ticket, prints the result, and returns the prize paid.
int check_ticket(const char *name, const int ticket[], const int winning[]) {
    int twice = repeated_pick(ticket);
    if (twice != 0) {
        printf("%s: invalid ticket (%d picked twice)\n", name, twice);
        return 0;
    }
    int matches = count_matches(ticket, winning);
    printf("%s: %d matches, wins $%d\n", name, matches, prize[matches]);
    return prize[matches];
}

// Do not modify this function.
int main(void) {
    const int draw[PICKS] = { 7, 13, 22, 31, 40, 49 };
    const int ana[PICKS] = { 7, 13, 22, 31, 40, 49 };
    const int ben[PICKS] = { 2, 7, 9, 22, 31, 35 };
    const int cal[PICKS] = { 13, 13, 20, 30, 40, 45 };
    const int dee[PICKS] = { 1, 2, 3, 4, 5, 6 };
    const int eve[PICKS] = { 5, 18, 25, 31, 44, 49 };

    int winning[MAX_NUMBER + 1] = { 0 };
    mark_draw(draw, winning);

    printf("Draw:");
    for (int i = 0; i < PICKS; i++) {
        printf(" %d", draw[i]);
    }
    printf("\n");

    int total = 0;
    total += check_ticket("Ana", ana, winning);
    total += check_ticket("Ben", ben, winning);
    total += check_ticket("Cal", cal, winning);
    total += check_ticket("Dee", dee, winning);
    total += check_ticket("Eve", eve, winning);
    printf("Total paid: $%d\n", total);
    return 0;
}
