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

//Function that calculates the sum of an array
int sum_array(int array[], int size) {
  int sum = 0;
  for (int i=0; i<size; i++) {
    sum += array[i];
  }
  return sum;
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

    case 1: printf("Which one do you want to keep? (1-5, left to right): ");     //Add while loops to make the user enter valid numbers
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

//Function that prompts the user for their preffered scoring method
void prompt_score_type(int *score_method, int check_score_option[]) {
  //Variable initialized; score menu printed
  int method = 0;
  printf("Enter your desired scoring method:\n");
  printf("1: Sum of ones   2: Sum of twos\n");
  printf("3: Sum of threes 4: Sum of fours\n");
  printf("5: Sum of fives  6: Sum of sixes\n");
  printf("7: 3 of a kind   8: 4 of a kind\n");
  printf("9: Full house   10: Small straight\n");
  printf("11: Big straight 12: Yahtzee\n");
  printf("13: Chance\n");

  //Prompts user for score method; Ensures valid range/hasn't already been chosen
  while ((method < 1 || method > 13) || check_score_option[method] == 1) {
    printf("Enter your scoring choice: ");
    scanf("%d", &method);
  }
  //Updates used scoring method; "Returns" score method choice
  check_score_option[method] = 1;
  *score_method = method;

}

//////////////////////////LOWER SCORE FUNCTIONS////////////////////////////////

//Function that scores a three of a kind
void three_of_a_kind(int die_values[], int num_die_values[], int lowers[]) {
  int is_three = 0;
  for (int i=NUM_DIE_VALUES_SIZE-1; i>0; i--) {
          if (num_die_values[i] == 3) {
            printf("Three of a kind!\n"); //For debugging
            is_three += 1;
            break; }
    }
  if (is_three >= 1) {
    lowers[1] = sum_array(die_values, DIE_VALUES_SIZE);
  }
  else {
    lowers[1] = 0;
  }
}

//Function that scores a four of a kind
void four_of_a_kind(int die_values[], int num_die_values[], int lowers[]) {
  int is_four = 0;
  for (int i=NUM_DIE_VALUES_SIZE-1; i>0; i--) {
          if (num_die_values[i] == 4) {
            printf("Four of a kind!\n"); //For debugging
            is_four += 1;
            break; }
    }
  if (is_four >= 1) {
    lowers[2] = sum_array(die_values, DIE_VALUES_SIZE);
  }
  else {
    lowers[2] = 0;
  }
}

//Function that scores a full house (3 of a kind and a pair)
void full_house(int num_die_values[], int lowers[]) {
  int is_full_three = 0, is_full_pair = 0;
  for (int i=1; i<NUM_DIE_VALUES_SIZE; i++) {
    if (num_die_values[i] == 3) {
      is_full_three += 1; }
    else if (num_die_values[i] == 2) {
      is_full_pair += 1; }
  }
  if (is_full_three == 1 && is_full_pair == 1) {
    printf("Full house!\n");
    lowers[3] = 25; }
  else {
    lowers[3] = 0; }
}

//Function that scores a small straight (4 in a row)
void small_straight(int num_die_values[], int lowers[]) {
  int counter = 0;
  for (int i=1; i<NUM_DIE_VALUES_SIZE; i++) {
    if (counter == 4) {
      break; }
    if (num_die_values[i] == 1) {
      counter += 1; }
    else if (num_die_values[i] == 0) {
      counter = 0; }
  }
  if (counter == 4) {
    printf("Small straight!\n");
    lowers[4] = 30; }
  else {
    lowers[4] = 0; }
}

//Function that scores a large straight (5 in a row)
void large_straight(int num_die_values[], int lowers[]) {
  int counter = 0;
  for (int i=1; i<NUM_DIE_VALUES_SIZE; i++) {
    if (counter == 5) {
      break; }
    if (num_die_values[i] == 1) {
      counter += 1; }
    else if (num_die_values[i] == 0) {
      counter = 0; }
  }
  if (counter == 5) {
    printf("Large straight!\n");
    lowers[5] = 40; }
  else {
    lowers[5] = 0; }
}

//Function that scores a yahtzee (5 of a kind)
void score_yahtzee(int num_die_values[], int lowers[]) {
  int is_yahtzee = 0;
  for (int i=NUM_DIE_VALUES_SIZE-1; i>0; i--) {
          if (num_die_values[i] == 5) {
            printf("Yahtzee!\n"); //For debugging
            is_yahtzee += 1;
            break; }
    }
  if (is_yahtzee >= 1) {
    lowers[6] = 50; }
  else {
    lowers[6] = 0; }
}

///////////////////////////////////////////////////////////////////////////////

//Function that scores the roll, based on user's choice
void score_roll(int die_values[], int num_die_values[], int uppers[], int lowers[], int check_score_option[]) {
  //Variables initialized; user prompted for score method
  int score_method = 0;
  prompt_score_type(&score_method, check_score_option);
  printf("SCORE METHOD: %d\n", score_method); //For debugging

  //Roll scored
  switch (score_method) {
    case 1: uppers[1] = num_die_values[1];
            check_score_option[1] = 1;
            printf("Score of ones: %d\n", uppers[1]);
            break;

    case 2: uppers[2] = num_die_values[2] * 2;
            check_score_option[2] = 1;
            printf("Score of twos: %d\n", uppers[2]);
            break;

    case 3: uppers[3] = num_die_values[3] * 3;
            check_score_option[3] = 1;
            printf("Score of threes: %d\n", uppers[3]);
            break;

    case 4: uppers[4] = num_die_values[4] * 4;
            check_score_option[4] = 1;
            printf("Score of fours: %d\n", uppers[4]);
            break;

    case 5: uppers[5] = num_die_values[5] * 5;
            check_score_option[5] = 1;
            printf("Score of fives: %d\n", uppers[5]);
            break;

    case 6: uppers[6] = num_die_values[6] * 6;
            check_score_option[6] = 1;
            printf("Score of sixes: %d\n", uppers[6]);
            break;

    //LOWERS START HERE
    case 7: three_of_a_kind(die_values, num_die_values, lowers);
            check_score_option[7] = 1;
            printf("Score of three-of-a-kind: %d\n", lowers[1]);
            break;

    case 8: four_of_a_kind(die_values, num_die_values, lowers);
            check_score_option[8] = 1;
            printf("Score of four-of-a-kind: %d\n", lowers[2]);
            break;

    case 9: full_house(num_die_values, lowers);
            check_score_option[9] = 1;
            printf("Score of full house: %d\n", lowers[3]);
            break;

    case 10: small_straight(num_die_values, lowers);
             check_score_option[10] = 1;
             printf("Score of small straight: %d\n", lowers[4]);
             break;

    case 11: large_straight(num_die_values, lowers);
             check_score_option[11] = 1;
             printf("Score of large straight: %d\n", lowers[5]);
             break;

    case 12: score_yahtzee(num_die_values, lowers);
             check_score_option[12] = 1;
             printf("Score of a Yahtzee: %d\n", lowers[6]);
             break;

    case 13: lowers[7] = sum_array(die_values, DIE_VALUES_SIZE);
             check_score_option[13] = 1;
             printf("Score of chance: %d\n", lowers[7]);
             break;
        }

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
