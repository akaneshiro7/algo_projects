#include "code.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


code::code(string x) {
    try{
        int guess = stoi(x);
        
        if (guess >= 0) {
            for(int i = 0; i < ; i++) {
                secret.push_back(guess[i]);
            }
        } else {
            throw bad_cast;
        }
    }
    catch (bad_cast) {
        return "Please input positive numbers.";
    }
};

code::code(int n, int m){
    // n = number of digits
    // m = range of digits from 0 - (m-1)

    try {
        if (typeid(n).name() == "i" && typeid(m).name() == "i") {
            int size = n

            for (int i = 0; i < n; i++){
                int randomNumber = getRandomNumber(m);
                secret.push_back(randomNumber);
                if (counter.find(randomNumber) == counter.end()) {
                    counter[randNumber] += 1;
                } else {
                    counter[randNumber] = 1;
                }
            }
        } else {
            throw 505;
        }
    } catch (...) {
        return "Please give integer inputs for the first and second argument in the constructor";
    }
};

int code::checkCorrect(const code& guess){
    // Check how many guesses have the correct number in an correct spot 
    int correct = 0;
    if (size != guess.getSize()){
        cout << "Invalid Guess" << endl;
        return;
    }
    for(int i = 0;i < size;i++) {
        if (secret[i] == guess.getNumberByIndex(i)){
            correct += 1;
        }
    }
    return correct;
};

int code::checkIncorrect(const code& guess){
    // Check how many guesses have the correct number but in an incorrect spot
        int incorrect = 0;
        unordered_map<int, int> guess_count = guess.getCounter();

        for(const auto& pair: guess_count) {

            incorrect += min(pair.second, counter[pair.first]);
        }

        return incorrect;
};

int code::getRandomNumber(int range){
    // Get a random number within [0, range-1]
    return rand() % range;
};

