#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class code {
    public:
        code(string x);
        code(int n, int m);
        int checkCorrect(const code& guess) const;
        int checkIncorrect(const code& guess) const;
        int getSize(){return size};
        int getCount() {return guessCount};
        int getNumberByIndex(int i){return secret[i]};
        void play();
        unordered_map<int, int> getCounter(){return counter};
    private:
        int guessCount;
        int size;
        vector<int> secret;
        unordered_map<int, int> counter;
        int getRandomNumber(int range);
};