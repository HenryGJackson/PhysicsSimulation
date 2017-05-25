#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Forces/force.hpp"
#include "tools/utility.hpp"
// class Force;

class Particle{
private:
    double m_mass;    //Mass in eV/c^2
    double m_charge;  //Charge in eV
    bool m_anti;
    bool m_position_set;
    std::vector<double> m_position;
    std::vector<double> m_velocity;
    Force *m_force;

public:
    Particle(double mass, double charge)
        : m_mass(mass), m_charge(charge), m_position_set(false),
          m_velocity(Utility::zeroVec()) {}
    Particle() : m_position_set(false), m_velocity(Utility::zeroVec()) {}
    double getMass();
    double getCharge();
    void setProperties(double mass, double charge, bool antiparticle = false);
    void printParticle();
    void setPosition(double x, double y, double z);
    std::vector<double> getPosition();
    double getPosition(int i);
    bool checkPosition();
    void setForce(Force *f);
    Force* getForce();
    void addToForce(std::vector<double> f);
    void Move(double timestep);
    void checkBounds(double L);
    void ReverseVel(int i);

    // ~Particle() { delete m_force; }
};

namespace Part{
    double DistanceMag(Particle p1, Particle p2);
    std::vector<double> DistanceVec(Particle p1, Particle p2);
}

#endif
