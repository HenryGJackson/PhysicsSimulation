#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "tools/mathfunction.hpp"
#include "tools/exponential.hpp"
#include "tools/polynomial.hpp"
#include "tools/product.hpp"
#include "tools/utility.hpp"
#include "AstroObjects/MainSequence.hpp"
#include "Particles/particle.hpp"
#include "Particles/lepton.hpp"
#include "Particles/baryon.hpp"

#define G 6.67408E-11
class Particle;

namespace Gravity{
    double Force(double mass1, double mass2, double distance);
    MathFunction* Force(Star* s1, Star* s2);
    MathFunction* Force(Particle* p1, Particle* p2);
    std::vector<double> ForceVec(Particle* p1, Particle* p2);
    void setForces(std::vector<Particle> parts);
}



#endif
