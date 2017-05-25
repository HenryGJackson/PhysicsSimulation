#ifndef MAINSEQUENCE_HPP
#define MAINSEQUENCE_HPP

#include <iostream>
#include <vector>
#include "tools/utility.hpp"
#define StefBoltz 5.67036713E-8

class Star{
private:
    double m_mass; // mass in solar masses
    double m_radius; //radius in solar radii
    double m_lum;  // luminosity in solar luminosities
    double m_temp;
    double m_msTime;
    std::vector<double> m_position;
    std::vector<double> m_velocity;

public:
    void SetLuminosity();
    void SetTemperature();
    void SetMsLifetime();
    double GetMass();
    Star(double mass, std::vector<double> pos, std::vector<double> vel)
      : m_mass(mass), m_position(pos), m_velocity(vel){
        SetLuminosity();
        SetTemperature();
        SetMsLifetime();
    }
};



#endif
