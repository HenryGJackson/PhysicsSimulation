#include "Particles/particle.hpp"


void Particle::setProperties(double mass, double charge, bool antiparticle){
    m_mass = mass;
    m_charge = charge;
    m_anti = antiparticle;
    return;
}

double Particle::getMass(){  return m_mass;  }
double Particle::getCharge(){  return m_charge;  }
void Particle::printParticle(){ std::cout << "Mass: " << getMass() << " eV/c^2\nCharge: " << getCharge() << " eV\n";}
void Particle::setPosition(double x, double y, double z) {
    m_position.resize(3);
    m_position[0] = x;
    m_position[1] = y;
    m_position[2] = z;
    m_position_set = true;
    return;
}
std::vector<double> Particle::getPosition(){ return m_position; }
bool Particle::checkPosition(){ return m_position_set; }
