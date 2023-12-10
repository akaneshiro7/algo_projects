#include <iostream>
#include <vector>
#include "d_matrix-2.h"
#include "d_except-1.h"
#include <fstream>
#include "board.cpp"

using namespace std;

int main()
{
   cout << "IN MAIN" << endl;
   ifstream fin;
//// Read the sample grid from the file.
   string fileName = "sudoku.txt";

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
           b1.isSolved();
       }
   }
   catch (indexRangeError &ex)
   {
       cout << ex.what() << endl;
       exit(1);
   }
}