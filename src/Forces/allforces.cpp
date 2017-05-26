#include "Forces/allforces.hpp"


void AllForces::setForces(std::vector<Particle> parts, bool reset){
      unsigned int i, j;
      std::vector<double> c, c2;
      std::vector<double> g, g2;
      if(reset){
          for( i = 0; i < parts.size(); i++) {
              parts[i].setForce(0,0,0);
          }
      }
      for( i = 0; i < parts.size(); i++ ) {
          for(j = i+1; j < parts.size(); j++) {
              c = Coulomb::Force(parts[i],parts[j]);
              c2 = Coulomb::Force(parts[j],parts[i]);
              g = Gravity::ForceVec(&parts[i],&parts[j]);
              g2 = Gravity::ForceVec(&parts[j],&parts[i]);
              parts[i].addToForce(c);
              parts[i].addToForce(g);
              parts[j].addToForce(c2);
              parts[j].addToForce(g2);
          }
          parts[i].getForce()->calcMag();
      }
      return;
}
