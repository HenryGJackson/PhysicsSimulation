#include <iostream>
#include <cstdlib>

#include "obj.hpp"
#include "macros/build.hpp"


void WelcomeMessage();
void Menu();

int main(int argc, char* argv[]){
    WelcomeMessage();
    std::string str;
    Object* m_map;

    m_map = Build::box();
    m_map->Go();
    delete m_map;
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
              << "|*                     By                       *|\n"
              << "|*                Henry Jackson                 *|\n"
              << "|************************************************/\n";
    return;
}

void Menu() {
    std::cout << "/************************************************|\n"
              << "|*                  -- Menu --                  *|\n"
              << "|*  (1): Box(A,B,C,D)                           *|\n"
              << "|*                     By                       *|\n"
              << "|*                Henry Jackson                 *|\n"
              << "|************************************************/\n";
}
