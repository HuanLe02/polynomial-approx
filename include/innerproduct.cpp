#include "innerproduct.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>

double innerProduct(std::function<double(double)> f, std::function<double(double)> g, double lower, double upper, int N) {
  assert(upper > lower);
  return midpointIntegrate_TwoFuncs(f, g, lower, upper, N);
}

// Gram-Schmidt to form orthonormal basis of P_n
vector<Polynomial> polynomialOrthonormalBasis(int n, double ip_lb, double ip_ub, int N) {
  // placeholder for orthogonal basis
  vector<Polynomial> e;
  // get standard basis
  vector<Polynomial> v = polynomialStandardBasis(n);
  assert(v.size() == n+1);
  // Gram-Schmidt
  for (int i = 0; i < v.size(); i++) {
    // get current basis vector
    Polynomial p = v.at(i);
    std::function<double(double)> p_eval = [&p](double x) -> double { return p.evaluate(x); };
    // subtract projections w.r.t previous orthonomal basis vectors in workstation
    for (int j=0; j < i; j++) {
      Polynomial u = e.at(j);
      std::function<double(double)> u_eval = [&u](double x) -> double { return u.evaluate(x); };
      double ip = innerProduct(p_eval, u_eval, ip_lb, ip_ub, N);
      p = p.subtract(u.multiply(ip));
    }
    // normalize p
    double norm = sqrt(innerProduct(p_eval, p_eval, ip_lb, ip_ub, N));
    p = p.multiply(1./norm);
    e.push_back(p);
  }
  
  // clear
  v.clear();

  return e;
}
