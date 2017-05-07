#include "lepton.hpp"
#include "baryon.hpp"
#include "coulomb.hpp"
#include "utility.hpp"

int main(){
    Hadron proton = Hadron(1);
    proton.printParticle();
    Lepton elect = Lepton(1);
    elect.printParticle();

    proton.setPosition(0,0,0);
    elect.setPosition(1,1,1);

    std::vector<double> force = Coulomb::Force(proton, elect);
    int i;
    for(i = 0; i < 3; i++) {std::cout << force[i] << ", ";}
    std::cout << std::endl;
    return(1);
}
