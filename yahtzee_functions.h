#ifndef YAHTZEE_H
#define YAHTZEE_H
#define UPPER_SCORE_SIZE 7
#define LOWER_SCORE_SIZE 8
#define DIE_VALUES_SIZE 6
#define NUM_DIE_VALUES_SIZE 7

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*************************************************************
* Function: sort_array                                      *
* Date Created: 10/13/2016                                  *
* Date Last Modified: 10/13/2016                            *
* Description: Sorts integers in an array in ascending order*
* Input parameters: int array[], int size                   *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
* Attribution: Code from http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
*************************************************************/
void sort_array(int array[], int size);

/*************************************************************
* Function: roll_die                                        *
* Date Created: 10/13/2016                                  *
* Date Last Modified: 10/13/2016                            *
* Description: Generates 6 random integers; stored in array *
* Input parameters: int die_values[] (array size 6)         *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void roll_die(int die_values[]);

/*************************************************************
* Function: print_die                                       *
* Date Created: 10/16/2016                                  *
* Date Last Modified: 10/16/2016                            *
* Description: Prints the die values to the console         *
* Input parameters: int die_values[]                        *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void print_die(int die_values[], int counter);

/*************************************************************
* Function: compute_score                                   *
* Date Created: 10/15/2016                                  *
* Date Last Modified: 10/15/2016                            *
* Description: Computes a players total score               *
* Input: upper score array, lower score array, score pointer*
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void compute_score(int uppers[], int lowers[], int *score_ptr);

/*************************************************************
* Function: prompt_roll_again                               *
* Date Created: 10/16/2016                                  *
* Date Last Modified: 10/16/2016                            *
* Description: Asks if the player wants to roll again       *
* Input: Pointer to character                               *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void prompt_roll_again(char *go_again_ptr);

/*************************************************************
* Function: prompt_roll_again                               *
* Date Created: 10/16/2016                                  *
* Date Last Modified: 10/16/2016                            *
* Description: Asks if the player wants to roll again       *
* Input: Pointer to character                               *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void roll_and_check(int die_values[]);

#endif YAHTZEE_H
