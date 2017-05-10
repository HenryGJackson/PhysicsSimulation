#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "mathfunction.hpp"
#include "polynomial.hpp"
#include "utility.hpp"
using namespace std;

class Exponential : public MathFunction{
private:
    MathFunction* m_exponent;
    MathFunction* m_fcoeff;
    bool m_funct_coeff;
    double m_dcoeff;
public:
    Exponential(MathFunction* exponent, double coeff) : MathFunction("Unset"),
        m_exponent(exponent), m_fcoeff(NULL),
        m_funct_coeff(false), m_dcoeff(coeff) {};
    Exponential(MathFunction* exponent, MathFunction* coeff) : MathFunction("Unset"),
        m_exponent(exponent), m_fcoeff(coeff),
        m_funct_coeff(true) {};
    // void Differentiate();
    string GetTag();
    bool CheckStatus();
    virtual double Evaluate(double value);
    virtual void PrintFunc();
};
void Exponential::PrintFunc(){
  std::cout << "Exponential";
  return;
}
string GetTag() {
    return "expo";
}
bool Exponential::CheckStatus() {
    if(!m_exponent) return false;
    return true;
}

double Exponential::Evaluate(double value){
  if(m_funct_coeff) {
      return m_fcoeff->Evaluate(value)*exp(m_exponent->Evaluate(value));
  }
  else {
      return m_dcoeff*exp(m_exponent->Evaluate(value));
  }
}

// void Exponential::Differentiate() {
//     // If the exponent is differentiable then multiply the coefficient
//     // by its derivative
//     if(m_exponent->check_differentiable()){
//         MathFunction *tmp = *m_exponent;
//         tmp->Differentiate();
//         if(m_funct_coeff) {
//             m_fcoeff->Multiply(MathFucntion tmp);
//         }
//         else m_fcoeff->Multiply(tmp);
//     }
//     if(m_funct_coeff) {
//         tmp* =
//     return;
//
//     if(m_funct_coeff) {
//
//             if(tmp->CheckStatus()) {
//
//             }
//         }
//     }
//     else
//     return;
// }




#endif
