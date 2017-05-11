#ifndef MAINSEQUENCE_HPP
#define MAINSEQUENCE_HPP

#include <iostream>
#define StefBoltz 5.67036713E-8

class Star{
private:
    double m_mass; // mass in solar masses
    double m_radius; //radius in solar radii
    double m_lum;  // luminosity in solar luminosities
    double m_temp;
    double m_msTime;
    vector<double> m_position;
    vector<double> m_velocity;

public:
    void SetLuminosity();
    void SetTemperature();
    void SetMsLifetime();
    Star(double mass, vector<double> pos, vector<double> vel) 
      : m_mass(mass), m_position(pos), m_velocity(vel){
        SetLuminosity();
        SetTemperature();
        SetMsLifetime();
    }
}

void Star::SetLuminosity() {
    if(m_mass < 0.43) {
        m_lum = 0.23*Utility::RaiseToPower(m_mass, 2.3);
    }
    else if(m_mass < 2.0) {
        m_lum = Utility::RaiseToPower(m_mass, 4);
    }
    else if(m_mass < 20) {
        m_lum = 1.5*Utility::RaiseToPower(m_mass, 3.5);
    }
    else {
        m_lum = 3200*m_mass;
    }
    return;
}

void Star::SetTemperature() {
    m_temp = Utility::RaiseToPower(m_lum/m_radius*m_radius, 0.25);
    return;
}

void Star::SetMsLifetime() {
    m_msTime = Utility::RaiseToPower(m_mass, -2.5);
    return;
}

void Star::GetNextStage() {

}
