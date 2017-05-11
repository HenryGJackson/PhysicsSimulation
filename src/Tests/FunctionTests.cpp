#include "Tests/FunctionTests.hpp"

// Tests that a polynomial and a factorised version as a
// product evaluate to the same value
using namespace FTests;
bool FTests::TestPolynomialProduct() {

      std::vector<double> powers;
      powers.push_back(0); powers.push_back(1); powers.push_back(2);
      std::vector<double> coeffs;
      coeffs.push_back(1); coeffs.push_back(2); coeffs.push_back(1);
      MathFunction* poly = new Polynomial(3,powers,coeffs);
      poly->PrintFunc();
      std::cout << "\n";
      std::vector<double> p1;
      p1.push_back(1); p1.push_back(0);
      std::vector<double> p2;
      p2.push_back(1); p2.push_back(0);
      std::vector<double> c1;
      c1.push_back(1); c1.push_back(1);
      std::vector<double> c2;
      c2.push_back(1); c2.push_back(1);
      MathFunction* poly1 = new Polynomial(2,p1,c1);
      MathFunction* poly2 = new Polynomial(2,p2,c2);
      Product* prod = new Product(poly1, poly2);
      srand((unsigned)time(0));
      int i;
      double val, diff;
      for(i = 0; i < 10; i++) {
          val = double(rand());
          diff = poly->Evaluate(val) - prod->Evaluate(val);
          diff = diff/poly->Evaluate(val);
          std::cout << "(" << val << ") " <<
           poly->Evaluate(val) << " = " << prod->Evaluate(val) << "\n";
          if(diff > 1E-4) return false;
      }
      prod->PrintFunc();
      std::cout << "\n";
      return(true);
}
