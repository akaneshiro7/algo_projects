#include "Dictionary.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <limits.h>
#include "heap.h"
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
    if (!file.is_open()){
        cout << " FILE UNABLE TO OPEN ERROR " << endl;
        return;
    }

    // adds all words from dictionary file to the word vector
    while(getline(file, line)) {
            words.push_back(line);
    }
    file.close(); // close the dictionary file
}

// function to print word vector
void Dictionary::printWords() {
    for(const auto& word : words) {
        cout << word << endl;
    }
    cout << endl;
}

// function to use SelectionSort to sort words in the dictionary
void Dictionary::selectionSort() {
    int left = words.size() - 1;
    int right = words.size();
        for (auto i = 0; i < left; i++) {
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
//}


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

// Function to sort using QuickSort
void Dictionary::quickSort() {
    quickSortHelper(0, words.size() - 1);
}

// Helper Function
void Dictionary::quickSortHelper(int low, int high) {
    // Base Case: Range is Valid
    if (low < high) {
        // Partition Array and Get Pivot Index
        int pivotIndex = partition(low, high);
        // Recursively Apply to left and right arrays
        quickSortHelper(low, pivotIndex - 1);
        quickSortHelper(pivotIndex + 1, high);
    }
}

// Function to partition the array into two parts based on a pivot
int Dictionary::partition(int low, int high) {
    // Choose last element as pivot
    string pivot = words[high];
    // Idx of small element
    int i = (low - 1);

    // Reorder with comparison with the pivot
    for (int j = low; j <= high - 1; j++) {
        // If curr word is smaller or equal to pivot
        if (words[j] < pivot) {
            i++;
            swap(words[i], words[j]);
        }
    }
    swap(words[i + 1], words[high]);
    // Return Partition Index
    return (i + 1);
}

void Dictionary::heapsort() {
    heap<std::string> wordHeap;
    // Insert words into Heap
    for (const std::string& word : words) {
        wordHeap.insert(word);
    }

    // Sort with heapsort
    wordHeap.heapsort();

    // Clear words and reinsert back into words array
    words.clear();
    for (int i = 0; i < wordHeap.getSize(); ++i) {
        words.push_back(wordHeap.getItem(i));
    }
}

void Dictionary::writeToFile(string fileName) {
    // Open a file in write mode
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Error opening file for writing" << endl;
        return;
    }

    // Write the contents of the vector to the file
    for (const auto& line : words) {
        outFile << line << endl;
    }

    // Close the file
    outFile.close();
}