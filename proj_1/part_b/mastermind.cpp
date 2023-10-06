#include "mastermind.h"
#include "code.h"

using namespace std;

Mastermind::Mastermind() : generatedCode(5, 10) {
}

Mastermind::Mastermind(int n, int m) : generatedCode(n, m) {
}

void Mastermind::printCode() { // Assuming this should be a member function
    generatedCode.printCode();
}

Code Mastermind::humanGuess() { // Assuming this should be a member function
    int input; // Fixed syntax here
    vector<int> inputGuess;
    for (int i = 0; i < generatedCode.getSize(); i++) {
        cout << "Please input a guess: ";
        cin >> input;

        // Removed typeid check since it's not logical here

        inputGuess.push_back(input);
    }
    return Code(inputGuess);
}

response Mastermind::getResponse(const Code& c1) {
    int corr = generatedCode.checkCorrect(c1); // Assuming these should be function calls
    int incorr = generatedCode.checkIncorrect(c1); // Assuming these should be function calls
    response r = response(corr, incorr);

    return r;
}

bool Mastermind::isSolved(response& res) {
    return generatedCode.getSize() == res.getResponse()[0];
}

void Mastermind::playGame() { // Assuming this should be a member function
    Code game = Code(rand() % 10, rand() % 10); // Assuming code is the correct class name
    printCode();

    int round = 0;
    vector<int> guess;

    while (round < 10) {

        Code input = humanGuess();

        int guessCorrect = game.checkCorrect(input);
        int guessIncorrect = game.checkIncorrect(input);

        response guessResponse = response(guessCorrect, guessIncorrect);


        if (isSolved(guessResponse)) {
            cout << "Congratulations! You're #1!!! Go buy yourself a cookie";
            return;
        }

        cout << guessResponse << endl; // Assuming response has an overloaded << operator
        round++;
    }

    cout << "The codemaker has won! GG, better luck next time!";
}
