#include "Polynomial.hpp"
#include <cassert>
#include <algorithm>
#include <cmath>

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

// POLYNOMIAL ARITHMETIC FUNCTIONS
// scalar multiply
Polynomial Polynomial::multiply(double a) {
  vector<double> newCoefficients = this->coefficients;
  // multiply each by a
  for (int i = 0; i <= maxDeg(); i++) {
    newCoefficients[i] *= a;
  }
  return Polynomial(newCoefficients);
}

// add another polynomial
Polynomial Polynomial::add(Polynomial p2) {
  // setup variables
  bool p1HigherMaxDegree = (this->maxDeg() >= p2.maxDeg());
  int higherMaxDegree = max(this->maxDeg(), p2.maxDeg());
  int lowerMaxDegree = min(this->maxDeg(), p2.maxDeg());
  Polynomial result = Polynomial(higherMaxDegree);       // allocate space for new polynomial

  // add coefficients
  for (int i = 0; i <= higherMaxDegree; i++) {
    // if within range of both polynomials, then simply add coefficients
    if (i <= lowerMaxDegree) {
      result.changeC(i, this->getC(i) + p2.getC(i));
    }
    else {   // if out of range, no adding needed
      if (p1HigherMaxDegree) result.changeC(i, this->getC(i));    // take on coefficient of this polynomial
      else result.changeC(i, p2.getC(i));    // take on coefficient of p2
    }
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


// CANONICAL BASIS
vector<Polynomial> polynomialCanonicalBasis(int n) {
  assert(n > 0);

  vector<Polynomial> basis;
  for (int i = 0; i <= n; i++) {
    Polynomial temp = Polynomial(n);
    temp.changeC(i, 1.);
    basis.push_back(temp);
  }

  return basis;
}
