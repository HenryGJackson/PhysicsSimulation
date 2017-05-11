#include "tools/product.hpp"

double Product::Evaluate(double value) {
    return m_f1->Evaluate(value)*m_f2->Evaluate(value);
}

void Product::PrintFunc(){
  std::cout << "(";
  m_f1->PrintFunc();
  std::cout << ")(";
  m_f2->PrintFunc();
  std::cout << ")";
  return;
}
