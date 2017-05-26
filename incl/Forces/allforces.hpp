#ifndef ALLFORCES_HPP
#define ALLFORCES_HPP
#include <vector>
#include "Forces/force.hpp"
#include "Particles/particle.hpp"
#include "Forces/electromagnetism.hpp"
#include "Forces/Gravity.hpp"


namespace AllForces{
    void setForces(std::vector<Particle> parts, bool reset);
}


#endif
