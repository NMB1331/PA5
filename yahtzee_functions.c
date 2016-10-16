#include "yahtzee_functions.h"

//Function that sorts an array (used to check for straights, multiples, etc.)
void sort_array(int array[], int size) {
  int temp = 0;
  for (int i=0; i<(size-1); i++) {
    for (int j=0; j<(size-i-1); j++) {
      if (array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp; }
    }
  }
}

//Function that rolls 6 die
void roll_die(int die_values[]) {
  for (int i=0; i<6; i++) {
    die_values[i] = rand() % 6 + 1;
  }
  sort_array(die_values, 6);
}

//Function that computes the scores of the 2 player_two_uppers
void compute_score(int uppers[], int lowers[], int *score_ptr) {
  int score = 0;
  //Sums upper score, adds to total
  for (int i=0; i<UPPER_SCORE_SIZE; i++) {
    score += uppers[i];
  }
  //Sums lower score, adds to total
  for (int i=0; i<LOWER_SCORE_SIZE; i++) {
    score += lowers[i];
  }
  //Sets p1/p2 score equal to calculated total
  *score_ptr = score;
}

//Function that asks the user if they want to roll again
void prompt_roll_again(char *go_again_ptr) {
  char wanna_roll = '\0';
  printf("Want to roll again? [Y/N]: ");
  scanf(" %c", &wanna_roll);
  if (wanna_roll == 'y' || wanna_roll == 'Y') {
    *go_again_ptr = 'Y'; }
  else {
    *go_again_ptr = '\0'; }
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
