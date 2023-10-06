/*
Homework 1
Name: Aidan Kaneshiro and Steven Lam 

Header file mastermind.h for the Mastermind class
Contains constructors, public functions, and private data Code
*/

#pragma once

#include "code.h"
#include "response.h"

class Mastermind {
public:
    // Default constructor
    Mastermind();

    // Parameterized constructor
    Mastermind(int n, int m);

    // Print the secret code
    void printCode();

    // Take a guess from the human player
    Code humanGuess();

    // Get the response for a given guess
    response getResponse(const Code& c1);

    // Check if the game is solved based on the response
    bool isSolved(response& res);

    // Play the Mastermind game
    void playGame();

private:
    Code game; // The secret code to be guessed
};


// End of header file