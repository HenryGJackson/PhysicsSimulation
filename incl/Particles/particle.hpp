#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

#include "obj.hpp"
#include "Forces/force.hpp"
#include "tools/utility.hpp"

class Particle : public Object{
private:
    double m_mass;    //Mass in eV/c^2
    double m_charge;  //Charge in eV
    bool m_anti;
    bool m_position_set;
    std::vector<double> m_position;
    std::vector<double> m_velocity;
    Force *m_force;

public:
    //Constructors
    Particle(double mass, double charge, std::string id = "Particle")
        : Object(id), m_mass(mass), m_charge(charge), m_position_set(false),
          m_velocity(Utility::zeroVec()) { }
    Particle(std::string id = "Particle") : Object(id), m_position_set(false), m_velocity(Utility::zeroVec()) {}
    //Public Memeber Functions
    void addToForce(std::vector<double> f);
    void takeFromForce(std::vector<double> f);
    bool checkBoundsA(double L);
    void checkBoundsB(double L);
    bool checkPosition();
    void ConvertUnits(bool toSI = true);
    double getCharge();
    Force* getForce();
    double getMass();
    std::vector<double> getPosition();
    double getPosition(int i);
    std::vector<double> getVelocity();
    double getVelocity(int i);
    void Move(double timestep);
    void printParticle();
    void ReverseVel(int i);
    void setProperties(double mass, double charge, bool antiparticle = false);
    void setPosition(double x, double y, double z);
    void setForce(Force *f);
    void setForce(double x, double y, double z);
    // ~Particle() { delete m_force; }


};

namespace Part{
    double DistanceMag(Particle p1, Particle p2);
    std::vector<double> DistanceVec(Particle p1, Particle p2);
}

#endif
