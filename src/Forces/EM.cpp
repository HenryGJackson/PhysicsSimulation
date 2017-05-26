#include "Forces/electromagnetism.hpp"


//Returns the magnitude of the coulomb force between p1 and p2
std::vector<double> Coulomb::Force(Particle p1, Particle p2){
    std::vector<double> force;
    int i;
    double numerator = p1.getCharge()*p2.getCharge()*k;
    for(i = 0; i < 3; i++) {
      force.push_back(p2.getPosition(i) - p1.getPosition(i));
      force[i] = numerator/(force[i]*force[i]); }
    return force;
}

//Returns the Acceleration of p1 due to the coulomb force between it and p2
std::vector<double> Coulomb::Acceleration(Particle p1, Particle p2){
    int i;
    std::vector<double> a = Coulomb::Force(p1, p2);
    for(i = 0; i < 3; i++) { a[i] = a[i]/p1.getMass(); }
    return a;
}

void Coulomb::setForces(std::vector<Particle> parts, bool reset){
      unsigned int i, j;
      std::vector<double> f, f2;
      if(reset){
          for( i = 0; i < parts.size(); i++) {
              parts[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < parts.size(); i++ ) {
          for(j = i+1; j < parts.size(); j++) {
              f = Coulomb::Force(parts[i],parts[j]);
              f2 = Coulomb::Force(parts[j],parts[i]);
              parts[i].addToForce(f);
              parts[j].addToForce(f2);
          }
          parts[i].getForce()->calcMag();
      }
      return;
}
