//
// Created by dpp on 9/3/18.
//

#include "DelegateConstructor.h"

#include <iostream>

using namespace std;

namespace {

    class A{

        string str;

    public:

        A() : A("STRING") {
            cout << str << endl;
            str = "";
            cout << "CALLING CONSTRUCTOR WITHOUT PARAMETER" << endl;
        }

        A(string s)
                : str(s)
        {
            cout << "CALLING PARAMETRISED CONSTRUCTOR" <<endl;
        }

        string getStr() const {
            return str;
        }
    };
}

void DelegateConstructor::run() {

    cout << "DELEGATE CONSTRUCTOR" << endl;
    A a;
    cout << "Str = " << a.getStr() << endl;
    cout << endl;
}