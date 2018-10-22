//
// Created by dpp on 10/15/18.
//

#include "References.h"

#include <iostream>

using namespace std;

namespace {

    void leftSidedReference() {
        int var = 1;
        cout << "var is " << var << endl;
        int& r {var};
        cout << "r is " << r << endl;
        int x = r;
        cout << "x is " << x << endl;
        r = 2;
        cout << "x is " << x << endl;
        cout << "r is " << r << endl;
        cout << "var is " << var << endl;
        ++r;
        cout << "r is " << r << endl;
        cout << "var is " << var << endl;

        int xx = 5;
        const int& rr {xx};
        ++xx;
//        ++rr; // Can't do that

        const int xxx = 10;
//        int& rrr {xxx}; //Can't do that

        const int yy = 15;
        const int& rrrr {yy};
        cout << "yy is " << yy << endl;
        cout << "rrrr is " << rrrr << endl;


//        int& ref = 15; //Can't do that
        const int& ref = 15; //But this is allowed
    }

    void rightSidedReference() {

    }
}

void References::run() {
    cout << "************ REFERENCES ***********" << endl;
    cout << "LEFT SIDED REFERENCES" << endl;
    leftSidedReference();
    cout << "RIGHT SIDED REFERENCES" << endl;
    rightSidedReference();
    cout << endl;
}