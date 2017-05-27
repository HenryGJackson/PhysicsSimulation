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
    ~VectFunction() {
        if(m_xFunc == m_yFunc){
          if(m_xFunc != m_zFunc) delete m_zFunc;
          delete m_xFunc;
        }
        else if(m_xFunc == m_zFunc){
          delete m_xFunc;
          delete m_yFunc;
        }
        else if(m_yFunc == m_zFunc){
          delete m_xFunc;
          delete m_yFunc;
        }
        else{
          delete m_xFunc;
          delete m_zFunc;
          delete m_yFunc;
        }
        std::cout << "Deleted VectFunction\n";
        return;
    }
    std::vector<double> Evaluate(std::vector<double> pos);
    void SetFunc(int i, MathFunction* f);
    void SetFunc(MathFunction* x, MathFunction* y, MathFunction* z);
};

#endif
