#include "Systems/box.hpp"

void Box::MoveParticlesGrav(){
    int j;
    setForcesGrav(true);
    for(j = 0; j < N; j++) {
        // std::cout  << "\rMovement Progress: " << j << "/" << N
        //     << "                      " << std::flush;
        m_particles[j]->Move(m_timestep);
        CheckBounds(j);
    }
    return;
}

void Box::MoveParticlesEM(){
    int j;
    setForcesEM(true);
    for(j = 0; j < N; j++) {
        // std::cout  << "\rMovement Progress: " << j << "/" << N
        //     << "                      " << std::flush;
        m_particles[j]->Move(m_timestep);
        CheckBounds(j);
    }
    return;
}


void Box::MoveParticlesAll(){
    int j;
    setForceAll(true);
    for(j = 0; j < N; j++) {
        // std::cout  << "\rMovement Progress: " << j << "/" << N
        //     << "                      " << std::flush;
        m_particles[j]->Move(m_timestep);
        CheckBounds(j);
    }
    return;
}

void Box::CheckBounds(int j){
  if(m_boundType == 1) m_particles[j]->checkBoundsB(L);
  else if(m_boundType == 2) {
      if(!m_particles[j]->checkBoundsA(L)) {
        m_particles.erase(m_particles.begin()+j);
        N -= 1;
      }
  }
  return;
}


Particle* Box::GetParticle(int i){
    return m_particles[i];
}

void Box::Print() {
  int i;
  for(i = 0; i < N; i++) {
      Utility::PrintVector(i, "Position", m_particles[i]->getPosition());
      Utility::PrintVector(i, "Velocity", m_particles[i]->getVelocity());
      std::cout << i << " - ";
      m_particles[i]->getForce()->Print();
  }
}

//Run simulation for T timesteps
void Box::Go(){
  int i;
  Print();
  for(i = 0; i < T; i++) {
      // std::cout << "\nTimestep: " << i << "/" << T << ".\n";
      MoveParticlesAll();
  }
  Print();
  return;
}

//Set forces using all forces (Gravity,Coulomb)
void Box::setForceAll(bool reset){
    int i, j;
    std::vector<double> c, c2;
    std::vector<double> g, g2;
    int len = m_particles.size();
    if(reset){
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                c = Magnet::Force(m_particles[i],m_particles[j], m_BField);
                c2 = Magnet::Force(m_particles[j],m_particles[i], m_BField);
                g = Gravity::ForceVec(m_particles[i],m_particles[j]);
                g2 = Gravity::ForceVec(m_particles[j],m_particles[i]);
                if(i!=0) {
                   if(j!=1) m_particles[i]->addToForce(c);
                   else m_particles[i]->setForce(c[0], c[1], c[2]);
                   m_particles[j]->addToForce(c2);
                }
                else{
                  m_particles[i]->setForce(c[0], c[1], c[2]);
                  m_particles[j]->setForce(c2[0], c2[1], c2[2]);
                }
                m_particles[i]->addToForce(g);
                m_particles[i]->addToForce(
                    EvalForce( m_particles[i]->getPosition(),
                               m_particles[i]->getMass() ) );
                m_particles[j]->addToForce(g2);
                m_particles[j]->addToForce(
                      EvalForce( m_particles[j]->getPosition(),
                                 m_particles[i]->getMass() ) );
            }
            m_particles[i]->getForce()->calcMag();
        }
    }
    else{
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                c = Magnet::Force(m_particles[i],m_particles[j], m_BField);
                c2 = Magnet::Force(m_particles[j],m_particles[i], m_BField);
                g = Gravity::ForceVec(m_particles[i],m_particles[j]);
                g2 = Gravity::ForceVec(m_particles[j],m_particles[i]);
                m_particles[i]->addToForce(c);
                m_particles[j]->addToForce(c2);
                m_particles[i]->addToForce(g);
                m_particles[j]->addToForce(g2);
                m_particles[i]->addToForce(
                  EvalForce( m_particles[j]->getPosition(),
                             m_particles[i]->getMass() ) );
                m_particles[j]->addToForce(
                  EvalForce( m_particles[j]->getPosition(),
                             m_particles[i]->getMass() ) );
            }
            m_particles[i]->getForce()->calcMag();
        }
    }
    return;
}

void Box::setForcesEM(bool reset){
      int i, j;
      std::vector<double> f, f2;
      int len = m_particles.size();
      if(reset){
          for( i = 0; i < len; i++) {
              m_particles[i]->setForce(0,0,0);
          }
      }
      for( i = 0; i < len; i++ ) {
          for(j = i+1; j < len; j++) {
              f = Coulomb::Force(m_particles[i],m_particles[j]);
              f2 = Coulomb::Force(m_particles[j],m_particles[i]);
              m_particles[i]->addToForce(f);
              m_particles[j]->addToForce(f2);
          }
          m_particles[i]->getForce()->calcMag();
      }
      return;
}

void Box::setForcesGrav(bool reset){
      int i, j;
      std::vector<double> f, f2;
      int len = m_particles.size();
      if(reset){
          for( i = 0; i < len; i++) {
              m_particles[i]->setForce(0,0,0);
          }
      }
      for( i = 0; i < len; i++ ) {
          for(j = i+1; j < len; j++) {
              f = Gravity::ForceVec(m_particles[i],m_particles[j]);
              f2 = Gravity::ForceVec(m_particles[j],m_particles[i]);
              m_particles[i]->addToForce(f);
              m_particles[j]->addToForce(f);
          }
          m_particles[i]->getForce()->calcMag();
      }
      return;
}

//Set the vector of the external B field
void Box::setBField(std::vector<double> B){
    m_BField = B;
    return;
}

//Set the function for the external force
void Box::setExtForce(VectFunction* f){
    m_forceExists = true;
    m_extForce = f;
    return;
}

//Evaluate the value of the external force at pos
std::vector<double> Box::EvalForce(std::vector<double> pos, double mass){
    std::vector<double> f;
    if(m_forceExists) {
      f = m_extForce->Evaluate(pos);
      f = Utility::MultiplyVector(f, mass);
    }
    else f = Utility::zeroVec();
    return f;
}

void Box::EarthGravity(){
    std::vector<double> p, c;
    p.push_back(0.0);
    c.push_back(0.0);
    MathFunction* xy = new Polynomial(1,p,c);
    c.clear();
    c.push_back(9.81);
    MathFunction* z = new Polynomial(1,p,c);
    VectFunction* xyz = new VectFunction(xy, xy, z);
    setExtForce(xyz);
}
