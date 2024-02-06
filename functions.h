// Christina Forbes 2/6/2024 Assignment 1

#pragma once
#include <string>
#include "integerArray.h"
using namespace std;

void printMainMenu();
// PRE:   none
// POST:  outputs main menu options

char getMainMenuOption();
// PRE:   none
// POST:  gets and validates user's main menu option
//          if input is valid, returns user's option
//          if input is invalid, prompts user again

bool isValidInputInt(string input);
// PRE:   accepts string input
// POST:  checks if input can be converted to int
//          if so, returns true
//          if not, outputs error message and returns false

bool isValidInputIndex(string input, IntegerArray arr);
// PRE:   accepts string input and IntegerArray arr
// POST:  checks if input is valid index (can be converted to int, is greater or equal to 0, and is less than arr size)
//          if so, returns true
//          if not, outputs error message and returns false

void findArrVal(IntegerArray arr);
// PRE:   accepts IntegerArray arr
// POST:  gets and validates user's input for value to find in arr
//        attempts to find the value in arr
//          if found, outputs message with the value's index in arr
//          if not found, outputs message stating that the value was not found

void modifyArrVal(IntegerArray& arr);
// PRE:   accepts IntegerArray arr passed by reference
// POST:  gets and validates user's input for index of value to modify and the new value
//        changes the value at the index to the new value and outputs a message with the original value and the new value

void addArrVal(IntegerArray& arr);
// PRE:   accepts IntegerArray arr passed by reference
// POST:  gets and validates user's input for value to add to arr
//        adds value to arr and outputs message when done

void removeArrVal(IntegerArray& arr);
// PRE:   accepts Integerarray arr passed by reference
// POST:  gets and validates user's input for index of value to remove from arr
//        removes value from arr and outputs message when done