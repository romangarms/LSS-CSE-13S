/*
* File:     moves.c
* Purpose:  Part B: write the four functions in this file.
*
* Hints:
*   An enum value is a name for a number. Which statement from week 4 picks
*   one case out of several named values?
*   randi() returns 0 to 999999. How many slots does the spinner have, and which
*   operator squeezes a big number into 0 to (slots - 1)?  (asgn4 section 3.2)
*   For winner(), handle the tie first. Then how many ways can player 1 win?
*   print_tally() prints the global wins[]. What's in wins[0], wins[1], wins[2]?
*/

#include "moves.h"
#include "randi.h"
#include "rps_strings.h"

#include <stdio.h>

/*
* Do not modify. The spinner has 5 slots, so it's lopsided on purpose
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
* Do not modify. wins[i] is the count for tally_label[i].
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
    return "?"; // Replace this line with your code.
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
    return ROCK; // Replace this line with your code.
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
    return 0; // Replace this line with your code.
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
    // Replace this comment with your code.
}
