#pragma once

#include <string>
#include <vector>

class code {
    public:
        code(int n, int m);
        int checkCorrect(const code& guess) const;
        int checkIncorrect(const code& guess) const;
        int getSize(){return size};
        int getNumberByIndex(){return vector[i]}
    private:
        int guessCount;
        int size;
        vector<int> secret;
        int getRandomNumber(int range);
};