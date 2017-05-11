#include "tools/exponential.hpp"

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
