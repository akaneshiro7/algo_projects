#pragma once

#include <string>
#include <vector>
#include <iostream>
class code {
    public:
        code(vector<int> arr);
        code(int n, int m);
        void generateRandomCode();
        int checkCorrect(const code& guess) const;
        int checkIncorrect(const code& guess) const;
        int getSize(){return size};
        int getCount() {return guessCount};
        int getNumberByIndex(int i){return secret[i]};
        void printCode();
    private:
        int guessCount;
        int size;
        vector<int> secret;
        int getRandomNumber(int range);
};