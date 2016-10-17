#include "yahtzee_functions.h"
#include "yahtzee_functions.c"

int main(void) {
  //Variables initialized; time seeded for rand()
  srand((unsigned int) (time NULL));
  int player_one_uppers[7] = { 0 }, player_one_lowers[8] = { 0 }, check_p1_score_option[14] = { 0 }, p1_score = 0;
  int player_two_uppers[7] = { 0 }, player_two_lowers[8] = { 0 }, check_p2_score_option[14] = { 0 }, p2_score = 0;
  int die_values[6] = { 0 }, num_die_values[7] = { 0 };
  int round_number = 1;

  //Main body of the game (plays 13 rounds)
  while (round_number <= 13) {
    printf("Round number %d\n", round_number);


    round_number += 1;
  }

  //Testing functions
  roll_and_check(die_values, num_die_values);

  return 0;
}

/*
NOTES:
-for scoring, print a menu where they enter 1-13, and enter the way they want to score (then switch-case!)
-also, write functions to check for every possible scoring method (if they select something they don't have, they get a zero!)
-store score values (3 of a kind, etc.) in an array, with the index as the die number, and the value as the points
-for debugging, consider printing "stats" before every roll (current score, etc.)
*/
