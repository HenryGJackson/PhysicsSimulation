#include "Particles/particle.hpp"


void Particle::setProperties(double mass, double charge, bool antiparticle){
    m_mass = mass;
    m_charge = charge;
    m_anti = antiparticle;
    return;
}

double Particle::getMass(){  return m_mass;  }
double Particle::getCharge(){  return m_charge;  }
void Particle::printParticle(){ std::cout << "Mass: " << getMass() << " eV/c^2\nCharge: " << getCharge() << " eV\n";}
void Particle::setPosition(double x, double y, double z) {
    m_position.resize(3);
    m_position[0] = x;
    m_position[1] = y;
    m_position[2] = z;
    m_position_set = true;
    return;
}
std::vector<double> Particle::getPosition(){
  try{
    if(!checkPosition()) throw 1;
  }
  catch(int e) {std::cout << "Particle position not set.\n"; exit(EXIT_FAILURE); }
  return m_position;
}
double Particle::getPosition(int i){
  try{
    if(!checkPosition()) throw 1;
  }
  catch(int e) {std::cout << "Particle position not set.\n"; exit(EXIT_FAILURE); }
  return m_position[i];
}
bool Particle::checkPosition(){ return m_position_set; }
void Particle::setForce(Force *f){ m_force = f; return; }
void Particle::addToForce(std::vector<double> f) {
    m_force->add(f);
    return;
}

Force* Particle::getForce() { return m_force; }

void Particle::Move(double timestep){
    double tmp;
    int i;
     for(i = 0; i < 3; i ++){
        tmp = m_force->getDir(i) * timestep / m_mass;
        m_velocity[i] += tmp;
        tmp = m_velocity[i] * timestep;
        m_position[i] += tmp;
    }
    return;
}




//Get the vector between p2 and p1
std::vector<double> Part::DistanceVec(Particle p1, Particle p2){
    try{
      if(!p1.checkPosition()) throw 1;
      else if(!p2.checkPosition()) throw 2;
    }
    catch(int e){ std::cout << "Position not set for particle: " << e << std::endl; exit(EXIT_FAILURE); }
    std::vector<double> v1 = p1.getPosition();
    std::vector<double> v2 = p2.getPosition();
    int i;
    std::vector<double> diff;
    for(i = 0; i < 3; i++) { diff.push_back(v2[i] - v1[i]); }
    return (diff);
}

//Get the magnitude of the vector between p2 and p1
double Part::DistanceMag(Particle p1, Particle p2){
    std::vector<double> diff = DistanceVec(p1, p2);
    return (Utility::Magnitude(diff));
}
