//
// Created by dpp on 10/9/18.
//

#include "Constructors.h"

#include <iostream>
#include <cstring>

namespace {

    class ClassT {

    private:
        static const int SIZE = 100;

        int* buffer;

    public:

        ClassT() {
            std::cout << "Default constructor" << std::endl;
            buffer = new int[SIZE]();
        }

        ClassT(int i) {
            std::cout << "Parametrized constructor" << std::endl;
        }

        ClassT(const ClassT& classT) {
            std::cout << "Copy constructor" << std::endl;
        }

        ClassT& operator=(const ClassT& classT) {
            std::cout << "Assignemnt" << std::endl;
            return *this;
        }

        ~ClassT() {
            std::cout << "Destructor" << std::endl;
            delete [] buffer;
        }

        friend std::ostream &operator<<(std::ostream& out, const ClassT& classT);
    };

}

void Constructors::run() {
    std::cout << "CONSTRUCTORS" << std::endl;

    ClassT t1;
//    ClassT t2 = t1;

    std::cout << std::endl;
}