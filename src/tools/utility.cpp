#include "tools/utility.hpp"




//Get the magnitude of the vector passed in
double Utility::Magnitude(std::vector<double> vect){
    return (vect[0]*vect[0] + vect[1]*vect[1] + vect[2]*vect[2]);
}



//Raise to an integer powers
double Utility::RaiseToPower(double value, int power){
    int tmp_pow;
    if(power == 0) return 1.0;
    else if(power < 0) tmp_pow = (-1)*power;
    else tmp_pow = power;
    int i;
    double result = 1.0;
    for(i = 0; i < tmp_pow; i ++) {
        result = result * value;
    }
    if(power < 0) return (1.0/result);
    else return result;
}

double Utility::RaiseToPower(double value, double power){
    if(value < 0) {
      int check = int(value/1.0);
      if(check != value) {
          std::cout << "WARNING: Raising " << value << " to power " << power <<
              ". Complex numbers have been disabled.\n" << check;
      }
      return RaiseToPower(value, int(power));
    }
    return exp(power*log(value));
}

std::vector<double> Utility::zeroVec(){
  std::vector<double> v;
  int i;
  for(i = 0; i < 3; i ++) v.push_back(0.0);
  return v;
}
