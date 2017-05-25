#include "AstroObjects/MainSequence.hpp"

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

double Star::GetMass() { return m_mass; }

// void Star::GetNextStage() {
//
// }
