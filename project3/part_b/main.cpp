#include "Dictionary.cpp"
#include "Grid.cpp"


using namespace std;

void search(string gridPath, int sortingOption){

    Dictionary dict = Dictionary();
    Grid grid = Grid();
    try {
        grid.readGrid(gridPath);
    } catch(std::invalid_argument& e) {
        cerr << e.what() << endl;

        return;
    }

    switch (sortingOption) {
        case 1:
            cout << "Sorting via Selection Sort" << endl;
            dict.selectionSort();
            break;
        case 2:
            cout << "Sorting via Quick Sort" << endl;
            dict.quickSort();
            break;
        case 3:
            cout << "Sorting via Heap Sort" << endl;
            dict.heapsort();
            break;
        default:
            cout << "Invalid Option Selected" << endl;
    }
    findMatches(dict, grid);

}



int main() {
    string gridPath;
    cout << "Please Enter the Path to the Grid: ";
    cin >> gridPath;
    int sortingOption;
    cout << "Please Select a Sorting Option\n" <<
         "1: Selection Sort\n" <<
         "2: Quick Sort\n" <<
         "3: HeapSort Sort\n" <<
         "Option: ";
    cin >> sortingOption;
    search(gridPath, sortingOption);
}

