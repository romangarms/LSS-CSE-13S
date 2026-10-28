/*
* File:     main.c
* Purpose:  Plays rounds of rock-paper-scissors between two players
*           who pick their moves at random.
*
*           Usage:  ./rps rounds seed
*/

#include "moves.h"
#include "randi.h"
#include "rps_strings.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
* Part B: add more assert() tests here, like asgn4 asks you to.
* Two are written for you. Add tests for winner() too.
*/
void run_tests(void) {
    assert(strcmp(name_of_move(ROCK), "rock") == 0);
    assert(strcmp(name_of_move(SCISSORS), "scissors") == 0);
}

// Do not modify this function.
int main(int argc, char **argv) {
    const char *result_text[3] = { "tie", "player 1 wins", "player 2 wins" };
    int rounds;
    unsigned seed;

    if (argc != 3) {
        printf(USAGE_s, argv[0]);
        return 1;
    }
    if (sscanf(argv[1], "%d", &rounds) < 1 || rounds < 1 || rounds > 100) {
        printf(ERROR_ROUNDS);
        rounds = 5;
    }
    if (sscanf(argv[2], "%u", &seed) < 1 || seed > 999999) {
        printf(ERROR_SEED);
        seed = 13;
    }

    run_tests();

    randi_seed(seed);
    for (int r = 1; r <= rounds; r++) {
        Move a = random_move();
        Move b = random_move();
        int w = winner(a, b);
        wins[w]++;
        printf(ROUND_d_s_s_s, r, name_of_move(a), name_of_move(b), result_text[w]);
    }
    print_tally();
    return 0;
}
