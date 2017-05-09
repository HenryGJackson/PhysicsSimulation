#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include "mathfunction.hpp"
#include "utility.hpp"
using namespace std;

class Polynomial : protected MathFunction{
private:
    bool m_zero;
    int m_num_terms;
    vector<int> m_powers;
    vector<double> m_coeffs;

public:
    Polynomial(int n_terms, vector<int> powers, vector<double> coeffs,
      string str = "Unset") : MathFunction(str),
      m_num_terms(n_terms), m_powers(powers), m_coeffs(coeffs), m_zero(false) {}
    double Evaluate(double value);
    void Differentiate();
    void Integrate(double x, double integralVal);
};

double Polynomial::Evaluate(double value) {
    if(ValInDomain(value)) {
        int i;
        double result = 0.0;
        for(i = 0; i < n_terms; i ++) {
            result += m_coeffs[i]*Utility::RaiseToPower(value, m_powers[i]);
        }
        return result;
    }
}

void Polynomial::Differentiate() {
    int i;
    int zero_count = 0;
    for(i = 0; i < m_num_terms; i ++) {
        if(m_coeffs[i] == 0 || m_powers[i] == 0) {
            zero_count ++;
            continue;
        }
        m_coeffs[i] = m_coeffs[i]*m_powers[i];
        m_powers[i] --;
    }
    if(zero_count >= m_num_terms) m_zero = true;
    return;
}

void Polynomial::Integrate(double x, double integralVal){
    int i;
    int zero_count = 0;
    for(i = 0; i < m_num_terms; i ++) {
        m_powers[i] ++;
        m_coeffs[i] = m_coeffs[i] / m_powers[i];
    }
    c = integralVal - Evaluate(x);
    m_num_terms ++;
    m_powers.push_back(0);
    m_coeffs.push_back(c);
    return;
}

#endif
