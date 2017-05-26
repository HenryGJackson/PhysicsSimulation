#include "Forces/force.hpp"

void Force::setMag(double mag){ m_magnitude = mag; return; }
void Force::setDir(std::vector<double> dir){ m_direction = dir; return; }
void Force::setDir(double x, double y, double z){
    m_direction[0] = x;
    m_direction[1] = y;
    m_direction[2] = z;
    calcMag();
    return;
}
void Force::calcMag(){ m_magnitude = Utility::Magnitude(m_direction); return; }
void Force::add(std::vector<double> f) {
    int i;
    for(i = 0; i < 3; i++) m_direction[i] += f[i];
    return;
}
std::vector<double> Force::getDir(){
  return m_direction;
}
double Force::getDir(int i){
  try{ if(i < 0 || i > 3) throw 1;}
  catch(int e){ std::cout << "Get Direction Index Error\n"; exit(EXIT_FAILURE);}
  return m_direction[i];
}
