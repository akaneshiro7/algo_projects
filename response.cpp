#include "response.h"
#include <iostream>
#include <vector>

response::response(int corr, int incorr) {
    setResponse(corr, incorr);
};

// sets the response to the given parameters
void response::setResponse(int corr, int incorr) {
    correct = corr;
    incorrect = incorr;
};

// gets the correct, incorrect response and returns as a vector
vector<int> response::getResponse() {
    vector<int> temp {correct, incorrect};
    return temp; 
};

bool operator==(const response& lhs, const response& rhs) {
    return (lhs.correct == rhs.correct && lhs.);
};

ostream& operator<< (ostream& ostr, const response& r) {
    ostr << r.correct << ", " << r.incorrect;
    return ostr;
};