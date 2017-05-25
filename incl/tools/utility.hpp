#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>


// class Particle;

namespace Utility{
    double Magnitude(std::vector<double> vect);
    double RaiseToPower(double value, int power);
    double RaiseToPower(double value, double power);
    std::vector<double> zeroVec();
}


#endif
