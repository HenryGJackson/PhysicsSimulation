#ifndef MATHFUNCTION_HPP
#define MATHFUNCTION_HPP

#include <vector>
#include <string>

#include "utility.hpp"
using namespace std;


class MathFunction{

private:
    bool restricted_domain;
    // bool m_differentiable = true;
    vector<double> m_domain;
    string variable;

public:
    MathFunction(string str) : restricted_domain(false), variable(str) {}
    MathFunction(string str, vector<double> dom)
      : restricted_domain(true), variable(str) {
          try {if(dom.size() != 2) throw 1;}
          catch(int e) {
              std::cout << "Domain must be a vector of length 2: dom(min, max)\n";
              exit(EXIT_FAILURE);
          }
      }
    bool ValInDomain(double val);
    string GetTag();
    virtual double Evaluate(double val);
    virtual void PrintFunc();
};
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


#endif
