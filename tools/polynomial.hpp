#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include "mathfunction.hpp"
#include "utility.hpp"
using namespace std;

class Polynomial : public MathFunction{
private:
    bool m_zero;
    string m_tag;
    int m_num_terms;
    vector<double> m_powers;
    vector<double> m_coeffs;
    const bool m_funct_coeff;
    // bool m_differentiable;

public:
    Polynomial(int n_terms, vector<double> powers, vector<double> coeffs,
      string var = "Unset") : MathFunction(var), m_tag("poly"), m_funct_coeff(false),
      m_num_terms(n_terms), m_powers(powers), m_coeffs(coeffs),
      m_zero(false) { /*check_differentiable();*/ }
    double Evaluate(double value);
    // void Differentiate();
    // void Integrate(double x, double integralVal);
    string GetTag();
    void PrintFunc();
    bool CheckStatus();
};

bool Polynomial::CheckStatus() {
    if(m_zero) return true;
    return false;
}

double Polynomial::Evaluate(double value) {
    if(!m_zero) {
      if(ValInDomain(value)) {
          int i;
          double result = 0.0;
          for(i = 0; i < m_num_terms; i ++) {
              result += m_coeffs[i]*Utility::RaiseToPower(value, m_powers[i]);
          }
          return result;
      }
    }
    else return 0;
}

string Polynomial::GetTag() {
    return m_tag;
}

void Polynomial::PrintFunc() {
    int i;
    for (int i = 0; i < m_num_terms; i++) {
        if(i > 0 && m_coeffs[i] > 0) std::cout << " + ";
        else std::cout << " ";
        std::cout << m_coeffs[i] << "x^" << m_powers[i];
    }
    return;
}

// void Polynomial::Differentiate() {
//     if(!m_zero) {
//       int i;
//       int zero_count = 0;
//       int power_count;
//       for(i = 0; i < m_num_terms; i ++) {
//           if(m_coeffs[i] == 0) {
//               zero_count ++;
//               continue;
//           }
//           else if (m_powers[i] == 0) {
//               power_count ++;
//               continue;
//           }
//           m_coeffs[i] = m_coeffs[i]*m_powers[i];
//           m_powers[i] --;
//       }
//       if(zero_count >= m_num_terms) m_zero = true;
//       if(power_count >= m_num_terms) {
//           m_tag = "const";
//           m_differentiable = false;
//           //Retain information so that integration remembers information about the constant
//           // for(i = 0; i < m_num_terms; i ++) {
//       }
//     }
//     return;
// }
//
// // Check if differentiable and set m_differentiable
// bool Polynomial::check_differentiable() {
//     if(m_zero || m_num_terms < 1) {
//         m_differentiable = false;
//         return false;
//     }
//     count = 0;
//     for(i = 0; i < m_num_terms; i ++) {
//         count += m_powers[i];
//     }
//     if(count > 0) {
//         m_differentiable = true;
//         return true;
//     }
//     m_differentiable = false;
//     return false;
// }
//
// void Polynomial::Integrate(double x, double integralVal){
//     int i;
//     if(m_tag = "const") {
//         for(i = 0; i < m_num_terms; i ++) {
//
//     }
//     for(i = 0; i < m_num_terms; i ++) {
//         m_powers[i] ++;
//         m_coeffs[i] = m_coeffs[i] / m_powers[i];
//     }
//     c = integralVal - Evaluate(x);
//     m_num_terms ++;
//     m_powers.push_back(0);
//     m_coeffs.push_back(c);
//     return;
// }





#endif
