#ifndef HADRON_HPP
#define HADRON_HPP

#include <iostream>
#include <cstdlib>

#include "particle.hpp"

class Hadron : public Particle{
private:
    int m_bnum;
    bool m_baryon;
    void Proton(bool antiparticle = false);
    void Neutron(bool antiparticle = false);

public:
    Hadron(int bnum, double mass, double charge)
      : Particle(mass, charge), m_bnum(bnum){
          if(bnum==0) m_baryon = false;
          else m_baryon = true;
    }
    Hadron(bool baryon) : Particle(), m_baryon(baryon) {}
    //Type = 0/1: Neutron/Proton
    Hadron(int baryon_type, bool antiparticle = false) : Particle(), m_baryon(true){
        try { if(baryon_type < 0 || baryon_type > 1) throw baryon_type; }
        catch(int e) { std::cout << "Incorrect generation number: " << e << std::endl; exit(EXIT_FAILURE); }
        if(baryon_type==0) Neutron(antiparticle);
        else Proton(antiparticle);
        return;
    }

};
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

#endif
