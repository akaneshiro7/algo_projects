#include "board.cpp"
#include <fstream>


int main()
{
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
        int count = 1.0;
        int totalRecursiveCalls = 0;

        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            b1.num = count;
            cout << "SOLVING BOARD " << count << endl;
            b1.solveBoard();
            b1.print();
            // b1.printConflicts();
            b1.printRecursiveCalls();

            // b1.isSolved();
            count++;
            totalRecursiveCalls += b1.getRecursiveCalls(); 
        }
        count--;
        cout << "Average Recursive Calls: " << totalRecursiveCalls / count << endl; 
        cout << "Total Recursive Calls: " << totalRecursiveCalls << endl;
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}