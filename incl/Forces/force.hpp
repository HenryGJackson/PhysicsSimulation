#ifndef FORCE_HPP
#define FORCE_HPP

#include <vector>
#include "tools/utility.hpp"

class Force{
private:
    double m_magnitude;
    std::vector<double> m_direction;

public:
    Force() : m_magnitude(0.0), m_direction(Utility::zeroVec()) {}
    Force(std::vector<double> dir)
        : m_direction(dir) { calcMag(); }
    void setMag(double mag);
    void setDir(std::vector<double> dir);
    std::vector<double> getDir();
    double getDir(int i);
    void calcMag();
    void add(std::vector<double> f);
};

#endif
