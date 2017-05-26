#include "Forces/Gravity.hpp"

//Create functions that return a function that evaluates to the gravitational
// force between two bodies
double Gravity::Force(double mass1, double mass2, double distance){
    double f = G*mass1*mass2*(-1) / distance*distance;
    return f;
}

MathFunction* Gravity::Force(Star* s1, Star* s2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*s1->GetMass()*s2->GetMass()*(-1));
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}
MathFunction* Gravity::Force(Particle* p1, Particle* p2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*p1->getMass()*p2->getMass()*(-1));
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}

std::vector<double> Gravity::ForceVec(Particle* p1, Particle* p2){
    std::vector<double> f = Utility::zeroVec();
    int i;
    for( i = 0; i < 3; i++) {
        f[i] = p2->getPosition(i) - p1->getPosition(i);
        f[i] = G*p1->getMass()*p2->getMass()/(f[i]*f[i])*(-1);
    }
    return f;
}
