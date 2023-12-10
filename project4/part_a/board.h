#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "d_matrix-2.h"
#include "d_except-1.h"

using namespace std;

class board
{
public:
    board(int);
    void clear();
    void initialize(ifstream &fin);
    void print();
    bool isBlank(int, int);
    int getCell(int, int);
    void setCell(int i, int j, int val);
    void clearCell(int i, int j);
    void addConflict(int i, int j, int val);
    void updateConflict(int i, int j, int val);
    void removeConflict(int i, int j, int val);
    void subtractConflict(int i, int j, int val);
    vector<int> getConflicts(int i, int j);
    void printConflicts();
    void printConflictVector(int i, int j);
    bool isSolved();

private:
    matrix<int> value;
    vector<vector<vector<int>>> conflictVectors;
};

#endif
