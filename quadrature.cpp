#include <cassert>
#include "quadrature.hpp"

// function to estimate definite integral w/ midpoint rule
// takes in pointer of a single-variable real-valued function
double midpointIntegrate(double (*func)(double), double from, double to, int num_intervals) {
  // check conditions
  assert(num_intervals >= 1);

  // form the intervals
  double intervalWidth = (to - from) / num_intervals;
  double sum = 0.0;

  // calculate areas
  for (int i = 0; i < num_intervals; i++) {
    // get midpoint, calculate value
    double midpoint = from + i*intervalWidth + (intervalWidth / 2);
    double height = func(midpoint);
    double area = height * intervalWidth;
    sum += area;
  }

  return sum;
}
