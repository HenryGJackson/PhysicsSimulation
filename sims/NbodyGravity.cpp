
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "tools/utility.hpp"
#include "Forces/force.hpp"
#include "Particles/particle.hpp"
#include "Particles/lepton.hpp"
#include "Forces/Gravity.hpp"


//Takes at least one argument:
//    1: number of timesteps
//    1: number of Particles
//    2: type of particles type 1
//    3: proportion of particles type 1
//    4: type of particles type 2
//  etc...
// NOTE: If just one argument is given, all particles are electrons
//       If no arguments are given, 100 electrons are simulated
int main(int argc, char* argv[]){
    unsigned int N, T, i, j; //Number of particles, Number of Timesteps, index
    double timestep = 1E-3; //length of each timestep
    double L = 10.0;        //Length of the sides of the box
    std::vector<Particle> particles;  //Vector of N particles
    Force *force;
    Particle* part;
    std::vector<double> zeroVec = Utility::zeroVec();

    //Set up the problem:
    //Create N particles with random co-ordinates between 0 and L
    try{
        if(argc < 4){
            if(argc < 2) T = 100;
            else T = std::atoi(argv[1]);
            if(argc < 3) N = 100;
            else N = std::atoi(argv[2]);

            srand((unsigned)time(0));
            //Create N particles
            for(i = 0; i < N; i++) {
                part = new Lepton(1);
                // std::cout << "co-ordinates: " << x << "," << y << "," << z << std::endl;
                part->setPosition(double(rand())/RAND_MAX*L,
                    double(rand())/RAND_MAX*L,double(rand())/RAND_MAX*L);
                force = new Force(zeroVec);
                part->setForce(force);
                particles.push_back(*part);
                // delete part;
            }
        }
        else throw argc;
    }
    catch(int a) { std::cout << a << " Is Too Many Arguments...\n"; exit(EXIT_FAILURE); }

    for(i = 0; i < T; i++) {
        Gravity::setForces(particles,true);
        for(j = 0; j < N; j++) {
            particles[j].Move(timestep);
            particles[j].checkBounds(L);
            if(i == T-1) {
                std::cout << "Final Position of Particle " << j << ": ("
                          << particles[j].getPosition(0) << ", "
                          << particles[j].getPosition(1) << ", "
                          << particles[j].getPosition(2) << ")\n";
                particles[j].getForce()->Print();
            }
        }
    }

}
