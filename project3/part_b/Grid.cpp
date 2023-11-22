#include <bits/stdc++.h>
#include "Grid.h"
#include "Dictionary.h"
#include <iostream>
#include <set>
#include <stdexcept>

using namespace std;
// default constructor to create instance
Grid::Grid() {
    width = 0;
    height = 0;
}

// function to read grid from file and store in 2D vector
void Grid::readGrid(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("Unable to Open File");
    };
    vector<char> notAllowed{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // vector to hold number values to not read

    string line;
    while(getline(file, line)) {
        vector<char> row;
        for(char c: line) {
            auto found = find(notAllowed.begin(), notAllowed.end(),c); // returns True if notALlowed value found

            if (found != notAllowed.end()) {
                continue;
            }
            else if (c != ' ' ) { // append to vector if not a space
                row.push_back(c);
            }
        }
        // assign width and row size and append row to 2d grid
        if (row.size() > 0) {
            if (width == 0) width = row.size();
            grid.push_back(row);
            height++;
        }
    }

    file.close();
}

char Grid::getLetter(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }

    return ' ';  // Return a space or some other default character for invalid coordinates.
}

// Getter function to get Width of Grid
int Grid::getWidth() {
    return width;
}

// Getter function to get Height of Grid
int Grid::getHeight() {
    return height;
}

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; // change in x for the 8 directions
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; // change in y for the 8 directions

// Helper function to find words to add to Potential words
void exploreWord(Dictionary &dict, Grid &grid, int i, int j, int dir, string &currWord, set<string> &potentialWords, vector<string> &tempDict, bool isFirstCall = true) {
    if (currWord.length() > 22) return; // 22 is the length of the longest string in dictionary

    int rows = grid.getWidth();
    int cols = grid.getHeight();

    // Check if currWord is a potential match in tempDict
    for (const auto &word: tempDict) {
        if (currWord == word && currWord.length() >= 5) { // add words that are length of 5 and in dictionary
            potentialWords.insert(currWord);
            break; // No need to check further once a match is found
        }
    }

    i = (i + dx[dir] + rows) % rows;
    j = (j + dy[dir] + cols) % cols;

    char nextChar = grid.getLetter(i, j); // getLetter to append to current Word
    currWord.push_back(nextChar); // append nextChar to current Word

    // if firstCall, find potential matches from dict, else parse filter through tempDict for potential words
    if (isFirstCall) {
        for (const auto &word: dict.getWords()) {
            if (word.find(currWord) == 0) { // if the dictionary word starts with currWord
                tempDict.push_back(word);
            }
        }
    } else {
        vector<string> newTempDict;
        // updates tempDict with the new potentialWords that can be found
        for (const auto &word: tempDict) {
            if (word.find(currWord) == 0) {
                newTempDict.push_back(word);
            }
        }
        tempDict = newTempDict;
    }


    exploreWord(dict, grid, i, j, dir, currWord, potentialWords, tempDict, false);
    currWord.pop_back();
}


// Function to find the words hidden in the grid and print the list of matches
void findMatches(Dictionary &dict, Grid &grid) {
    set<string> potentialWords;
    vector<string> tempDict;
    int rows = grid.getWidth();
    int cols = grid.getHeight();

    for (int i = 0; i < rows; i++) { // iterates through rows
        for (int j = 0; j < cols; j++) { // iterates through columns
            for (int dir = 0; dir < 8; dir++) { // iterates and checks in each 8 direcitons
                string currWord;
                exploreWord(dict, grid, i, j, dir, currWord, potentialWords, tempDict);
            }
        }
    }

    // print out all found matches in grid
    cout << "Found words:" << endl;
    // cout << potentialWords.size() << endl;
    for (const auto &word: potentialWords) {
        cout << word << endl;
    }

}

void Grid::printGrid() {
    for (const auto& row : grid) {
        for (char elem : row) {
            cout << elem;
        }
        cout << endl; // New line at the end of each row
    }
}
