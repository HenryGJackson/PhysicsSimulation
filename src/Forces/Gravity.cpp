#include "Forces/Gravity.hpp"

//Create functions that return a function that evaluates to the gravitational
// force between two bodies
double Gravity::Force(double mass1, double mass2, double distance){
    double f = G*mass1*mass2 / distance*distance;
    return f;
}

MathFunction* Gravity::Force(Star* s1, Star* s2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*s1->GetMass()*s2->GetMass());
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}
MathFunction* Gravity::Force(Particle* p1, Particle* p2){
    std::vector<double> power;
    power.push_back(double(-2));
    std::vector<double> coeff;
    coeff.push_back(G*p1->getMass()*p2->getMass());
    MathFunction* force = new Polynomial(1,power,coeff,"Force");
    return force;
}

std::vector<double> Gravity::ForceVec(Particle* p1, Particle* p2){
    std::vector<double> f = Utility::zeroVec();
    int i;
    for( i = 0; i < 3; i++) {
        f[i] = p1->getPosition(i) - p2->getPosition(i);
        f[i] = G*p1->getMass()*p2->getMass()/(f[i]*f[i]);
    }
    return f;
}

void Gravity::setForces(std::vector<Particle> parts){
      unsigned int i, j;
      std::vector<double> f;
      for( i = 0; i < parts.size(); i++ ) {
          for(j = i+1; j < parts.size(); j++) {
              f = Gravity::ForceVec(&parts[i],&parts[j]);
              parts[i].addToForce(f);
              parts[j].addToForce(f);
          }
          parts[i].getForce()->calcMag();
      }
      return;
}
