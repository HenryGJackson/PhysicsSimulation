#ifndef FORCE_HPP
#define FORCE_HPP

#include <vector>
#include "tools/utility.hpp"

class Force{
private:
    double m_magnitude;
    std::vector<double> m_direction;

public:
    //Constructors
    Force() : m_magnitude(0.0), m_direction(Utility::zeroVec()) {}
    Force(std::vector<double> dir)
        : m_direction(dir) { calcMag(); }
    //Public memeber Functions
    void add(std::vector<double> f);
    void calcMag();
    std::vector<double> getDir();
    double getDir(int i);
    void setDir(std::vector<double> dir);
    void setDir(double x, double y, double z);
    void setMag(double mag);

};

#endif
