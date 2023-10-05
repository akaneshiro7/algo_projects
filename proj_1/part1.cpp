#include <iostream>
#include <code.h>

int main(){
    code c1 = code(5, 7);

    vector<vector<int>> samples = [[5, 0, 3, 2, 6], [2, 1, 2, 2, 2], [1, 3, 3, 4, 5]]
    for(int i=0; i < 3; i++) {
        code sample = code(samples[i]);
        cout << "Correct: " << c1.getCorrect(sample) << endl;
        cout << "Incorrect: " << c1.getIncorrect(sample) << endl;
        cout << "Test Case:" << sample.printCode() << endl;
        cout << "Actual: " << c1.printCode() << endl;
    }   

}