#include "Forces/electromagnetism.hpp"


//Returns the magnitude of the coulomb force between p1 and p2
std::vector<double> Coulomb::Force(Particle p1, Particle p2){
    std::vector<double> force;
    double q1 = p1.getCharge();
    double q2 = p2.getCharge();
    int i;
    double numerator = q1*q2*k;
    for(i = 0; i < 3; i++) {
      force.push_back(p1.getPosition(i) - p2.getPosition(i));
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
      std::vector<double> f;
      if(reset){
          for( i = 0; i < parts.size(); i++) {
              parts[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < parts.size(); i++ ) {
          for(j = i+1; j < parts.size(); j++) {
              f = Coulomb::Force(parts[i],parts[j]);
              parts[i].addToForce(f);
              parts[j].addToForce(f);
          }
          parts[i].getForce()->calcMag();
      }
      return;
}
