//
// Created by Steven Lam on 11/9/2023.
//
#pragma once

#include <iostream>
#include <vector>
#include "Dictionary.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <limits.h>

using namespace std;

class Dictionary {
public:
    Dictionary();
    void readWords(const string& filename);
    void printWords();
    void selectionSort();
    vector<string> getWords();
    bool findWord(const string& s);

    void quickSortHelper(int low, int high);
    void quickSort();
    int partition(int low, int high);
    void heapsort();

private:
    vector<string> words;
    void maxHeapify(vector<string>& heap, int i, int n);
    void buildMaxHeap(vector<string>& heap);

    void writeToFile(string fileName);
};