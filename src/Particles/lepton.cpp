#include "Particles/lepton.hpp"

void Lepton::Electron(bool antiparticle){
    double charge;
    if(antiparticle) charge = 1;
    else charge = -1;
    setProperties(511E3,charge,antiparticle);
    return;
}
void Lepton::Muon(bool antiparticle){
    double charge;
    if(antiparticle) charge = 1;
    else charge = -1;
    setProperties(105.7E6,charge,antiparticle);
    return;
}
void Lepton::Tau(bool antiparticle){
    double charge;
    if(antiparticle) charge = 1;
    else charge = -1;
    setProperties(1776.82E6,charge,antiparticle);
    return;
}
void Lepton::Neutrino(bool antiparticle){
    setProperties(0.12,0,antiparticle);
    return;
}
