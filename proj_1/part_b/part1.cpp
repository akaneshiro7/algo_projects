/*
Homework 1 - Aidan Kaneshiro and Steven Lam
Main program file for Homework 1a.
Contains testing of the `Code` class in `code.cpp` using three different inputs.
*/

#include <iostream>
#include "code.h"
#include <vector>

using namespace std;

int main() {
    // Create an instance of the Code class with a random code of length 5 and digits in the range 0-6
    Code c1 = Code(5, 7);
    c1.printCode();  // Print the generated code

    // Changed initialization of 2D vector
    vector<vector<int>> samples = {{5, 0, 3, 2, 6}, {2, 1, 2, 2, 2}, {1, 3, 3, 4, 5}};

    // Iterate through three different input samples
    for (int i = 0; i < 3; i++) {
        // Create a Code instance based on the current input sample
        Code sample = Code(samples[i]);
        
        // Check the number of correct and incorrect digits between the generated code (c1) and the sample code
        cout << "Correct: " << c1.checkCorrect(sample) << endl;
        cout << "Incorrect: " << c1.checkIncorrect(sample) << endl;

        // Print the current sample code
        cout << "Test Case: ";
        sample.printCode();

        // Print the actual generated code (c1)
        cout << "Actual: ";
        c1.printCode();
    } // end for loop
    
    return 0;
}
