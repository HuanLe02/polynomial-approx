#include <cmath>
#include <cstdio>
#include <vector>
#include "innerproduct.hpp"

double f(double x) {
  return sin(x);
}

double g(double x) {
  return exp(x);
}

int main() {
  double ip = innerProduct(&f, &g, 0, 1);
  printf("%.10e\n", ip);

  vector<Polynomial> e = polynomialGramSchmidt(2, 0, 1);
  for (int i = 0; i < e.size(); i++) {
    printf("%s\n", &e[i].toString()[0]);
  }
}
