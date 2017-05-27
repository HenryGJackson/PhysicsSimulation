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
#include "Particles/sphere.hpp"
#include "Systems/box.hpp"

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
    unsigned int N, T, i; //Number of particles, Number of Timesteps, index
    double timestep = 1E-3; //length of each timestep
    double L = 10E3;        //Length of the sides of the box
    std::vector<Particle> particles;  //Vector of N particles
    Force *force;
    std::vector<double> B;
    B.push_back(0.0); B.push_back(0.0); B.push_back(1.0);
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
                particles.push_back(Sphere(50,1.0E-1,1.0));
                // part->ConvertUnits(true);
                particles[i].setPosition(double(rand())/RAND_MAX*L,
                    double(rand())/RAND_MAX*L,double(rand())/RAND_MAX*L);
                force = new Force(zeroVec);
                particles[i].setForce(force);
            }
            // for(i = N*0.5; i < N; i++) {
            //     particles.push_back(Sphere(1,-1.0,1.0));
            //     // part->ConvertUnits(true);
            //     particles[i].setPosition(double(rand())/RAND_MAX*L,
            //         double(rand())/RAND_MAX*L,double(rand())/RAND_MAX*L);
            //     force = new Force(zeroVec);
            //     particles[i].setForce(force);
            // }
        }
        else throw argc;
    }
    catch(int a) { std::cout << a << " Is Too Many Arguments...\n"; exit(EXIT_FAILURE); }
    //Create Box
    Box *b = new Box(particles, L, T, timestep);
    b->setBField(B);
    //Run Simulation
    b->Go();

    for(i = 0; i < N; i++) {
        delete particles[i].getForce();
    }

}
