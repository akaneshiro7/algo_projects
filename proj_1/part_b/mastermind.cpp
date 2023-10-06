#include "mastermind.h"
#include "code.h"

using namespace std;

Mastermind::Mastermind() : game(5, 10) {
    playGame(5, 10);
}

Mastermind::Mastermind(int n, int m) : game(n,m) {
    playGame(n, m);
}

void Mastermind::printCode() { // Assuming this should be a member function
    game.printCode();
}

Code Mastermind::humanGuess() { // Assuming this should be a member function
    int input; // Fixed syntax here
    vector<int> inputGuess;
    for (int i = 0; i < game.getSize(); i++) {
        cout << "Please input digit " << i << ": ";
        cin >> input;

        // Removed typeid check since it's not logical here

        inputGuess.push_back(input);
    }
    return Code(inputGuess);
}

response Mastermind::getResponse(const Code& c1) {
    int corr = game.checkCorrect(c1); // Assuming these should be function calls
    int incorr = game.checkIncorrect(c1); // Assuming these should be function calls
    response r = response(corr, incorr);

    return r;
}

bool Mastermind::isSolved(response& res) {
    return game.getSize() == res.getResponse()[0];
}

void Mastermind::playGame(int n, int m) { // Assuming this should be a member function
    game = Code(n, m); // Assuming code is the correct class name
    printCode();

    int round = 0;

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