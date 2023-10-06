#include "mastermind.h"

using namespace std;

mastermind::mastermind() {
    generatedCode = code(5, 10);
};

mastermind::mastermind(int n, int m) {
    generatedCode = code(n, m);
};

void printCode() {
    // print out secret code
    cout << generatedCode;
};

code humanGuess() {
    string numGuess;

    cout << "Please give a guess: ";
    cin >> numGuess;
    code guess = code(numGuess);

    return guess;
};

response mastermind::getResponse(const code& c1) {
    int corr = c1.checkCorrect;
    int incorr = c1.checkIncorrect;
    response r = response(corr, incorr);

    return r;
};

bool mastermind::isSolved(const response& res) {
    return generatedCode.getSize() == res.getResponse()[0];
}

void playGame() {
    Code game = Code(rand() % 10, rand() % 10); // intiializes random number 0-9 
    game.printCode(); // prints the random code

    int round = 0, int input;
    vector <int> guess;

    while (round < 10) {
        // prompts user for gets
        for (int i = 0; i < game.getSize(); i++) {
            cout << "Please input a guess: ";
            cin >> input;

            while(typeid(input) != typeid(int)) {
                cout << "Please input a integer: ";
                cin >> input;
            }

            guess.push_back(input);
        }

        int guessCorrect = guess.checkCorrect();
        int guessIncorrect = guess.checkIncorrect();

        response guessResponse = response(guessCorrect, guessIncorrect);

        if (isSolved(guessResponse)) {
            cout << "Congratulations! You're #1!!! Go buy yourself a cookie";
            return;
        }

        cout << guessResponse << endl;
        round++;
    }

    cout << "The codemaker has won! GG, better luck next time!";
}