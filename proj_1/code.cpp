#include "code.h"
#include <iostream>
#include <string>
using namespace std;

code::code(vector<int> arr) {
    size = arr.size();
    for(int i = 0; i < arr.size(); i++) {
        secret.push_back(arr[i]);
    }
}

code::code(int n, int m){
    // n = number of digits
    // m = range of digits from 0 - (m-1)

    try {
        if (typeid(n).name() == "i" && typeid(m).name() == "i") {
            size = n;
            secret = generateRandomCode(n, m)
        } else {
            throw 505;
        }
    } catch (...) {
        return "Please give integer inputs for the first and second argument in the constructor";
    }
};

void code::generateRandomCode(int n, int m) {
    for (int i = 0; i < n; i++){
        int randomNumber = getRandomNumber(m);
        secret.push_back(randomNumber);
    }
}

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
        vector <bool> check(size, false);
        int incorrect = 0
        if(size != guess.getSize()) {
            cout << "Please give a guess of the same length." << endl;
            return;
        }

        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if (checked[k] == false && j != k && secret[j] != guess.getNumberByIndex(k) && secret[k] != guess.getNumberByIndex(k) &&  secret[j] == guess.getNumberByIndex(k)) {
                    incorrect += 1;
                    checkld[k] = true;
                }
            }
        }

        return incorrect;
};

int code::getRandomNumber(int range){
    // Get a random number within [0, range-1]
    return rand() % range;
};

void code::printCode(){
    for (int i = 0; i < size; i++) {
        cout << secret[i];
    }
    return
}