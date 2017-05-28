#include <iostream>
#include <cstdlib>
#include <map>
#include "obj.hpp"
#include "macros/build.hpp"


void WelcomeMessage();
void BoxMenu();
void SimMenu();
std::map<std::string, int> GetBoxMap();
void BoxInterface(int BCs);
std::map<std::string, int> GetSimMap();


int main(int argc, char* argv[]){
    WelcomeMessage();
    std::string str;
    std::map<std::string, int> SMap = GetBoxMap();
    SimMenu();
    while(1){
        std::cin >> str;
        if(str == "quit") exit(EXIT_SUCCESS);
        if(str == "done") break;
        if(str == "help") SimMenu();
        else SMap[str] = 1;
    }
    if(SMap["BOX-BB"])  BoxInterface(1);
    if(SMap["BOX-AB"])  BoxInterface(2);
    if(SMap["BOX-NB"])  BoxInterface(0);
    if(SMap["PLANE"])   BoxInterface(3);
    // while(1) {
    //     std::cin >> str;
    //     if(str == "quit") break;
    //     else if(str == "help") Menu();
    //     else if()
    //
    //
    // }
    return(EXIT_SUCCESS);
}

void WelcomeMessage() {
    std::cout << "/************************************************|\n"
              << "|*         Welcome to PhysicsSimulation         *|\n"
              << "|*       Type 'help' for common functions       *|\n"
              << "|*  Type 'done' when finished choosing options  *|\n"
              << "|*                Henry Jackson                 *|\n"
              << "|************************************************/\n";
    return;
}
void SimMenu() {
    std::cout << "/************************************************|\n"
              << "|*                  -- Menu --                  *|\n"
              << "|*  BOX-BB: Box with bouncing boundaries.       *|\n"
              << "|*  BOX-AB: Box with absorbing boundaries.      *|\n"
              << "|*  BOX-NB: Box with no boundaries.             *|\n"
              << "|*                                              *|\n"
              << "|************************************************/\n";
}
void BoxMenu() {
    std::cout << "/************************************************|\n"
              << "|*                  -- Menu --                  *|\n"
              << "|*  - External Forces -                         *|\n"
              << "|*  EG: Earth Gravity.                          *|\n"
              << "|*                                              *|\n"
              << "|*  - Particles -                               *|\n"
              << "|*  NRS: N unit spheres with random positions,  *|\n"
              << "|*       masses and charges.                    *|\n"
              << "|*                                              *|\n"
              << "|*  CBOX: customize parameters of sim           *|\n"
              << "|************************************************/\n";
}

std::map<std::string, int> GetBoxMap(){
  std::map<std::string, int> Map;
  Map["EG"] = 0;     //Earth Gravity
  Map["NRS"] = 0;    //N spheres with random position, mass, charge
  Map["CBOX"] = 0;   //Allows customization of parameters
  return Map;
}

std::map<std::string, int> GetSimMap(){
  std::map<std::string, int> Map;
  Map["BOX-BB"] = 0;     //Box with bouncing boundaries
  Map["BOX-AB"] = 0;     //Box with absorbing boundaries
  Map["BOX-NB"] = 0;     //Box with no boundaries
  Map["PLANE"] = 0;      //Plane with a flat bottom at z = 0
  //Map["F-PLANE"] = 0;    //Plane given by a vector function
  return Map;
}

void BoxInterface(int BCs){
  BoxMenu();
  int T = 100;
  double timestep = 1E-5;
  double L = 10E3;
  int N = 100;
  int ints = 1;
  std::map<std::string, int> BMap = GetBoxMap();
  std::string str;
  while(1){
      std::cin >> str;
      if(str == "quit") exit(EXIT_SUCCESS);
      if(str == "done") break;
      if(str == "help") BoxMenu();
      BMap[str] = 1;
  }
  Box* box;
  std::vector<Particle*> parts;
  if(BMap["NRS"]) parts = Build::SphereRandParts(N, L);
  else {
    std::cout << "No Sphere Set Selected.\n";
    exit(EXIT_FAILURE);
  }
  if(BMap["CBOX"]) {
      std::cout << "Number of Timesteps:     "; std::cin >> T;
      std::cout << "Length of each timestep: "; std::cin >> timestep;
      std::cout << "Length of each side:     "; std::cin >> L;
      std::cout << "Number of particles:     "; std::cin >> N;
      std::cout << "Allowed Interactions:    \n"
                << "1: Gravity      2: EM \n"
                << "3: Gravity + EM 0: None.."; std::cin >> ints;
  }
  box = Build::PutInBox(parts, BCs, T, timestep, L, ints);
  if(BMap["EG"]) box->EarthGravity();
  box->Go();
  delete box;
}
