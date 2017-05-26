#ifndef BOX_HPP
#define BOX_HPP
#include "Particles/particle.hpp"
#include "Forces/Gravity.hpp"

class Box{
private:
    std::vector<Particle> m_particles;
    double m_timestep;
    double L;
    int T;
    int N;

public:
    Box(std::vector<Particle> part, double len, int numsteps, double timestep)
      : m_particles(part), m_timestep(timestep), L(len), T(numsteps) {
        N = part.size();
        return;
    }
    Particle* GetParticle(int i);
    void MoveParticles();
    void Print();
};

#endif
