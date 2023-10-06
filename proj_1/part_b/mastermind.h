#pragma once

#include "code.h"
#include "response.h"

class mastermind {
    public:
    mastermind();
    mastermind(int n, int m);
    void printCode();
    code humanGuess();
    response getResponse(const code& c1);
    bool isSolved(const response& res);
    void playGame();

    private:
    Code generatedCode;
};