#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class code {
    public:
        code(vector<int> arr);
        code(int n, int m);
        void generateRandomCode(int n, int m);
        int checkCorrect(code& guess) const;
        int checkIncorrect(code& guess) const;
        int getSize(){return size;};
        int getCount() {return guessCount;};
        int getNumberByIndex(int i);
        void printCode();
    private:
        int guessCount;
        int size;
        vector<int> secret;
        int getRandomNumber(int range);
};