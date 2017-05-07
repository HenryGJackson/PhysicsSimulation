#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <iostream>
#include <cstdlib>

#include "particle.hpp"
#include "lepton.hpp"
#include "baryon.hpp"

namespace Utility{
    double DistanceMag(Particle p1, Particle p2);
    std::vector<double> DistanceVec(Particle p1, Particle p2);
    double Magnitude(std::vector<double> vect);
}

//Get the vector between p2 and p1
std::vector<double> Utility::DistanceVec(Particle p1, Particle p2){
    try{
      if(!p1.checkPosition()) throw 1;
      else if(!p2.checkPosition()) throw 2;
    }
    catch(int e){ std::cout << "Position not set for particle: " << e << std::endl; exit(EXIT_FAILURE); }
    std::vector<double> v1 = p1.getPosition();
    std::vector<double> v2 = p2.getPosition();
    int i;
    std::vector<double> diff;
    for(i = 0; i < 3; i++) { diff.push_back(v2[i] - v1[i]); }
    return (diff);
}

//Get the magnitude of the vector passed in
double Utility::Magnitude(std::vector<double> vect){
    return (vect[0]*vect[0] + vect[1]*vect[1] + vect[2]*vect[2]);
}

//Get the magnitude of the vector between p2 and p1
double Utility::DistanceMag(Particle p1, Particle p2){
    std::vector<double> diff = Utility::DistanceVec(p1, p2);
    return (Utility::Magnitude(diff));
}

#endif
