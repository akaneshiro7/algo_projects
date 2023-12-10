// Declarations and functions for project #4
#include <iostream>
#include <limits.h>
#include "d_matrix-2.h"
#include "d_except-1.h"
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include "board.h"

using namespace std;
typedef int ValueType; // The type of the value in a cell
const int Blank = -1; // Indicates that a cell is blank
const int SquareSize = 3; // The number of cells in a small square
// (usually 3). The board has
// SquareSize^2 rows and SquareSize^2
// columns.
const int BoardSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;
int numSolutions = 0;

// Checks if Every Cell has a non-blank value
bool board::isSolved(){
   for (int row=MinValue; row<=MaxValue; row++) {
       for (int col=MinValue; col<=MaxValue; col++){
           if (value[row][col] == Blank) {
               cout << "Board is Not Solved" << endl;
               return false;
           }
       }
   }
   cout << "Board is Solved" << endl;
   return true;
};

// Return Conflict Vector for cell i, j
vector<int> board::getConflicts(int i, int j) {
   return conflictVectors[i][j];
}

// Print Conflict Vector for cell i, j
void board::printConflictVector(int i, int j) {
   vector<int> conflictVector = getConflicts(i, j);
   for (int num : conflictVector) {
       cout << num << " ";
   }
   cout << endl;
}

// Print All Conflict Vectors
void board::printConflicts() {
   for (int row=MinValue; row<=MaxValue; row++){
       for (int col=MinValue; col<=MaxValue; col++){
           cout << "Conflict Vector for (" << row << "," << col << "): ";
           printConflictVector(row, col);
       }
   }
}

// Add a value to a cell's conflict vector
void board::addConflict(int i, int j, int val) {
   conflictVectors[i][j].push_back(val);
}

// Set the cell to blank and remove it from conflict vectors
void board::clearCell(int i, int j) {
   removeConflict(i, j, value[i][j]);
   value[i][j] = Blank;
}

// Update conflict vectors for same row, column, and square
void board::updateConflict(int i, int j, int val) {

    // Update conflict vector for own cell
    addConflict(i, j, val);
   // Update all in the same row, except cell (i, j)
   for (int row = 1; row <= BoardSize; row++) {
       if (row != i) {
           addConflict(row, j, val);
       }
   }

   // Update all in the same column, except cell (i, j)
   for (int col = 1; col <= BoardSize; col++) {
       if (col != j) {
           addConflict(i, col, val);
       }
   }
    // Update cf in same box, except already added to 
   int boxRow = ((i - 1) / 3) * 3 + 1;
   int boxCol = ((j - 1) / 3) * 3 + 1;
   for (int k = 0; k < 3; k++) {
       for (int l = 0; l < 3; l++) {
           if ((boxRow + k) == i || (boxCol + l) == j) {
               continue;
           }
           addConflict(boxRow + k, boxCol + l, val);
       }
   }
}

// Remove first instance of value from conflict vector
void board::subtractConflict(int i, int j, int val) {
   // Find the value in the conflict vector
   auto idx = find(conflictVectors[i][j].begin(), conflictVectors[i][j].end(), val);

   // If the value is found, erase it from the vector
   if (idx != conflictVectors[i][j].end()) {
       conflictVectors[i][j].erase(idx);
   }
}

void board::removeConflict(int i, int j, int val) {

    // Update Self
    subtractConflict(i,j,val);
   // Update all in the same row, except cell (i, j)
   for (int row = 1; row <= BoardSize; row++) {
       if (row != i) {
           subtractConflict(row, j, val);
       }
   }
   // Update all in the same column, except cell (i, j)
   for (int col = 1; col <= BoardSize; col++) {
       if (col != j) {
           subtractConflict(i, col, val);
       }
   }

    // Update all in the same 3x3 box, except already updated
    int boxRow = ((i - 1) / 3) * 3 + 1;
    int boxCol = ((j - 1) / 3) * 3 + 1;
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if ((boxRow + k) == i || (boxCol + l) == j) {
                continue;
            }
            subtractConflict(boxRow + k, boxCol + l, val);
        }
    }
}

board::board(int sqSize)
       : value(BoardSize+1,BoardSize+1),
         conflictVectors(BoardSize+1, vector<vector<int>>(BoardSize+1, vector<int>()))

// Board constructor
{
   clear();
}
void board::clear()
// Mark all possible values as legal for each board entry
{
   for (int i = 1; i <= BoardSize; i++)
       for (int j = 1; j <= BoardSize; j++)
       {
            // Reset conflict vectors to empty for that cell
           conflictVectors[i][j].clear();
           value[i][j] = Blank;
       }

}

// set a cell value and update its conflict vectors
void board::setCell(int i, int j, int val) {
   value[i][j] = val;
   updateConflict(i, j, val);
   return;
}


void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
   char ch;
   clear();
   for (int i = 1; i <= BoardSize; i++)
       for (int j = 1; j <= BoardSize; j++)
       {
           fin >> ch;
// If the read char is not Blank
           if (ch != '.') {
               setCell(i,j,ch-'0'); // Convert char to int
           }
       }
}
int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom. Note that i and j each go from 1 to BoardSize
{
// Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
// coordinates of the square that i,j is in.
   return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}
ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
   for (int i = 0; i < v.size(); i++)
       ostr << v[i] << " ";
   cout << endl;
}
ValueType board::getCell(int i, int j)
// Returns the value stored in a cell. Throws an exception
// if bad values are passed.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
       return value[i][j];
   else
       throw rangeError("bad value in getCell");
}
bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
       throw rangeError("bad value in setCell");
   return (getCell(i,j) == Blank);
}
void board::print()
// Prints the current board.
{
   for (int i = 1; i <= BoardSize; i++)
   {
       if ((i-1) % SquareSize == 0)
       {
           cout << " -";
           for (int j = 1; j <= BoardSize; j++)
               cout << "---";
           cout << "-";
           cout << endl;
       }
       for (int j = 1; j <= BoardSize; j++)
       {
           if ((j-1) % SquareSize == 0)
               cout << "|";
           if (!isBlank(i,j))
               cout << " " << getCell(i,j) << " ";
           else
               cout << "   ";
       }
       cout << "|";
       cout << endl;
   }
   cout << " -";
   for (int j = 1; j <= BoardSize; j++)
       cout << "---";
   cout << "-";
   cout << endl;
}