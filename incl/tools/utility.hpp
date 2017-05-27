#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

// class Particle;

namespace Utility{
    std::vector<double> CrossProd(std::vector<double> a, std::vector<double> b);
    double Magnitude(std::vector<double> vect);
    void PrintVector(int ind, std::string title, std::vector<double> v);
    double RaiseToPower(double value, int power);
    double RaiseToPower(double value, double power);
    std::vector<double> zeroVec();
}


#endif
