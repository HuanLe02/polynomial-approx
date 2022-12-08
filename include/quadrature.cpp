#include <cassert>
#include <omp.h>
#include "quadrature.hpp"

// function to estimate definite integral w/ midpoint rule
// takes in pointer of a single-variable real-valued function
double midpointIntegrate(std::function<double(double)> func, double from, double to, int num_intervals) {
  // check conditions
  assert(num_intervals >= 1);

  // form the intervals
  double intervalWidth = (to - from) / num_intervals;
  double sum = 0.0;

  // calculate areas
  #pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < num_intervals; i++) {
    // get midpoint, calculate value
    double midpoint = from + i*intervalWidth + (intervalWidth / 2);
    double height = func(midpoint);
    double area = height * intervalWidth;
    sum += area;
  }

  return sum;
}

// same as above, but product of 2 functions
double midpointIntegrate_TwoFuncs(std::function<double(double)> f, std::function<double(double)> g, double from, double to, int num_intervals) {
  // check conditions
  assert(num_intervals >= 1);

  // form the intervals
  double intervalWidth = (to - from) / num_intervals;
  double sum = 0.0;

  // calculate areas
  #pragma omp parallel for schedule(static) reduction(+:sum)
  for (int i = 0; i < num_intervals; i++) {
    // get midpoint, calculate value
    double midpoint = from + i*intervalWidth + (intervalWidth / 2);
    double height = f(midpoint) * g(midpoint);
    sum += height;
  }

  return sum*intervalWidth;
}
