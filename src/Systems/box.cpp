#include "Systems/box.hpp"


void Box::MoveParticlesAll(){
    int j;
    if(Interactions()) {
      if(Interactions() == 1) setForceNoEM(true);
      else if(Interactions() == 2) setForceNoGrav(true);
      else if(Interactions() == 3) setForceAll(true);
    }
    else setForceNoInts(true);
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
  else if(m_boundType == 3) m_particles[j]->CheckBoundsP(3,0.0);

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

int Box::Interactions() {
  return m_ints;
}
//Set forces using all forces (Gravity,electromagnetic,external)
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

//Set forces using all forces (Gravity,electromagnetic,external)
void Box::setForceNoEM(bool reset){
    int i, j;
    std::vector<double> g, g2;
    int len = m_particles.size();
    if(reset){
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                g = Gravity::ForceVec(m_particles[i],m_particles[j]);
                g2 = Gravity::ForceVec(m_particles[j],m_particles[i]);
                if(i!=0) {
                   if(j!=1) m_particles[i]->addToForce(g);
                   else m_particles[i]->setForce(g[0], g[1], g[2]);
                   m_particles[j]->addToForce(g2);
                }
                else{
                  m_particles[i]->setForce(g[0], g[1], g[2]);
                  m_particles[j]->setForce(g2[0], g2[1], g2[2]);
                }
                m_particles[i]->addToForce(
                    EvalForce( m_particles[i]->getPosition(),
                               m_particles[i]->getMass() ) );
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
                g = Gravity::ForceVec(m_particles[i],m_particles[j]);
                g2 = Gravity::ForceVec(m_particles[j],m_particles[i]);
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

void Box::setForceNoGrav(bool reset){
    int i, j;
    std::vector<double> c, c2;
    int len = m_particles.size();
    if(reset){
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                c = Magnet::Force(m_particles[i],m_particles[j], m_BField);
                c2 = Magnet::Force(m_particles[j],m_particles[i], m_BField);
                if(i!=0) {
                   if(j!=1) m_particles[i]->addToForce(c);
                   else m_particles[i]->setForce(c[0], c[1], c[2]);
                   m_particles[j]->addToForce(c2);
                }
                else{
                  m_particles[i]->setForce(c[0], c[1], c[2]);
                  m_particles[j]->setForce(c2[0], c2[1], c2[2]);
                }
                m_particles[i]->addToForce(
                    EvalForce( m_particles[i]->getPosition(),
                               m_particles[i]->getMass() ) );
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
                m_particles[i]->addToForce(c);
                m_particles[j]->addToForce(c2);
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

void Box::setForceNoInts(bool reset){
    int i, j;
    std::vector<double> c, c2;
    int len = m_particles.size();
    if(reset){
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                c = EvalForce( m_particles[i]->getPosition(),
                           m_particles[i]->getMass() );
                c2 = EvalForce( m_particles[j]->getPosition(),
                           m_particles[i]->getMass() );
                if(i!=0) {
                   if(j!=1) m_particles[i]->addToForce(c);
                   else m_particles[i]->setForce(c[0], c[1], c[2]);
                   m_particles[j]->addToForce(c2);
                }
                else{
                  m_particles[i]->setForce(c[0], c[1], c[2]);
                  m_particles[j]->setForce(c2[0], c2[1], c2[2]);
                }
            }
            m_particles[i]->getForce()->calcMag();
        }
    }
    else{
        for( i = 0; i < len; i++ ) {
            for(j = i+1; j < len; j++) {
                c = EvalForce( m_particles[i]->getPosition(),
                           m_particles[i]->getMass() );
                c2 = EvalForce( m_particles[j]->getPosition(),
                           m_particles[i]->getMass() );
                m_particles[i]->addToForce(c);
                m_particles[j]->addToForce(c2);
            }
            m_particles[i]->getForce()->calcMag();
        }
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
