/*
* File:     potato.c
* Purpose:  Hot potato! Write the three functions at the bottom of this file.
*
* The rules:
*   - Each player starts with 2 lives. Player 0 holds the potato first.
*   - On each turn, the player holding the potato rolls a die (0 to 5) and
*     looks up the roll in action_of_roll[] below:
*       PASS_LEFT   pass the potato to the next player who is still in the game,
*                   going up in player number (after the last player comes player 0)
*       PASS_RIGHT  pass it to the next player still in the game, going down in
*                   player number (before player 0 comes the last player)
*       HOLD        keep it. The same player rolls again on the next turn.
*       BOOM        the holder loses a life. A player with 0 lives is out.
*                   Then the holder passes the potato LEFT, as above.
*   - Players who are out are skipped when the potato is passed.
*   - The game ends as soon as only one player is still in. That player wins.
*
* Print each turn with the strings in potato_strings.h. Your output has to match
* the expected_*.txt files exactly (check with diff -us, like asgn4 section 5.5).
*/

#include "potato.h"
#include "potato_strings.h"
#include "randi.h"

#include <stdio.h>

// Do not modify.
const char *player_name[] = {
    "Dennis Ritchie",
    "Barbara Liskov",
    "Ken Thompson",
    "Frances Allen",
    "Brian Kernighan",
    "Shafi Goldwasser",
    "Donald Knuth",
    "Fei-Fei Li",
};

// Do not modify. Convert a roll (0 to 5) into an Action with action_of_roll[roll].
const Action action_of_roll[6] = {
    PASS_LEFT,
    PASS_LEFT,
    PASS_RIGHT,
    PASS_RIGHT,
    HOLD,
    BOOM,
};

// lives[i] is how many lives player i has left.
int lives[MAX_PLAYERS];

/*
* Purpose:      Find the next player who is still in the game, starting from
*               "player" and moving one seat at a time in the direction "step".
*
* Parameters:   player      - the player to start from, 0 to num_players - 1
*               step        - +1 to go left (up), -1 to go right (down)
*               num_players - the number of players in this game
*
* Returns:      a player number from 0 to num_players - 1 whose lives are above 0
*/
int next_in_game(int player, int step, int num_players) {
    return 0; // Replace this line with your code.
}

/*
* Purpose:      Count how many players are still in the game.
*
* Parameter:    num_players - the number of players in this game
*
* Returns:      how many of players 0 to num_players - 1 have lives above 0
*/
int players_left(int num_players) {
    return 0; // Replace this line with your code.
}

// Replace this comment with your own header comment: Purpose, Parameters, Returns.
void play_potato(unsigned seed, int num_players) {
    // Replace this comment with your code. Before you write it, add comments
    // that list the steps of your plan.
}
