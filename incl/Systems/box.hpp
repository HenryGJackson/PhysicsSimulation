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
    std::vector<Particle*> m_particles;
    double m_timestep;
    double L;
    int T;
    int N;
    std::vector<double> m_BField;
    int m_boundType;
    VectFunction* m_extForce;
    bool m_forceExists;

public:
    //Construct/Destruct
    Box(std::vector<Particle*> part, double len, int numsteps,
      double timestep, int bType = 0, std::string id = "Box") : Object(id),
      m_particles(part), m_timestep(timestep), L(len), T(numsteps),
      m_boundType(bType){
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
    void MoveParticlesGrav();
    void MoveParticlesEM();
    void MoveParticlesAll();
    void Print();
    void setBField(std::vector<double> B);
    void setExtForce(VectFunction* f);
    void setForceAll(bool reset);
    void setForcesEM(bool reset);
    void setForcesGrav(bool reset);
};

#endif
