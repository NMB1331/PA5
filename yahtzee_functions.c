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

//Function that prints the die values to the console
void print_die(int die_values[], int counter) {
  printf("Die values of roll %d: ", counter);
  for (int i=1; i<DIE_VALUES_SIZE; i++) {
    printf("%d ", die_values[i]);
  }
  printf("\n");
}

//Function that stores the number of every die value in an array (used for scoring)
void get_num_die(int die_values[], int num_die_values[]) {
  for (int i=1; i<6; i++) {
    int x = die_values[i];
    num_die_values[x] += 1;
  }
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
  //Sets p1/p2 score equal to calculated total         //Add 35 point bonus!
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

//Function that does the rolling for a round (rolls, prompts to save/roll again)
void roll_and_check(int die_values[]) {
  //Variables initialized
  int i1 = 0, i2 = 0, i3 = 0, i4= 0, i5 = 0, how_many = 0, counter = 1;
  char wanna_roll_again = '\0';

  //Die rolled and printed (first roll); User prompted to roll again
  roll_die(die_values);
  print_die(die_values, counter);
  prompt_roll_again(&wanna_roll_again);
  counter += 1;

  //Second and third roll (if necessary)
  do {
    if (wanna_roll_again == '\0') {
      break; }
  //Prompts for how many die should be kept
  do {
  printf("How many do you want to keep? ");
  scanf("%d", &how_many);
  } while (how_many < 1 || how_many > 5);

  //Prompts for which ones should be kept; re-rolls the others
  switch (how_many) {
    case 0: roll_die(die_values);
            break;

    case 1: printf("Which one do you want to keep? (1-5, left to right): ");
            scanf("%d", &i1);
            for (int i=1; i<6; i++) {
              if (i == i1) {
                continue; }
              else {
                die_values[i] = rand() % 6 + 1; }
            }
            break;

    case 2: printf("Which ones do you want to keep? (1-5, left to right): ");
            scanf("%d%d", &i1, &i2);
            for (int i=1; i<6; i++) {
              if (i == i1 || i == i2) {
                continue; }
              else {
                die_values[i] = rand() % 6 + 1; }
            }
            break;

    case 3: printf("Which ones do you want to keep? (1-5, left to right): ");
            scanf("%d%d%d", &i1, &i2, &i3);
            for (int i=1; i<6; i++) {
              if (i == i1 || i == i2 || i == i3) {
                continue; }
              else {
                die_values[i] = rand() % 6 + 1; }
            }
            break;

    case 4: printf("Which ones do you want to keep? (1-5, left to right): ");
            scanf("%d%d%d%d", &i1, &i2, &i3, &i4);
            for (int i=1; i<6; i++) {
              if (i == i1 || i == i2 || i == i3 || i == i4) {
                continue; }
              else {
                die_values[i] = rand() % 6 + 1; }
            }
            break;

    case 5: break;

  }
  //Prints the die, prompts for a 3rd roll
  print_die(die_values, counter);
  if (counter < 3) {
  prompt_roll_again(&wanna_roll_again); }
  counter += 1;
} while (wanna_roll_again == 'Y' && counter <= 3);

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
