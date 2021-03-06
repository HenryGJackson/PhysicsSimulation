#ifndef MATHFUNCTION_HPP
#define MATHFUNCTION_HPP

#include <vector>
#include <string>

#include "utility.hpp"
using namespace std;


class MathFunction{

private:
    bool restricted_domain;
    // bool m_differentiable = true;
    vector<double> m_domain;
    string variable;

public:
    //Constructors
    MathFunction(string str) : restricted_domain(false), variable(str) {}
    MathFunction(string str, vector<double> dom)
      : restricted_domain(true), variable(str) {
          try {if(dom.size() != 2) throw 1;}
          catch(int e) {
              std::cout << "Domain must be a vector of length 2: dom(min, max)\n";
              exit(EXIT_FAILURE);
          }
      }
    virtual ~MathFunction() {}
    //Public Member Functions
    virtual double Evaluate(double val);
    string GetTag();
    virtual void PrintFunc();
    bool ValInDomain(double val);

};



#endif
