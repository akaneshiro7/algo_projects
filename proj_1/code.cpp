#include "code.h"
#include <iostream>
#include <string>
#include <vector>  // Added missing include
#include <cstdlib>  // Added for rand()
#include <typeinfo>  // Added for typeid()
using namespace std;

code::code(vector<int> arr) {
    size = arr.size();
    secret = arr;  // Simplified copying of vector
}

void code::generateRandomCode(int n, int m) {
    for (int i = 0; i < n; i++){
        int randomNumber = getRandomNumber(m);
        secret.push_back(randomNumber);
    }
}

code::code(int n, int m){
    // n = number of digits
    // m = range of digits from 0 - (m-1)
     size = n;
     generateRandomCode(n, m);  // Added missing semicolon
}


int code::checkCorrect(code& guess) const {
    int correct = 0;
    if (size != guess.getSize()){
        cout << "Invalid Guess" << endl;
        return -1;  // Added return value
    }
    for(int i = 0; i < size; i++) {
        if (secret[i] == guess.getNumberByIndex(i)){
            correct += 1;
        }
    }
    return correct;
}

int code::checkIncorrect(code& guess) const {
    vector<bool> checked(size, false);  // Corrected variable name


    int incorrect = 0;  // Added missing semicolon
    if(size != guess.getSize()) {
        cout << "Please give a guess of the same length." << endl;
        return -1;  // Added return value
    }
    for (int a=0; a <size; a++){
        if (secret[a] == guess.getNumberByIndex(a)) {
            checked[a] = true;
        }
    }
    for(int j = 0; j < size; j++) {
        for(int k = 0; k < size; k++) {
            if (checked[k] == false && j != k && secret[j] != guess.getNumberByIndex(j) && secret[k] != guess.getNumberByIndex(k) && secret[j] == guess.getNumberByIndex(k)) {
                incorrect += 1;
                checked[k] = true;
                break;
            }
        }
    }

    return incorrect;
}

int code::getRandomNumber(int range){
    return rand() % range;
}

void code::printCode(){
    for (int i = 0; i < size; i++) {
        cout << secret[i];
    }
    cout << endl;  // Added newline character
}

int code::getNumberByIndex(int i) {
    if(i < 0 || i >= secret.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return secret[i];
};