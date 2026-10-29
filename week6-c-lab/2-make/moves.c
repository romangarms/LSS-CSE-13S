/*
* File:     moves.c
* Purpose:  The rock-paper-scissors moves: names, random spins, and who wins.
*           This program is already finished. Your job is only the Makefile.
*/

#include "moves.h"
#include "randi.h"
#include "rps_strings.h"

#include <stdio.h>

/*
* The spinner has 5 slots, so it's lopsided on purpose
* (like asgn4's die, which has DOT on three faces). Convert a spin number
* from 0 to 4 into a Move like this:
*
*    Move move = move_of_spin[spin];
*/
const Move move_of_spin[5] = {
    ROCK,
    ROCK,
    ROCK,
    PAPER,
    SCISSORS,
};

/*
* wins[i] is the count for tally_label[i].
*/
int wins[3];
const char *tally_label[3] = { "ties", "player 1", "player 2" };

/*
* Purpose:      Return the name of a move:  ROCK "rock", PAPER "paper",
*               SCISSORS "scissors".
*
* Parameter:    move - ROCK, PAPER, or SCISSORS
*
* Returns:      the move's name as a string
*/
const char *name_of_move(Move move) {
    switch (move) {
    case ROCK: return "rock";
    case PAPER: return "paper";
    case SCISSORS: return "scissors";
    }
    return "?";
}

/*
* Purpose:      Spin the spinner once. Get the next number from randi(),
*               turn it into a spin from 0 to 4, and look up that spin's Move.
*
* Parameter:    none
*
* Returns:      ROCK, PAPER, or SCISSORS
*/
Move random_move(void) {
    int spin = randi() % 5;
    return move_of_spin[spin];
}

/*
* Purpose:      Decide who wins one round. Rock beats scissors, scissors
*               beats paper, and paper beats rock.
*
* Parameters:   a - player 1's move
*               b - player 2's move
*
* Returns:      0 for a tie, 1 if player 1 (a) wins, 2 if player 2 (b) wins
*/
int winner(Move a, Move b) {
    if (a == b) {
        return 0;
    }
    if ((a == ROCK && b == SCISSORS) || (a == SCISSORS && b == PAPER) || (a == PAPER && b == ROCK)) {
        return 1;
    }
    return 2;
}

/*
* Purpose:      Print the final tally like this, using FINAL_TALLY and TALLY_ds
*               from rps_strings.h:

Final tally:
    1 -- ties
    3 -- player 1
    1 -- player 2

* Parameter:    none
*
* Returns:      nothing
*/
void print_tally(void) {
    printf(FINAL_TALLY);
    for (int i = 0; i < 3; i++) {
        printf(TALLY_ds, wins[i], tally_label[i]);
    }
}
