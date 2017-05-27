#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class Object{
private:
    std::string m_tag;

public:
    Object(std::string tag) : m_tag(tag) {}
    virtual ~Object() {}
    std::string GetTag();
    virtual void Go();
};


#endif
