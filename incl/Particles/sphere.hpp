#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Particles/particle.hpp"
#define PI 3.1415926

class Sphere : public Particle{
private:
    double m_density;
    double m_volume;
    double m_radius;
    void CalcDensity();
    void CalcVolume();

public:
    Sphere(double mass, double charge, double rad)
      : Particle(mass, charge), m_radius(rad) {
          CalcVolume();
          CalcDensity();
          return;
    }
    //Set value of radius and the volume
    void SetRadius(double rad);
};

#endif
