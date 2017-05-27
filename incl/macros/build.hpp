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
    Box* box(int N = 100, int T = 100, double timestep = 1E-5, double L = 10E3);
}

#endif
