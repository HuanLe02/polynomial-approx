#include <cstdio>
#include <cmath>

#include "quadrature.hpp"

// test function
double testFunc(double x) {
  return sin(x);
}

// main program
int main(int argc, char** argv) {
  
  double a = 0, b = 1;
  int num_integrate_intervals = 1000000;
  double defInt = midpointIntegrate(&testFunc, 2000, 1000, num_integrate_intervals);

  printf("%f\n", defInt);


  return 0;
}
