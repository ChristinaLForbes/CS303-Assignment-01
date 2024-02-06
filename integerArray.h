// Christina Forbes 2/6/2024 Assignment 1

#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

// adapted from KW::vector from lecture slides
class IntegerArray {
  private:
    static const size_t initialCapacity = 10;
    size_t currentCapacity;
    size_t numItems;
    int* data;
  public:
    // default constructor
    IntegerArray();

    // getters
    size_t getNumItems() { return numItems; };

    // class functions
    void reserve(size_t newCapacity);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    int findVal(int val);
    IntegerArray modifyVal(size_t index, int newVal);
    void pushBack(int val);
    void erase(size_t index);
};