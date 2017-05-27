#include "macros/build.hpp"

Box* Build::box(int N, int T, double timestep, double L){
    int i;
    std::vector<Particle> particles;  //Vector of N particles
    Force *force;
    std::vector<double> B;
    B.push_back(0.0); B.push_back(0.0); B.push_back(1.0);
    std::vector<double> zeroVec = Utility::zeroVec();

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

    //Create Box
    Box *b = new Box(particles, L, T, timestep, 1, "box1");
    //Set Forces on the box
    std::vector<double> p, c;
    p.push_back(1.0);
    c.push_back(1E-3);
    MathFunction* ef = new Polynomial(1,p,c);
    VectFunction* eF = new VectFunction(ef, ef, ef);
    //Set External Force
    b->setExtForce(eF);
    //Set external magnetic field
    b->setBField(B);

    return b;
}
