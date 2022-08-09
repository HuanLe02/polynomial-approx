#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>
#include <cassert>

#include "include/orthogonalProjection.hpp"

// test functions
double testFunc2(double x) { return exp(x); }

// main program
int main(int argc, char** argv) {
  
  // test functions
  std::function<double(double)> testFunc1 = [](double x) -> double { return sin(x); };
  
  // test 1
  Polynomial p = orthoProjection(testFunc1, 5, -M_PI, M_PI);
  printf("Test 1: f = sin(x), n = 5, interval [-pi,pi]\n");
  printf("Best polynomial: %s\n\n", &p.toString()[0]);

  // test 2
  p = orthoProjection(&testFunc2, 4, -8, 2);
  printf("Test 1: f = e^x, n = 4, interval [-8,2]\n");
  printf("Best polynomial: %s\n\n", &p.toString()[0]);
  
  return 0;
}
