#ifndef YAHTZEE_H
#define YAHTZEE_H
#define NUMBER_OF_DIE 5
#define UPPER_SCORE_SIZE 7
#define LOWER_SCORE_SIZE 8
#define DIE_VALUES_SIZE 6
#define NUM_DIE_VALUES_SIZE 7
#define POSSIBLE_SCORE_METHODS 14 //13 ways to score, 14 for an array to hold the 13

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
* Function: sum_array                                       *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Calculates the sum of an array               *
* Input parameters: int array[], int size                   *
* Returns: Integer sum of array                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
int sum_array(int array[], int size);

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
* Function: get_num_die                                     *
* Date Created: 10/18/2016                                  *
* Date Last Modified: 10/18/2016                            *
* Description: Gets the number of die values                *
* Input: Array die values, array num die values             *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void get_num_die(int die_values[], int num_die_values[]);

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

/*************************************************************
* Function: prompt_score_type                               *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Prompts the player for a scoring method, checks
               if they've used that method before
* Input: Pointer to score_choice, check_score_option[]      *
* Returns: None (modifies integer score_choice)             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void prompt_score_type(int *score_method, int check_score_option[]);

/////////////////////////LOWERS SCORING FUNCTIONS/////////////////

/*************************************************************
* Function: three_of_a_kind                                 *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if three of a kind; updates score     *
* Input: Die values, num die values, lower score array      *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void three_of_a_kind(int die_values[], int num_die_values[], int lowers[]);

/*************************************************************
* Function: four_of_a_kind                                  *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if four of a kind; updates score      *
* Input: Die values, num die values, lower score array      *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void four_of_a_kind(int die_values[], int num_die_values[], int lowers[]);

/*************************************************************
* Function: full_house                                      *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if full house, updates score          *
* Input: Num die values, lower score array                  *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void full_house(int num_die_values[], int lowers[]);

/*************************************************************
* Function: small_straight                                  *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if small straight, updates score      *
* Input: Num die values, lower score array                  *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void small_straight(int num_die_values[], int lowers[]);

/*************************************************************
* Function: large_straight                                  *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if large straight, updates score      *
* Input: Num die values, lower score array                  *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void large_straight(int num_die_values[], int lowers[]);

/*************************************************************
* Function: score_yahtzee                                   *
* Date Created: 10/19/2016                                  *
* Date Last Modified: 10/19/2016                            *
* Description: Checks if yahtzee, updates score             *
* Input: Num die values, lower score array                  *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void score_yahtzee(int num_die_values[], int lowers[]);

//////////////////////////////////////////////////////////////////

/*************************************************************
* Function: score_the_roll                                  *
* Date Created: 10/18/2016                                  *
* Date Last Modified: 10/18/2016                            *
* Description: Scores the die values after rolling          *
* Input: Arrays num_die_values, upper score, lower score    *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void score_the_roll(int die_values[], int num_die_values[], int uppers[], int lowers[], int check_score_option[]);           //Modifies the score check arrays

#endif YAHTZEE_H
