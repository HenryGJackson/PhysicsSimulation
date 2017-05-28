#ifndef BUILD_HPP
#define BUILD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "obj.hpp"
#include "tools/utility.hpp"
#include "Forces/force.hpp"
#include "Particles/particle.hpp"
#include "Particles/lepton.hpp"
#include "Forces/Gravity.hpp"
#include "Particles/sphere.hpp"
#include "Systems/box.hpp"

namespace Build{
    Box* PutInBox(std::vector<Particle*> particles, int BCs = 1,  int T = 100, double timestep = 1E-5, double L = 10E3);
    std::vector<Particle*> SphereRandParts(int N = 100, double L = 10E3);
}

#endif
