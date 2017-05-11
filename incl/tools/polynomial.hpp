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



#endif
