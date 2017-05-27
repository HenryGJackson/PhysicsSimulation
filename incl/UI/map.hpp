#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include "obj.hpp"

class Map {
private:
    std::map<std::string, Object> m_map;
    void BuildMap();

public:
    Map() {
        BuildMap();
    }

};
