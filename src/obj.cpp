#include "obj.hpp"

std::string Object::GetTag(){
  return m_tag;
}

void Object::Go() {
    std::cout << m_tag << " is not runnable object.\n";
    return;
}
