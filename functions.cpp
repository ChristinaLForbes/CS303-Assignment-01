// Christina Forbes 2/6/2024 Assignment 1

#include "functions.h"

void printMainMenu() {
  cout << endl << endl;
  cout << "MAIN MENU" << endl;
  cout << "F: Find Value in Array" << endl;
  cout << "M: Modify Value in Array" << endl;
  cout << "A: Add Value to End of Array" << endl;
  cout << "R: Remove Value from Array" << endl;
  cout << "Q: Quit" << endl;
  cout << endl << endl;
}

char getMainMenuOption() {
  string input = "";
  char option = '\0';
  
  while (option != 'F' && option != 'M' && option != 'A' && option != 'R' && option != 'Q') {
    cout << "\nEnter menu option: ";
    getline(cin, input);
    option = toupper(input.at(0));
 }
  
 return option;
}

bool isValidInputInt(string input) {
  try {
    // attempts to convert input to int
    int inputInt = stoi(input);
    return true;
  }
  catch (invalid_argument& error) {
    cout << "Invalid input. Please enter an integer." << endl;
    return false;
  }
}

bool isValidInputIndex(string input, IntegerArray arr) {
  try {
    // attempts to convert input to int
    int inputIndex = stoi(input);

    // checks if input is a valid arr index
    if (inputIndex < 0 || inputIndex >= arr.getNumItems()) {
      throw out_of_range("Index is out of range.");
    }

    return true;
  }
  catch (invalid_argument& error) {
    cout << "Invalid index. Please enter an integer (0 to <" << arr.getNumItems() << ")." << endl;
    return false;
  }
  catch (out_of_range& error) {
    cout << "Invalid index. Please enter an integer (0 to <" << arr.getNumItems() << ")." << endl;
    return false;
  }
}

void findArrVal(IntegerArray arr) {
  string input;
  int val;

  // gets and validates user's input for val to find
  bool isInputValid = false;
  while (!isInputValid) {
    cout << "\nEnter integer value: ";
    getline(cin, input);
    isInputValid = isValidInputInt(input);
  }
 
  // converts input to int
  val = stoi(input);

  // attempts to find val in arr
  int valIndex = arr.findVal(val);

  // val was not found in arr
  if (valIndex == -1) {
    cout << "\nThe value " << val << " was not found in the array." << endl;
  }
  // val was found in arr
  else {
    cout << "\nThe value " << val << " was found at index " << valIndex << " in the array." << endl;
  }
 
  return;
}

void modifyArrVal(IntegerArray& arr) {
  string inputIndex;
  string inputNewVal;
  int index;
  int newVal;

  // gets and validates user's input for index of val to modify
  bool isInputIndexValid = false;
  while (!isInputIndexValid) {
    cout << "\nEnter index (0 to <" << arr.getNumItems() << "): ";
    getline(cin, inputIndex);
    isInputIndexValid = isValidInputIndex(inputIndex, arr);
  }
  
  // converts input for index to int
  index = stoi(inputIndex);

  // gets and validates user's input for newVal
  bool isInputNewValValid = false;
  while (!isInputNewValValid) {
    cout << "\nEnter new integer value: ";
    getline(cin, inputNewVal);
    isInputNewValValid = isValidInputInt(inputNewVal);
  }

  // converts input for newVal to int
  newVal = stoi(inputNewVal);

  // changes val at index in arr to newVal
  IntegerArray vals = arr.modifyVal(index, newVal);

  cout << "\nThe value at index " << index << " was changed from " << vals[0] << " to " << vals[1] << "." << endl;

  return;
}

void addArrVal(IntegerArray& arr) {
  string inputNewVal;
  int newVal;

  // gets and validates user's input for newVal
  bool isInputNewValValid = false;
  while (!isInputNewValValid) {
    cout << "\nEnter new integer value: ";
    getline(cin, inputNewVal);
    isInputNewValValid = isValidInputInt(inputNewVal);
  }

  // converts input for newVal to int
  newVal = stoi(inputNewVal);

  // adds newVal to end of arr
  arr.pushBack(newVal);

  cout << "\nThe value " << newVal << " was added to the end of the array." << endl;

  return;
}

void removeArrVal(IntegerArray& arr) {
  string inputIndex;
  int index;

  // gets and validates user's input for index of val to remove
  bool isInputIndexValid = false;
  while (!isInputIndexValid) {
    cout << "\nEnter index (0 to <" << arr.getNumItems() << "): ";
    getline(cin, inputIndex);
    isInputIndexValid = isValidInputIndex(inputIndex, arr);
  }

  // converts input for index to int
  index = stoi(inputIndex);

  // removes value at index from arr
  arr.erase(index);

  cout << "\nThe value at index " << index << " was removed from the array." << endl;

  return;
}