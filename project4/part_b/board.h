#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "d_matrix-2.h"
#include "d_except-1.h"

using namespace std;

typedef int ValueType;

class board {
public:
    board(int sqSize);
    void clear();
    void initialize(ifstream &fin);
    void print();
    bool isBlank(int, int);
    int getCell(int, int);
    void setCell(int i, int j, int val);
    void clearCell(int i, int j);
    void addConflict(int i, int j, int val);
    void updateConflict(int i, int j, int val);
    void subtractConflict(int i, int j, int val);
    void removeConflict(int i, int j, int val);
    void printRecursiveCalls();
    vector<int> getConflicts(int i, int j);
    void printConflicts();
    void printConflictVector(int i, int j);
    bool isSolved();
    bool solveBoard();
    int getRecursiveCalls();
    int num;
private:
    matrix<ValueType> value;
    vector<vector<vector<int>>> conflictVectors;
    int recursiveCalls;
};

#endif // BOARD_H
