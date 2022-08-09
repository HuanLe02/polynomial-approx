#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>
#include <cassert>

#include "../include/quadrature.hpp"

// main program
int main(int argc, char** argv) {
  
  const int num_integrate_intervals = 10000000;
  const double tolerance = 1e-8;

  std::function<double(double)> testFunc1 = [](double x) -> double { return cos(x); };
  std::function<double(double)> testFunc2 = [](double x) -> double { return exp(x); };
  
  // test 1
  double defInt1 = midpointIntegrate(testFunc1, 2000, 1000, num_integrate_intervals);
  double trueResult1 = sin(1000) - sin(2000);
  double err1 = abs(defInt1 - trueResult1);
  assert(err1 < tolerance);
  printf("Passed test 1\n");

  // test 2
  double defInt2 = midpointIntegrate_TwoFuncs(testFunc1, testFunc2, -100, 1, num_integrate_intervals);
  double trueResult2 = 0.5*M_E*(sin(1) + cos(1)) - (0.5/exp(100))*(cos(100)-sin(100));
  double err2 = abs(defInt2 - trueResult2);
  assert(err2 < tolerance);
  printf("Passed test 2\n");

  return 0;
}
