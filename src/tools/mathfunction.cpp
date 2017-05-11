#include "tools/mathfunction.hpp"

void MathFunction::PrintFunc(){
    std::cout << "UNSET FUNCTION";
    return;
}
double MathFunction::Evaluate(double val){
    return val;
}
// Return false if value is not in the domain of the function, true otherwise
bool MathFunction::ValInDomain(double val) {
    if(!restricted_domain) return true;
    else {
        if(val < m_domain[0] || val > m_domain[1]) return false;
    }
    return true;
}
