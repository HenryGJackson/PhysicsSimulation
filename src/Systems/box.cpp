#include "Systems/box.hpp"

void Box::MoveParticlesGrav(){
    int j;
    Gravity::setForces(m_particles,true);
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
    Coulomb::setForces(m_particles,false);
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
    AllForces::setForces(m_particles,true);
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
