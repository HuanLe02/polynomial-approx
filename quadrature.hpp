#ifndef QUADRATURE
#define QUADRATURE

#include <functional>

// FORWARD DECLARATION OF FUNCTIONS

double midpointIntegrate(std::function<double(double)> func, double from, double to, int num_intervals);

// same as above, but product of 2 functions
double midpointIntegrate_TwoFuncs(std::function<double(double)> f, std::function<double(double)> g, double from, double to, int num_intervals);


#endif
