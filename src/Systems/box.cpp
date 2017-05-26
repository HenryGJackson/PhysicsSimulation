#include "Systems/box.hpp"

void Box::MoveParticlesGrav(){
    int j;
    setForcesGrav(true);
    for(j = 0; j < N; j++) {
        std::cout  << "\rMovement Progress: " << j << "/" << N
            << "                      " << std::flush;
        m_particles[j].Move(m_timestep);
        m_particles[j].checkBounds(L);
    }
    return;
}

void Box::MoveParticlesEM(){
    int j;
    setForcesEM(true);
    for(j = 0; j < N; j++) {
        std::cout  << "\rMovement Progress: " << j << "/" << N
            << "                      " << std::flush;
        m_particles[j].Move(m_timestep);
        m_particles[j].checkBounds(L);
    }
    return;
}

void Box::MoveParticlesAll(){
    int j;
    setForceAll(true);
    for(j = 0; j < N; j++) {
        std::cout  << "\rMovement Progress: " << j << "/" << N
            << "                      " << std::flush;
        m_particles[j].Move(m_timestep);
        m_particles[j].checkBounds(L);
    }
    return;
}

Particle* Box::GetParticle(int i){
    return &m_particles[i];
}

void Box::Print() {
  int i;
  for(i = 0; i < N; i++) {
      std::cout << "Position of Particle " << i << ": ("
                << m_particles[i].getPosition(0) << ", "
                << m_particles[i].getPosition(1) << ", "
                << m_particles[i].getPosition(2) << ")\n";
      m_particles[i].getForce()->Print();
  }
}

void Box::Go(){
  int i;
  for(i = 0; i < T; i++) {
      std::cout << "\nTimestep: " << i << "/" << T << ".\n";
      MoveParticlesAll();
  }
  Print();
  return;
}

void Box::setForceAll(bool reset){
      int i, j;
      std::vector<double> c, c2;
      std::vector<double> g, g2;
      int len = m_particles.size();
      if(reset){
          for( i = 0; i < len; i++) {
              m_particles[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < len; i++ ) {
          for(j = i+1; j < len; j++) {
              c = Coulomb::Force(m_particles[i],m_particles[j]);
              c2 = Coulomb::Force(m_particles[j],m_particles[i]);
              g = Gravity::ForceVec(&m_particles[i],&m_particles[j]);
              g2 = Gravity::ForceVec(&m_particles[j],&m_particles[i]);
              m_particles[i].addToForce(c);
              m_particles[i].addToForce(g);
              m_particles[j].addToForce(c2);
              m_particles[j].addToForce(g2);
          }
          m_particles[i].getForce()->calcMag();
      }
      return;
}

void Box::setForcesEM(bool reset){
      int i, j;
      std::vector<double> f, f2;
      int eslen = m_particles.size();
      if(reset){
          for( i = 0; i < len; i++) {
              m_particles[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < len; i++ ) {
          for(j = i+1; j < len; j++) {
              f = Coulomb::Force(m_particles[i],m_particles[j]);
              f2 = Coulomb::Force(m_particles[j],m_particles[i]);
              m_particles[i].addToForce(f);
              m_particles[j].addToForce(f2);
          }
          m_particles[i].getForce()->calcMag();
      }
      return;
}

void Box::setForcesGrav(bool reset){
      int i, j;
      std::vector<double> f, f2;
      int len = m_particles.size();
      if(reset){
          for( i = 0; i < len; i++) {
              m_particles[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < len; i++ ) {
          for(j = i+1; j < len; j++) {
              f = Gravity::ForceVec(&m_particles[i],&m_particles[j]);
              f2 = Gravity::ForceVec(&m_particles[j],&m_particles[i]);
              m_particles[i].addToForce(f);
              m_particles[j].addToForce(f);
          }
          m_particles[i].getForce()->calcMag();
      }
      return;
}
