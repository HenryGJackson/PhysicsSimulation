#include "tools/vectfunction.hpp"

std::vector<double> VectFunction::Evaluate(std::vector<double> pos) {
    std::vector<double> F;
    F.push_back(m_xFunc->Evaluate(pos[0]));
    F.push_back(m_yFunc->Evaluate(pos[1]));
    F.push_back(m_zFunc->Evaluate(pos[2]));
    return F;
}

void VectFunction::SetFunc(int i, MathFunction* f){
    try{
        if(i == 0) {
            m_xFunc = f;
            return;
        }
        else if(i == 1) {
            m_yFunc = f;
            return;
        }
        else if(i == 2) {
            m_zFunc = f;
            return;
        }
        else throw 1;
    }
    catch(int e) {
        std::cout << "Index Error to VectFunction::SetFunc(int, MathFunction*)\n";
        exit(EXIT_FAILURE);
    }
    return;
}

void VectFunction::SetFunc(MathFunction* x, MathFunction* y, MathFunction* z) {
    m_xFunc = x;
    m_yFunc = y;
    m_zFunc = z;
    return;
}
