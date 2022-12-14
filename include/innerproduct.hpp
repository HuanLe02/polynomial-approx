#include "quadrature.hpp"
#include "Polynomial.hpp"
#include <vector>
#include <functional>

using namespace std;

// INTEGRAL INNER PRODUCT of 2 functions f & g, on interval [lower, upper]
double innerProduct(std::function<double(double)> f, std::function<double(double)> g, double lower, double upper, int N);

// Gram-Schmidt on a canonical basis of Pn (vector space of all polynomials with deg <= n)
// ip_lb, ip_ub are lower/upper bounds for inner product calculation
// output: orthonormal basis of Pn
vector<Polynomial> polynomialOrthonormalBasis(int n, double ip_lb, double ip_ub, int N);
