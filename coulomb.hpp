#ifndef COULOMB_HPP
#define COULOMB_HPP

#include <vector>

#include "particle.hpp"
#include "utility.hpp"

#define PI 3.1415926

namespace Coulomb{
    std::vector<double> Force(Particle p1, Particle p2);
    std::vector<double> Acceleration(Particle p1, Particle p2);
}

//Returns the magnitude of the coulomb force between p1 and p2
std::vector<double> Coulomb::Force(Particle p1, Particle p2){
    std::vector<double> force = Utility::DistanceVec(p1, p2);
    double q1 = p1.getCharge();
    double q2 = p2.getCharge();
    int i;
    double numerator = q1*q2;
    for(i = 0; i < 3; i++) { force[i] = numerator/(force[i]*force[i]); }
    return force;
}

//Returns the Acceleration of p1 due to the coulomb force between it and p2
std::vector<double> Coulomb::Acceleration(Particle p1, Particle p2){
    int i;
    std::vector<double> a = Coulomb::Force(p1, p2);
    for(i = 0; i < 3; i++) { a[i] = a[i]/p1.getMass(); }
    return a;
}



#endif
