#pragma once

#include "code.h"
#include "response.h"

class Mastermind {
public:
    Mastermind();
    Mastermind(int n, int m);
    void printCode();
    Code humanGuess();
    response getResponse(const Code& c1);
    bool isSolved(response& res);
    void playGame();

private:
    Code generatedCode;
};