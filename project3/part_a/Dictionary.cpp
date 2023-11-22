#include "Dictionary.h"
#include <fstream>
#include <cmath>

using namespace std;

// default constructor that calls readWords to store strings in vector words
Dictionary::Dictionary() {
    readWords("dictionary");
}

// function to read words from dictionary and return vector of words
void Dictionary::readWords(const string& filename) {
    ifstream file(filename);
    string newFile = filename + ".txt";
    string line;
    if (!file.is_open()) return;

    // adds all words from dictionary file to the word vector
    while(getline(file, line)) {
            words.push_back(line);
    }
    file.close(); // close the dictionary file
}

// function to print word vector
void Dictionary::printWords() {
    for(const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
}

// function to use SelectionSort to sort words in the dictionary
void Dictionary::sortWords() {
    int left = words.size() - 1;
    int right = words.size();

    for (int i = 0; i < left; i++) {
        int minIndx = i;
        for (int j = i+1; j < right; j++) {
            if (words[j] < words[minIndx]) {
                minIndx = j;
            }
        }

        // updates first alphabetical word with newfound alphabetically preceding word
        if (minIndx != i) {
            string temp = words[i];
            words[i] = words[minIndx];
            words[minIndx] = temp;
        }
    }

}

// getter function to get words vector
vector<string> Dictionary::getWords() {
    return words;
}

// function that will find the given search word if it exists
bool Dictionary::findWord(const string &s) {
    int left = 0; // left pointer
    int right = int(words.size()) - 1; // right pointer

    while (left <= right) {
        int mid = floor((left + right) / 2);
        string compareWord = words[mid];

        if(compareWord == s){
            return true; // returns true when word can be found in dictionary
        }
        else if(compareWord < s){
            left = mid + 1;
        }
        else if(compareWord > s){
            right = mid - 1;
        }
    }
    return false; // handles case when word cannot be found in dictionary

}