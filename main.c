#include "yahtzee_functions.h"
#include "yahtzee_functions.c"

int main(void) {
  srand((unsigned int) (time NULL));
  int test_array[6] = { 0 };
  roll_die(test_array);
  printf("You rolled:\n");
  //Printing (debugging)
  for (int i=0; i<6; i++) {
    printf("%d\n", test_array[i]);
  }

  return 0;
}

/*
NOTES:
-for scoring, print a menu where they enter 1-13, and enter the way they want to score (then switch-case!)
-also, write functions to check for every possible scoring method (if they select something they don't have, they get a zero!)
-store score values (3 of a kind, etc.) in an array, with the index as the die number, and the value as the points
-for debugging, consider printing "stats" before every roll (current score, etc.)
*/
