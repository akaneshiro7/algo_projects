#include "Dictionary.cpp"
#include "Grid.cpp"

using namespace std;

int main() {
    Dictionary dict = Dictionary(); // Create dict object of Dictionary
    Grid grid = Grid(); // Create grid object of Grid
    grid.readGrid("input30"); // input desired grid file
    dict.printWords();
    cout << "----------------------------------------------------------------------------------" << endl;
    dict.sortWords();
    dict.printWords();

    findMatches(dict, grid); // find all matches in grid

    // findWord test
    bool found = dict.findWord("awarded");
    if (found) cout << "The word was found!" << endl;
    else cout << "The word was not found" << endl;

}