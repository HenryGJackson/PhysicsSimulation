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
    //Constructors
    Exponential(MathFunction* exponent, double coeff) : MathFunction("Unset"),
        m_exponent(exponent), m_fcoeff(NULL),
        m_funct_coeff(false), m_dcoeff(coeff) {};
    Exponential(MathFunction* exponent, MathFunction* coeff) : MathFunction("Unset"),
        m_exponent(exponent), m_fcoeff(coeff),
        m_funct_coeff(true) {};
    // void Differentiate();
    //Public Member Functions
    bool CheckStatus();
    virtual double Evaluate(double value);
    string GetTag();
    virtual void PrintFunc();
};


#endif
