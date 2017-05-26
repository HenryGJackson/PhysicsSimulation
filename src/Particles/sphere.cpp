#include "Particles/sphere.hpp"

void Sphere::CalcVolume(){
    m_volume = 4.0*0.33333333333 * PI * m_radius*m_radius*m_radius;
    return;
}

void Sphere::CalcDensity(){
    m_density = getMass()/m_volume;
    return;
}

void Sphere::SetRadius(double rad){
    m_radius = rad;
    CalcVolume();
    CalcDensity();
}
