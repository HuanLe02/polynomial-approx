#include <cstdio>
#include <cassert>
#include <vector>
#include "../include/Polynomial.hpp"

using namespace std;

// test 1
void test1() {
  Polynomial p1 = Polynomial(5);
  assert(p1.getDegree() == -1);
  printf("test1 - checkpoint1: %s\n", &p1.toString()[0]);
  p1.changeC(0, -2);
  assert(p1.getDegree() == 0);
  p1.changeC(2, 3);
  assert(p1.getDegree() == 2);
  p1.changeC(5, 1);
  assert(p1.getDegree() == 5);
  assert(p1.getC(0) == -2);
  assert(p1.getC(4) == 0);

  Polynomial p2 = p1.multiply(3);
  for (int i = 0; i < 5; i++) {
    assert(p2.getC(i) == 3. * p1.getC(i));
  }
  printf("test1 - checkpoint2: %s\n", &p2.toString()[0]);
  assert(p1.maxDeg() == 5 && p2.maxDeg() == 5);
}

// test 2
void test2() {
  Polynomial p1 = Polynomial(10);
  p1.changeC(9, 1.5);
  p1.changeC(2, -3);
  Polynomial p2 = Polynomial(14);
  p2.changeC(0, 1);
  p2.changeC(2, 3);
  p2.changeC(12, 1);
  Polynomial p3 = p1.add(p2);
  Polynomial p4 = p1.subtract(p2);
  printf("test2 - checkpoint1: %s\n", &(p3).toString()[0]);
  printf("test2 - checkpoint2: %s\n", &(p4).toString()[0]);
  assert(p4.evaluate(2) == -3353);
  printf("test2 - checkpoint3: %f\n", p4.evaluate(2));

}

// test 3
void test3() {
  int n = 4;
  vector<Polynomial> basis = polynomialCanonicalBasis(n);
  for (int i = 0; i < basis.size(); i++) {
    Polynomial p = basis[i];
    printf("test3 - checkpoint1: %s\n", &p.toString()[0]);
  }
  printf("test3 - checkpoint2: %s\n", &(basis[0].add(basis[2])).toString()[0]);
  printf("test3 - checkpoint2: %s\n", &(basis[2].add(basis[4])).toString()[0]);
}

int main(int argc, char** argv) {
  test1();
  test2();
  test3();  
}

