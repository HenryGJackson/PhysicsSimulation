#ifndef ELECTROMTISM_HPP
#define ELECTROMTISM_HPP

#include <vector>

#include "Particles/particle.hpp"
#include "tools/utility.hpp"

#define PI 3.1415926
#define k 8.99E9
// Update using mathfunction class and derived.

//Better off using Maxwell Eqns???
namespace Coulomb{
    std::vector<double> Force(Particle p1, Particle p2);
    std::vector<double> Acceleration(Particle p1, Particle p2);
}
#endif
