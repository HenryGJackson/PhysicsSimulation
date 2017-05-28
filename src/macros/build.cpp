#include "macros/build.hpp"

std::vector<Particle*> Build::SphereRandParts(int N, double L) {
    int i;
    Force *force;
    std::vector<double> zeroVec = Utility::zeroVec();
    std::vector<Particle*> particles;  //Vector of N particles
    srand((unsigned)time(0));
    double mass;
    double charge;
    //Create N particles
    for(i = 0; i < N; i++) {
        mass = double(rand())/RAND_MAX*100;
        charge = double(rand())/RAND_MAX*1E-20;
        particles.push_back(new Sphere(mass,charge,1.0));
        // part->ConvertUnits(true);
        particles[i]->setPosition(double(rand())/RAND_MAX*L,
            double(rand())/RAND_MAX*L,double(rand())/RAND_MAX*L);
        force = new Force(zeroVec);
        particles[i]->setForce(force);
    }
    //Change particle/box destructor
    return particles;
}

Box* Build::PutInBox(std::vector<Particle*> particles, int BCs, int T, double timestep, double L, int ints){
    std::vector<double> B;
    B.push_back(0.0); B.push_back(0.0); B.push_back(1.0);

    //Create Box
    Box *b = new Box(particles, L, T, timestep, BCs, ints, "box1");
    //Set Forces on the box

    //Set External Force

    //Set external magnetic field
    b->setBField(B);

    return b;
}
