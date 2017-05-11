#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Particles/particle.hpp"
#include "Particles/lepton.hpp"
#include "Particles/baryon.hpp"

namespace Utility{
    double DistanceMag(Particle p1, Particle p2);
    std::vector<double> DistanceVec(Particle p1, Particle p2);
    double Magnitude(std::vector<double> vect);
    double RaiseToPower(double value, int power);
    double RaiseToPower(double value, double power);
}


#endif
