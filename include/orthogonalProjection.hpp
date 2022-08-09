#include "Polynomial.hpp"
#include <functional>

using namespace std;


// Notation: 
//     - F: vector space of functions f:R->R that is continuous on [a,b]
//     - P_n: vector space of polynomials with degree at most n
// below are methods to find the orthogonal projection of a function f in F onto P_n. Input: f, n, [a,b]
// such projection p minimizes the norm of (p-v)   (thus the "optimal" approximation)

// for std::function
Polynomial orthoProjection(std::function<double(double)> f, int n, double a, double b);

// for traditional function pointer
Polynomial orthoProjection(double (*f)(double), int n, double a, double b);
