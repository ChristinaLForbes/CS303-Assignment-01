// Christina Forbes 2/6/2024 Assignment 1

#include "integerArray.h"

// default constructor
IntegerArray::IntegerArray() {
  // sets default values
  currentCapacity = initialCapacity;
  numItems = 0;
  data = new int[initialCapacity];
}

// reserves additional memory
void IntegerArray::reserve(size_t newCapacity) {
  if (newCapacity > currentCapacity) {
    currentCapacity = newCapacity;
  }
  else {
    currentCapacity *= 2;
  }

  // creates new array with greater capacity
  int* newData = new int[currentCapacity];
  // copies values from original array into new array
  for (size_t i = 0; i < numItems; i++) {
    newData[i] = data[i];
  }

  // deletes original array
  delete[] data;
  // sets data to point to new array
  data = newData;
}

// overrides the subscripting operator 
int& IntegerArray::operator[](size_t index) {
  try {
    if (index < 0 || index >= numItems) {
      throw out_of_range("Index is out of range.");
    }
  }
  catch (out_of_range& error) {
    cout << error.what() << endl;
  }

  return data[index];
}

// overrides the subscripting operator
const int& IntegerArray::operator[](size_t index) const {
  try {
    if (index < 0 || index >= numItems) {
      throw out_of_range("Index is out of range.");
    }
  }
  catch (out_of_range& error) {
    cout << error.what() << endl;
  }

  return data[index];
}

// searches array for val and returns index of val if found or -1 if not found
int IntegerArray::findVal(int val) {
  for (int i = 0; i < numItems; i++) {
    if (data[i] == val) {
      // returns index of 1st instance of val in array
      return i;
    }
  }

  // val is not found in array
  return -1;
}

// changes value at index to newVal and returns array with original value and new value
IntegerArray IntegerArray::modifyVal(size_t index, int newVal) {
  try {
    if (index < 0 || index >= numItems) {
      throw out_of_range("Index is out of range.");
    }
  }
  catch (out_of_range& error) {
    cout << error.what() << endl;
  }

  // gets original value at index
  int oldVal = data[index];
  // changes value at index to new value
  data[index] = newVal;

  // creates array to store original value and new value
  IntegerArray vals;
  vals.pushBack(oldVal);
  vals.pushBack(newVal);
  return vals;
}

// adds val to the end of the array
void IntegerArray::pushBack(int val) {
  // array is full
  if (numItems == currentCapacity) {
    reserve(2 * currentCapacity);
  }

  // adds val to array
  data[numItems] = val;
  numItems++;
}

// removes value at index from the array
void IntegerArray::erase(size_t index) {
  try {
    if (index > numItems) {
      throw out_of_range("Index is out of range.");
    }
  }
  catch (out_of_range& error) {
    cout << error.what() << endl;
  }

  // removes value at index and shifts each value at higher indices down 1
  for (size_t i = index + 1; i < numItems; i++) {
    data[i - 1] = data[i];
  }

  numItems--;
}