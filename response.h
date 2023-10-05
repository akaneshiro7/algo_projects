#pragma once

#include <vector>
#include <iostream>

class response {
    public:
    response(int corr, int incorr);
    void setResponse(int corr, int incorr);
    vector<int> getResponse();

    // overloading of == and <<
    friend bool operator==(const repsponse &lhs, const response &rhs);
    friend ostream& operator<<(ostream& ostr, const response& r);

    private:
    int correct, incorrect;

};