#include "yahtzee_functions.h"
#include "yahtzee_functions.c"

int main(void) {
  //Variables initialized; time seeded for rand()
  srand((unsigned int) (time NULL));
  int player_one_uppers[7] = { 0 }, player_one_lowers[8] = { 0 }, check_p1_score_option[14] = { 0 }, p1_score = 0;
  int player_two_uppers[7] = { 0 }, player_two_lowers[8] = { 0 }, check_p2_score_option[14] = { 0 }, p2_score = 0;
  int die_values[6] = { 0 }, num_die_values[7] = { 0 };
  int round_number = 1;
  int test = 0;

  //Main body of the game (plays 13 rounds)
  while (round_number <= 13) {
    printf("ROUND NUMBER %d\n", round_number);

    //For debugging
    printf("P1 CURRENT SCORE: %d\n", sum_array(player_one_uppers, 7) + sum_array(player_one_lowers, 8));

    //Plays round for player 1
    printf("PLAYER 1 TURN\n");
    roll_and_check(die_values);
    get_num_die(die_values, num_die_values);
    score_roll(die_values, num_die_values, player_one_uppers, player_one_lowers, check_p1_score_option);
    //system('cls');

    //Plays round for player 2
    printf("PLAYER 2 TURN\n");

    //For debugging
    printf("P2 CURRENT SCORE: %d\n", sum_array(player_two_uppers, 7) + sum_array(player_two_lowers, 8));

    roll_and_check(die_values);
    get_num_die(die_values, num_die_values);
    score_roll(die_values, num_die_values, player_two_uppers, player_two_lowers, check_p2_score_option);
    //system('cls');

    round_number += 1;
  }

  //Calculates score; determines winner
  compute_score(player_one_uppers, player_one_lowers, &p1_score);
  compute_score(player_two_uppers, player_two_lowers, &p2_score);
  if (p1_score > p2_score) {
    printf("Player 1 wins!!! Congratulations!\n");
    printf("Player 2, suck less next time\n"); }
  else if (p2_score > p1_score) {
      printf("Player 2 wins!!! Congratulations!\n");
      printf("Player 1, suck less next time\n");
    }
  else if (p1_score == p2_score) {
    printf("Holy hell, it's a tie! I guess you better play again!\n"); }
  else {
    printf("Uh oh! You shouldn't be seeing this! Something went wrong...\n"); }


  return 0;
}
