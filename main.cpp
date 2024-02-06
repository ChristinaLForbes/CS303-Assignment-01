// Christina Forbes 2/6/2024 Assignment 1

#include <fstream>
#include "integerArray.h"
#include "functions.h"
using namespace std;

int main() {
  // opens input file
  ifstream inputFile;
  inputFile.open("A1input.txt");

  // creates array of ints
  IntegerArray inputArray;
  
  // reads ints from input file into array
  int temp;
  while (!inputFile.eof()) {
    inputFile >> temp;
    inputArray.pushBack(temp);
  }

  cout << "ONE-DIMENSIONAL ARRAYS" << endl;

  printMainMenu();
  char mainMenuOption = getMainMenuOption();

  while (mainMenuOption != 'Q') {
    if (mainMenuOption == 'F') {
      findArrVal(inputArray);
    }
    else if (mainMenuOption == 'M') {
      modifyArrVal(inputArray);
    }
    else if (mainMenuOption == 'A') {
      addArrVal(inputArray);
    }
    else if (mainMenuOption == 'R') {
      removeArrVal(inputArray);
    }

    printMainMenu();
    mainMenuOption = getMainMenuOption();
  }

  // closes input file
  inputFile.close();
  return 0;
}