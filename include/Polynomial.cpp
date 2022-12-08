#include "Polynomial.hpp"
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstdio>

// ctor
Polynomial::Polynomial(int maxDegree) {             // placeholder of a polynomial with a certain maximal degree
  assert(maxDegree >= 0);
  this->coefficients = vector<double> (maxDegree+1, 0.0);   // blank polynomial
}

Polynomial::Polynomial(vector<double> coeffs) {    // build polynomial from a vector of coefficients
  assert(coeffs.size() != 0);
  this->coefficients = coeffs;
}

Polynomial::~Polynomial() {
  this->coefficients.clear();
}

// maximum allocated degree
int Polynomial::maxDeg() {
  return this->coefficients.size() - 1;
}

// get degree
int Polynomial::getDegree() {
  // get position of highest nonzero coefficient
  int degree = -1;
  for (int i = 0; i <= maxDeg(); i++) {
    if (getC(i) != 0.0) degree = i;
  }
  return degree;
}

// get coefficient
double Polynomial::getC(int position) {
  return this->coefficients.at(position);
}

// change coefficient
void Polynomial::changeC(int position, double newVal) {
  this->coefficients[position] = newVal;
}

// to string representation
string Polynomial::toString() {
  if (getDegree() == -1) return "0";   // if all 0's, return 0 string

  string output = "";
  for (int i = 0; i <= maxDeg(); i++) {
    double c = getC(i);
    // if coefficient is nonzero
    if (c != 0.0) {
      // add + into string if not empty
      if (output.length() > 0) output = output + " + ";
      // add coefficient to string
      output = output + "(" + to_string(c) + ")";
      // add x^i
      if (i > 0) output = output + "x^" + to_string(i);
    }
  }

  return output;
}

// print
void Polynomial::print() {
  if (getDegree() == -1) {
  	printf("0\n");
  	return;   // if all 0's, return 0 string
  }
  bool firstTerm = true;
  for (int i = 0; i <= maxDeg(); i++) {
    double c = getC(i);
    // if coefficient is nonzero
    if (c != 0.0) {
      // add + into string if not empty
      if (!firstTerm) {
      	printf(" + ");
      } else {
      	firstTerm = false;
      }
      // add coefficient to string
      printf("(%e)", c);
      // add x^i
      if (i > 0) printf("x^%d", i);
    }
  }
}

// POLYNOMIAL ARITHMETIC FUNCTIONS
// scalar multiply
Polynomial Polynomial::multiply(double a) {
  vector<double> newCoefficients = this->coefficients;
  // multiply each by a
  #pragma omp parallel for schedule(static)
  for (int i = 0; i <= maxDeg(); i++) {
    newCoefficients[i] *= a;
  }
  return Polynomial(newCoefficients);
}

// add another polynomial (same Max Degree)
Polynomial Polynomial::add(Polynomial p2) {
  // setup variables
  int higherMaxDegree = this->maxDeg();
  Polynomial result = Polynomial(higherMaxDegree);       // allocate space for new polynomial

  // add coefficients
  #pragma omp parallel for schedule(static)
  for (int i = 0; i <= higherMaxDegree; i++) {
    result.changeC(i, this->getC(i) + p2.getC(i));
  }
  
  return result;
}

// subtract by another polynomial
Polynomial Polynomial::subtract(Polynomial p2) {
  return this->add(p2.multiply(-1));
}

// evaluate using Horner's method
double Polynomial::evaluate(double x0) {
  // temp array for recursive calculation
  int n = getDegree();
  if (n < 0) return 0;
  double* temp = new double[n+1];

  // start at highest degree coefficient
  temp[n] = getC(n);
  for (int i = n-1; i >= 0; i--) {
    temp[i] = getC(i) + x0*temp[i+1];
  }

  double result = temp[0];
  delete[] temp;
  return result;
}


// STANDARD BASIS
vector<Polynomial> polynomialStandardBasis(int n) {
  assert(n > 0);

  vector<Polynomial> basis;
  for (int i = 0; i <= n; i++) {
    Polynomial temp = Polynomial(n);
    temp.changeC(i, 1.);
    basis.push_back(temp);
  }

  return basis;
}
