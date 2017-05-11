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

#endif
