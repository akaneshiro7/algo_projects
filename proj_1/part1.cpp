#include <iostream>
#include "code.h"  // Use double quotes for user-defined headers
#include <vector>  // Added missing include
using namespace std;

int main(){
    code c1 = code(5, 7);
    c1.printCode();
    // Changed initialization of 2D vector
    vector<vector<int>> samples = {{5, 0, 3, 2, 6}, {2, 1, 2, 2, 2}, {1, 3, 3, 4, 5}};
    for(int i=0; i < 3; i++) {
        code sample = code(samples[i]);
        cout << "Correct: " << c1.checkCorrect(sample) << endl;  // Corrected method name
        cout << "Incorrect: " << c1.checkIncorrect(sample) << endl;  // Corrected method name
        cout << "Test Case: ";
        sample.printCode();  // Moved to a separate line
        cout << "Actual: ";
        c1.printCode();  // Moved to a separate line
    }
}
