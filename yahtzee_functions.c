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

void roll_die(int die_values[]) {
  for (int i=0; i<6; i++) {
    die_values[i] = rand() % 6 + 1;
  }
  sort_array(die_values, 6);
}
