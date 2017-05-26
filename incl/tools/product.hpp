#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <vector>
#include <string>

#include "mathfunction.hpp"
#include "exponential.hpp"
#include "polynomial.hpp"
// #include "trig.hpp"
#include "utility.hpp"

class Product : public MathFunction{
private:
  MathFunction* m_f1;
  MathFunction* m_f2;

public:
    //Constructors
    Product(MathFunction* f1, MathFunction* f2, string str = "Unset")
      : MathFunction(str), m_f1(f1), m_f2(f2) {}
    //Public member functions
    double Evaluate(double value);
    void PrintFunc();
};


#endif
