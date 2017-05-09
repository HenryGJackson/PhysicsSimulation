#ifndef MATHFUNCTION_HPP
#define MATHFUNCTION_HPP

#include <vector>
#include "utility.hpp"
using namespace std;
class MathFunction{
private:
    bool restricted_domain;
    vector<double> m_domain;

public:
    MathFunction() : restricted_domain(false) {}
    MathFunction(vector<double> dom) : restricted_domain(true) {
        try {if(dom.size() != 2) throw 1}
        catch(int e) {
            std::cout << "Domain must be a vector of length 2: dom(min, max)\n";
            exit(EXIT_FAILURE);
        }
    }
    bool ValInDomain(double val);
};

bool MathFunction::ValInDomain(double val) {
    if(!restricted_domain) return true;
    else {
        if(val < m_domain[0] || val > m_domain[1]) return false;
    }
}


#endif
