#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "AstroObjects/MainSequence.hpp"

#define G 6.67408E-11

namespace Gravity{
    double Force(Star* s1, Star* s2);
}

MathFunction* Gravity::Force(Star* s1, Star* s2){
    std::vector<int> power;
    power.push_back(-2);
    std::vector<double> coeff;
    coeff.push_back(G*s1->GetMass(m_mass)*s2->GetMass(m_mass));
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
}

#ifndef
