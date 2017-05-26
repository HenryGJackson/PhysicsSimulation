#ifndef BOX_HPP
#define BOX_HPP
#include "Particles/particle.hpp"
#include "Forces/Gravity.hpp"
#include "Forces/electromagnetism.hpp"

class Box{
private:
    std::vector<Particle> m_particles;
    double m_timestep;
    double L;
    int T;
    int N;
    int m_boundType;

public:
    Box(std::vector<Particle> part, double len, int numsteps,
      double timestep, int bType = 0) : m_particles(part),
      m_timestep(timestep), L(len), T(numsteps), m_boundType(bType) {
        N = part.size();
        return;
    }
    void CheckBounds(int j);
    Particle* GetParticle(int i);
    void Go();
    void MoveParticlesGrav();
    void MoveParticlesEM();
    void MoveParticlesAll();
    void Print();
    void setForceAll(bool reset);
    void setForcesEM(bool reset);
    void setForcesGrav(bool reset);
};

#endif
