#ifndef BOX_HPP
#define BOX_HPP


#include "tools/utility.hpp"
#include "Particles/particle.hpp"
#include "Forces/Gravity.hpp"
#include "Forces/electromagnetism.hpp"
#include "tools/vectfunction.hpp"
#include "Particles/sphere.hpp"
#include "Particles/lepton.hpp"

class Box : public Object{
private:
    std::vector<Particle*> m_particles;   //The particles in the box
    double m_timestep; //Duration of one timesttep
    double L;    //Length of the one side of the box
    int T;       //Number of timesteps
    int N;       //Number of particles
    int m_ints;  //Interaction code
                 // 1: Gravity 2: EM 3: Gravity + EM 0: Neither
    std::vector<double> m_BField; //Magnetic field vector
    int m_boundType;    //Boundary conditions type code
    VectFunction* m_extForce; //External force as a function of posisitions
    bool m_forceExists;   //Tells whether a magnetic force is present

public:
    //Construct/Destruct
    Box(std::vector<Particle*> part, double len, int numsteps,
      double timestep, int bType = 0, int ints = 1, std::string id = "Box") :
        Object(id), m_particles(part), m_timestep(timestep), L(len), T(numsteps),
        m_ints(ints), m_boundType(bType){
        setBField(Utility::zeroVec());
        N = part.size();
        m_forceExists = false;
        return;
    }
    virtual ~Box(){
        int i;
        for(i = 0; i < N; i++) {
            delete m_particles[i];
            // delete m_particles[i].getForce();
        }
        std::cout << "Deleted Forces\n";
        delete m_extForce;
        std::cout << "Deleted Box\n";
        return;
    }
    //Public member funcs
    void CheckBounds(int j);
    void EarthGravity();
    std::vector<double> EvalForce(std::vector<double> pos, double mass);
    Particle* GetParticle(int i);
    void Go();
    int Interactions();
    void MoveParticlesAll();
    void Print();
    void setBField(std::vector<double> B);
    void setExtForce(VectFunction* f);
    void setForceAll(bool reset);
    void setForceNoEM(bool reset);
    void setForceNoGrav(bool reset);
    void setForceNoInts(bool reset);

};

#endif
