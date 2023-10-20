/*
Header file code.h for the Code class
vector implementation for Code constructor
Asssumption: easiest way to handle n integers as a single code
*/



#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Code {
public:
    // Constructor that takes a vector of integers as input
    Code(vector<int> arr);

    // Constructor that generates a random code of length 'n' with digits in the range [0, m-1]
    Code(int n, int m);

    // Generate a random code of length 'n' with digits in the range [0, m-1]
    void generateRandomCode(int n, int m);

    // Check the number of correct digits in a guess
    int checkCorrect(const Code& guess) const;

    // Check the number of incorrect digits in a guess
    int checkIncorrect(const Code& guess) const;

    // Get the size of the code
    int getSize() const { return size; };

    // Get the guess count
    int getCount() const { return guessCount; };

    // Get the digit at a specific index in the code
    int getNumberByIndex(int i) const;

    // Print the code to the console
    void printCode();

private:
    int guessCount;
    int size;
    vector<int> secret;

    // Generate a random number in the range [0, range-1]
    int getRandomNumber(int range);
}; // End of code class


// End of header file