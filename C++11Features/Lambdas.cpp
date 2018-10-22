//
// Created by dpp on 8/30/18.
//

#include <iostream>
#include "Lambdas.h"

void Lambdas::run()
{
    std::cout << "***** THESE ARE LAMBDAS FEATURES" << std::endl;
    simpleLambda();
    std::cout << std::endl;
    mutableLambda();
    std::cout << std::endl;
}

void Lambdas::simpleLambda()
{
    std::cout << "THIS IS SIMPLE LAMBDA" << std::endl;
    void (*fun)(int, int) = [](int x, int y) {
        std::cout << "So we have an addition" << std::endl;
        std::cout << (x + y) << std::endl;
    };

    (*fun)(5,6);
}

void Lambdas::mutableLambda() {
        std::cout << "THIS IS MUTABLE LAMBDA" << std::endl;
        std::string x = "BEFORE";
        std::cout << "Before lambda x = " << x << std::endl;
        auto d = [&x]() mutable {
            x = "AFTER";

        };
        d();
        std::cout << "After lambda call x = " << x << std::endl;
}