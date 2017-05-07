#ifndef LEPTON_HPP
#define LEPTON_HPP

#include <iostream>
#include <cstdlib>

#include "particle.hpp"

class Lepton : public Particle{
private:
    int m_generation;
    void Electron(bool antiparticle = false);
    void Muon(bool antiparticle = false);
    void Tau(bool antiparticle = false);
    void Neutrino(bool antiparticle = false);

public:
    Lepton(int gen, bool neutrino = false, bool antiparticle = false)
        : Particle(), m_generation(gen) {
            try { if(gen < 1 || gen > 3) throw gen; }
            catch(int e) { std::cout << "Incorrect generation number: " << gen << std::endl; exit(EXIT_FAILURE); }
            if(neutrino) Neutrino(antiparticle);
            else {
                if(gen == 1) Electron(antiparticle);
                else if(gen == 2) Muon(antiparticle);
                else Tau(antiparticle);
            }
            return;
        }


};
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

#endif
