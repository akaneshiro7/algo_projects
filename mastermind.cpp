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
    response correctCode = getResponse(generatedCode);

    return (res == correctCode);

}
