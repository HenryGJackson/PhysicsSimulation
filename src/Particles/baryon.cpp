#include "Particles/baryon.hpp"

void Hadron::Proton(bool antiparticle) {
    double charge;
    if(antiparticle) charge = -1;
    else charge = 1;
    setProperties(938.28E6,charge,antiparticle);
    return;
}
void Hadron::Neutron(bool antiparticle) {
    setProperties(939.57E6,0.0,antiparticle);
    return;
}
