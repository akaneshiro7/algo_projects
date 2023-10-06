/*
Homework 1 part b

Names: Aidan Kaneshiro and Steven Lam

Main function file declaration for response.
Declarations for response consctructors, get and set functions, and 
overloaded operators
*/

#include "response.h"
#include <iostream>
#include <vector>

using namespace std;

response::response(int corr, int incorr) {
    // Constructor for response class, initializes correct and incorrect counts
    setResponse(corr, incorr);
};

// Sets the response to the given parameters
void response::setResponse(int corr, int incorr) {
    correct = corr;
    incorrect = incorr;
};

// Gets the correct and incorrect response counts and returns as a vector
vector<int> response::getResponse() {
    vector<int> temp {correct, incorrect};
    return temp; 
};

bool operator==(const response& lhs, const response& rhs) {
    // Check if two response objects are equal
    return (lhs.correct == rhs.correct && lhs.incorrect == rhs.incorrect);
};

ostream& operator<< (ostream& ostr, const response& r) {
    // Overloaded << operator to display a response object
    ostr << r.correct << ", " << r.incorrect;
    return ostr;
};