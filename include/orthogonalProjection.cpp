#include "innerproduct.hpp"
#include <vector>

Polynomial orthoProjection(std::function<double(double)> f, int n, double a, double b, int N) {
  // get orthonormal basis of P_n
  vector<Polynomial> orthonormalBasis = polynomialOrthonormalBasis(n, a, b, N);

  // allocate 0 polynomial with max degree n
  Polynomial p = Polynomial(n);

  // calculate orthogonal projection
  for (int i = 0; i < orthonormalBasis.size(); i++) {
    // calculate inner product of f & e_i
    Polynomial e = orthonormalBasis[i];
    std::function<double(double)> e_eval = [&e](double x) -> double { return e.evaluate(x); };
    double ip = innerProduct(f, e_eval, a, b, N);
    // add to p
    p = p.add(e.multiply(ip));
  }

  return p;
}

Polynomial orthoProjection(double (*f)(double), int n, double a, double b, int N) {
  // create std::function container
  std::function<double(double)> f_std = *f;
  // use above
  return orthoProjection(f_std, n, a, b, N);
}
