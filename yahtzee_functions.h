//#ifndef YAHTZEE_H
#define YAHTZEE_H

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

//#endif YAHTZEE_H
