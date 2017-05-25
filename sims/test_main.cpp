#include "Tests/FunctionTests.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "tools/mathfunction.hpp"
#include "tools/polynomial.hpp"
#include "tools/product.hpp"



int main() {
    bool check = FTests::TestPolynomialProduct();
    if(check) std::cout << "\nPolynommial has passed test\n";
    else std::cout << "\nPolynommial has failed test\n";
    return(1);
}
