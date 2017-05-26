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
    bool m_funct_coeff;
    // bool m_differentiable;

public:
    //Constructors
    Polynomial(int n_terms, vector<double> powers, vector<double> coeffs,
      string var = "Unset") : MathFunction(var), m_zero(false), m_tag("poly"),
      m_num_terms(n_terms), m_powers(powers), m_coeffs(coeffs),
      m_funct_coeff(false) { /*check_differentiable();*/ }
    //Public member functions
    bool CheckStatus();
    // void Differentiate();
    double Evaluate(double value);
    string GetTag();
    // void Integrate(double x, double integralVal);
    void PrintFunc();
    void setCoeffs(vector<double> coeffs);

};





#endif
