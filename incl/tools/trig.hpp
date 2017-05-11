#ifndef TRIG_HPP
#define TRIG_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "mathfunction.hpp"
#include "polynomial.hpp"
#include "utility.hpp"

using namespace std;

#define PI 3.1415926


//Uses sine with a phase added such that sin(x) = cos(x + PI/2)
class Wave : public MathFunction{
private:
    double phase;
    MathFunction* m_theta;
    bool m_functional_theta;
public:
    Wave(bool cosine) : m_functional_theta(false){
        if(cosine = true) phase = PI*0.5;
        else phase = 0;
    }
    Wave(bool cosine, MathFunction* theta)
      : m_theta(theta), m_functional_theta(true) {
        if(cosine = true) phase = PI*0.5;
        else phase = 0;
    }
    double Evaluate(double value);
}

double Wave::Evaluate(double value){
    if(!m_functional_theta) return sin(value + phase);
    return sin(m_theta->Evaluate(value) + phase);
}
