#include "code.h"
#include <iostream>
using namespace std;

code::code(int n, int m){
    // n = number of digits
    // m = range of digits (0-1)
    size = m;
    for (int i=0; i<n;i++){
        int randomNumber = getRandomNumber(m);
        secret.push_back(randomNumber)
    }
};

int code::checkCorrect(const code& guess){
    // Check how many guesses have the correct number in an correct spot 
    int correct = 0;
    if (size != giess.getSize){
        cout << "Invalid Guess" << endl;
        return
    }
    for(int i=0;i<m;i++) {
        if (secret[i] == guess.getNumberByIndex(i)){
            count += 1
        }
    }
    return count
};

int code::checkIncorrect(const code& guess){

    // Check how many guesses have the correct number but in an incorrect spot
};

int code::getRandomNumber(int range){
    // Get a random number within [0, range-1]
    return rand() % range 
}
