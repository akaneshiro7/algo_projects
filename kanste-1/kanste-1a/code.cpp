/*
Homework 1 - Aidan Kaneshiro and Steven Lam
Main code program file for Homework 1a.
Contains declarations for Code and other functions
*/

#include "code.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>

using namespace std;

// Constructor for Code class that takes a vector of integers as input
Code::Code(vector<int> arr) {
    size = arr.size();
    secret = arr;  // Initialize the 'secret' vector with the provided input
}

// Generate a random code of length 'n' with digits in the range [0, m-1]
void Code::generateRandomCode(int n, int m) {
    for (int i = 0; i < n; i++) {
        int randomNumber = getRandomNumber(m);
        secret.push_back(randomNumber);  // Add random digits to the 'secret' vector
    }
}

// Constructor for Code class that generates a random code of length 'n' with digits in the range [0, m-1]
Code::Code(int n, int m) {
    size = n;
    generateRandomCode(n, m);  // Generate a random code during construction
}

// Check the number of correct digits in a guess
int Code::checkCorrect(const Code& guess) const {
    int correct = 0;
    if (size != guess.getSize()) {  // Ensure the guess has the same length as the secret
        cout << "Invalid Guess" << endl;
        return -1;  // Return -1 to indicate an error
    }
    for (int i = 0; i < size; i++) {
        if (secret[i] == guess.getNumberByIndex(i)) {
            correct += 1;  // Count the correct digits in the guess
        }
    }
    return correct;  // Return the count of correct digits
}

// Check the number of incorrect digits in a guess
int Code::checkIncorrect(const Code& guess) const {
    vector<bool> checked(size, false);  // Initialize a vector to keep track of checked digits

    int incorrect = 0;
    if (size != guess.getSize()) {  // Ensure the guess has the same length as the secret
        cout << "Please give a guess of the same length." << endl;
        return -1;  // Return -1 to indicate an error
    }
    for (int a = 0; a < size; a++) {
        if (secret[a] == guess.getNumberByIndex(a)) {
            checked[a] = true;  // Mark correct digits as checked
        }
    }
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            if (checked[k] == false && j != k && secret[j] != guess.getNumberByIndex(j) && secret[k] != guess.getNumberByIndex(k) && secret[j] == guess.getNumberByIndex(k)) {
                incorrect += 1;  // Count incorrect digits
                checked[k] = true;  // Mark incorrect digits as checked
                break;
            }
        }
    }
    return incorrect;  // Return the count of incorrect digits
}

// Generate a random number in the range [0, range-1]
int Code::getRandomNumber(int range) {
    return rand() % range;
}

// Print the code to the console
void Code::printCode() {
    for (int i = 0; i < size; i++) {
        cout << secret[i];  // Print each digit of the code
    }
    cout << endl;  // Print a newline character for formatting
}

// Get the digit at a specific index in the 'secret' vector
int Code::getNumberByIndex(int i) const {
    if (i < 0 || i >= secret.size()) {
        throw std::out_of_range("Index out of bounds");  // Throw an exception for out-of-bounds index
    }
    return secret[i];  // Return the digit at the specified index
} // end of code.cpp file