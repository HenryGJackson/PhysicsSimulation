#include "Systems/box.hpp"

void Box::MoveParticles(){
    int j;
    Gravity::setForces(m_particles,true);
    for(j = 0; j < N; j++) {
        m_particles[j].Move(m_timestep);
        m_particles[j].checkBounds(L);
    }
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
      MoveParticles();
  }
  Print();
  return;
}
