//
// Created by dpp on 9/3/18.
//

#include "FunctionalTypes.h"

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

namespace {

    bool fun(int number)
    {
        return number >= 5;
    }

    class Functor{
    public:
        bool operator()(int number) {
            return number <= 4;
        }
    } func;

    void runFunction(function<bool(int)> checkIf)
    {
        int number = 3;
        cout << checkIf(number) << endl;
    }
}

void FunctionalTypes::run() {
    cout << "***** PRESENTATION OF FUNCTIONAL TYPES" << endl;
    countingByFunctionPointer();
    countingByLambda();
    countingByFunctor();
    callFunctionTemplate();
    cout << endl;
}

void FunctionalTypes::countingByLambda() {
    cout << "Counting by Lambda" << endl;
    const int size = 6;
    vector<int> vec {5,6,3,7,1,2,5,6};

    cout << count_if(vec.begin(), vec.end(), [size](int number) {return number >=size; }) << endl;
}

void FunctionalTypes::countingByFunctionPointer() {

    cout << "Counting by Pointer to function" << endl;

    vector<int> vec {5,6,3,7,1,2,5,6};

    cout << count_if(vec.begin(), vec.end(), fun) << endl;
}

void FunctionalTypes::countingByFunctor() {
    cout << "Counting by Functor" << endl;

    vector<int> vec {5,6,3,7,1,2,5,6};

    cout << count_if(vec.begin(), vec.end(), func) << endl;
}

void FunctionalTypes::callFunctionTemplate() {
    cout << "Using function template" << endl;
    const int size = 5;
    auto lambda = [size](int number) {return number <= size; };
    runFunction(lambda);
    runFunction(fun);
    runFunction(func);
}