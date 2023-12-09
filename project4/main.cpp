// Declarations and functions for project #4
#include <iostream>
#include <limits.h>
#include "d_matrix-2.h"
#include "d_except-1.h"
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>

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
class board
// Stores the entire Sudoku board
{
public:
    board(int);
    void clear();
    void initialize(ifstream &fin);
    void print();
    bool isBlank(int, int);
    ValueType getCell(int, int);
    void setCell(int i, int j, int val);
    void clearCell(int i, int j);
    void addConflict(int i, int j, int val);
    void updateConflict(int i, int j, int val);
    void removeConflict(int i, int j, int val);
//    void checkConflict
    // TODO GET CONFLICT
    vector<int> getConflicts(int i, int j);
    void printConflicts();
    void printConflictVector(int i, int j);
    bool isSolved();
private:
// The following matrices go from 1 to BoardSize in each
// dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
    matrix<ValueType> value;
    vector<vector<vector<int>>> conflictVectors;

};

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


vector<int> board::getConflicts(int i, int j) {
    return conflictVectors[i][j];
}
void board::printConflictVector(int i, int j) {
    vector<int> conflictVector = getConflicts(i, j);
    for (int num : conflictVector) {
        cout << num << " ";
    }
    cout << endl;
}

void board::printConflicts() {
    for (int row=MinValue; row<=MaxValue; row++){
        for (int col=MinValue; col<=MaxValue; col++){
            cout << "Conflict Vector for (" << row << "," << col << "): ";
            printConflictVector(row, col);
        }
    }
}
void board::addConflict(int i, int j, int val) {
    //Todo ADD CHECKING TO MAKE SURE CONFLICT VECTORS DO NOT CONTAIN DUPLICATE VALUES
    if (find(conflictVectors[i][j].begin(), conflictVectors[i][j].end(), val) == conflictVectors[i][j].end()) {
        // If the value is not present, add it to the vector
        conflictVectors[i][j].push_back(val);
    }
}

void board::clearCell(int i, int j) {
    removeConflict(i, j, value[i][j]);
    value[i][j] = Blank;
}

void board::updateConflict(int i, int j, int val) {
    // TODO Update All with same row
    for (int row=MinValue; row<=MaxValue; row++) {
        addConflict(row, j, val);
    }
    // TODO Update All with same column
    for(int col=MinValue; col<=MaxValue; col++) {
        addConflict(i, col, val);
    }
    // TODO Update All with same 3x3 box
    int boxRow = ((i-1) / 3) * 3 + 1; // Math to get top left cell in box
    int boxCol = ((j-1) / 3) * 3 + 1; // Math to get top left cell in box
    for (int k=0; k<3; k++) {
        for (int l=0; l<3; l++) {
            addConflict(boxRow+k, boxCol+l, val);
        }
    }
}

void board::removeConflict(int i, int j, int val) {
    // More complicated than simply removing vector if conflict vectors do not have duplicate entries for duplicat conflicts
    // Any cell can conflict with a number up to 3 times, might have to adjust addConflict function checking for duplicates.
    // Aidan - Have solution in mind
    // TODO Remove All with same row
    // TODO Remove All with same column
    // TODO Remove All with same 3x3 box

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
            conflictVectors[i][j].clear();
            value[i][j] = Blank;
        }

}

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
                updateConflict(i,j,ch-'0');
            }
//            else {
//                // !TODO CHANGE THIS LATER NO MORE ELSE LEAVE EMPTY
//                setCell(i, j, 0);
//            }
            // UPDATE CONFLICT VECTORS
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

int main()
{
    cout << "IN MAIN" << endl;
    ifstream fin;
//// Read the sample grid from the file.
    string fileName = "../smallSudoku.txt";

    fin.open(fileName.c_str());
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    {
        board b1(SquareSize);

        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            b1.print();
            b1.printConflicts();
        }
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}