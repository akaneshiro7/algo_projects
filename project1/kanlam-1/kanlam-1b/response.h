/*
Homework 1 part b

Names: Aidan Kaneshiro and Steven Lam

Header file response.h for the Response class
Contains response constructors, public functions for set and get
Overloaded functions for << and ==
*/


#pragma once

#include <vector>
#include <iostream>
using namespace std;

class response {
public:
    // Constructor to initialize response object with correct and incorrect counts
    response(int corr, int incorr);

    // Set the response counts to the given values
    void setResponse(int corr, int incorr);

    // Get the correct and incorrect response counts and return as a vector
    vector<int> getResponse();

    // Overloading of the equality operator (==) to compare two response objects
    friend bool operator==(const response &lhs, const response &rhs);

    // Overloading of the << operator to display a response object
    friend ostream& operator<<(ostream& ostr, const response& r);

private:
    int correct;    // Correct count in the response
    int incorrect;  // Incorrect count in the response
};
