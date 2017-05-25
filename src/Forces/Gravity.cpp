#include "Forces/Gravity.hpp"

//Create functions that return a function that evaluates to the gravitational
// force between two bodies
MathFunction* Gravity::Force(Star* s1, Star* s2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*s1->GetMass()*s2->GetMass());
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}
MathFunction* Gravity::Force(Particle* p1, Particle* p2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*p1->getMass()*p2->getMass());
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}
