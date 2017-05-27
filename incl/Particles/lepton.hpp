#ifndef LEPTON_HPP
#define LEPTON_HPP

#include <iostream>
#include <cstdlib>

#include "Forces/force.hpp"
#include "Particles/particle.hpp"
// class Force;
// class Particle;

class Lepton : public Particle{
private:
    int m_generation;
    void Electron(bool antiparticle = false);
    void Muon(bool antiparticle = false);
    void Tau(bool antiparticle = false);
    void Neutrino(bool antiparticle = false);

public:

    Lepton(int gen, std::string tag = "Lepton", bool neutrino = false, bool antiparticle = false)
        : Particle(tag), m_generation(gen) {
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

#endif
