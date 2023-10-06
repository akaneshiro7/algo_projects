/*
Homework 1

Names: Aidan Kaneshiro and Steven Lam

Main program file for homework 1. Contains declarations for Mastermind,
printCode, humanGuess, getResponse, and playGame functions.
*/

#include "mastermind.h"
#include "code.h"
#include <limits>

using namespace std;

Mastermind::Mastermind() : game(5, 10) {
    // default constructor with size of 5 and range of 10
    playGame(5, 10); // calls playGame
}

Mastermind::Mastermind(int n, int m) : game(n, m) {
    // default constructor with n size and m range parameters
    playGame(n, m); // calls playGame
}

void Mastermind::printCode() {
    // Print the secret code
    game.printCode();
}

Code Mastermind::humanGuess() {
    // gets digits incrementally from user, appends digits to vector to be converted to a guess
    vector<int> inputGuess;
    
    int i = 0;
    while (i < game.getSize()) {
        int input;
        cout << "Please input digit " << i << ": ";
        
        if (!(cin >> input)) {
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the line
            cout << "Invalid input. Please enter an integer." << endl;
        } else {
            inputGuess.push_back(input);
            i++;  // Only increment when a valid integer is provided
        }
    }
    
    return Code(inputGuess);
}

response Mastermind::getResponse(const Code& c1) {
    // Get the response for a given guess, returns correct, incorrect response
    int corr = game.checkCorrect(c1);
    int incorr = game.checkIncorrect(c1);
    response r = response(corr, incorr);

    return r;
}


bool Mastermind::isSolved(response& res) {
    // Check if the game is solved based on the response
    return game.getSize() == res.getResponse()[0];
}

void Mastermind::playGame(int n, int m) {
    // Play the Mastermind game
    game = Code(n, m); 
    printCode();

    int round = 0; // variable to store round #

    // codebreaker wins if the correct code is guessed in ten or fewer guesses, and otherwise the codemaker wins.
    while (round < 10) {

        Code input = humanGuess();

        int guessCorrect = game.checkCorrect(input);
        int guessIncorrect = game.checkIncorrect(input);

        response guessResponse = response(guessCorrect, guessIncorrect);

        if (isSolved(guessResponse)) {
            cout << "Congratulations! You're #1!!! Go buy yourself a cookie";
            return;
        }

        cout << guessResponse << endl; // prints out guessResponse using overloaded function
        round++;
    }

    cout << "The codemaker has won! GG, better luck next time!";
}
// end of mastermind.cpp file
