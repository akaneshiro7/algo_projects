//
// Created by Steven Lam on 11/9/2023.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#pragma once

class Grid {
public:
    Grid();
    void readGrid(const string& filename);
    char getLetter(int x, int y); // gets letter of given element from grid
    int getWidth(); // gets width of grid
    int getHeight(); // gets height of grid
private:
    vector<vector<char>> grid;
    int width, height;
};


