//
// Created by Steven Lam on 11/9/2023.
//

#include <iostream>
#include <vector>

#pragma once
using namespace std;

class Dictionary {
public:
    Dictionary();
    void readWords(const string& filename);
    void printWords();
    void sortWords();
    vector<string> getWords();
    bool findWord(const string& s);
private:
    vector<string> words;
};