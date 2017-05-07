#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include <vector>

class Particle{
private:
    double m_mass;    //Mass in eV/c^2
    double m_charge;  //Charge in eV
    bool m_anti;
    bool m_position_set;
    std::vector<double> m_position;

public:
    Particle(double mass, double charge)
        : m_mass(mass), m_charge(charge), m_position_set(false) {}
    Particle() : m_position_set(false) {}
    double getMass();
    double getCharge();
    void setProperties(double mass, double charge, bool antiparticle = false);
    void printParticle();
    void setPosition(double x, double y, double z);
    std::vector<double> getPosition();
    bool checkPosition();
};

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
#endif
