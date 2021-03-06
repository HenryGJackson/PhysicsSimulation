#ifndef HADRON_HPP
#define HADRON_HPP

#include <iostream>
#include <cstdlib>

#include "Particles/particle.hpp"

class Hadron : public Particle{
private:
    int m_bnum;
    bool m_baryon;
    void Neutron(bool antiparticle = false);
    void Proton(bool antiparticle = false);


public:
    //Constructors
    Hadron(int bnum, double mass, double charge, std::string id = "Hadron")
      : Particle(mass, charge, id), m_bnum(bnum){
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


#endif
