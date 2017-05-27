#ifndef VECTFUNCTION_HPP
#define VECTFUNCTION_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include "tools/mathfunction.hpp"

class VectFunction {
private:
    MathFunction* m_xFunc;
    MathFunction* m_yFunc;
    MathFunction* m_zFunc;

public:
    VectFunction(MathFunction* x, MathFunction* y, MathFunction* z)
      : m_xFunc(x), m_yFunc(y), m_zFunc(z) {}
    VectFunction() {}

    std::vector<double> Evaluate(std::vector<double> pos);
    void SetFunc(int i, MathFunction* f);
    void SetFunc(MathFunction* x, MathFunction* y, MathFunction* z);
};

#endif
