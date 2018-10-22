#include <iostream>

#include "Lambdas.h"
#include "FunctionalTypes.h"
#include "DelegateConstructor.h"
#include "Constructors.h"
#include "References.h"

int main() {
    Lambdas::run();
    FunctionalTypes::run();
    DelegateConstructor::run();
    Constructors::run();
    References::run();
    return 0;
}