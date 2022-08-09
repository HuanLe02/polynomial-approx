#include <vector>
#include <string>

using namespace std;

// Polynomial class:
// support addition, subtraction, scalar multiplication, transform into native C++ function
class Polynomial {
  protected:
    vector<double> coefficients;    // coefficients, order from lowest degree term to highest degree term

  public:
    // ctor & dtor
    Polynomial(int n);
    Polynomial(vector<double> coeffs);
    ~Polynomial();

    // maximum degree allocated
    int maxDeg();
    
    // get degree of polynomial
    int getDegree();

    // get coefficient
    double getC(int position);

    // change new coefficient
    void changeC(int position, double newVal);

    // print polynomial as string
    string toString();

    // add another polynomial (p + p2)
    Polynomial add(Polynomial p2);
    
    // subtract by another polynomial (p - p2)
    Polynomial subtract(Polynomial p2);

    // multiply by a scalar
    Polynomial multiply(double a);

    // evaluate at x0
    double evaluate(double x0);
};


// return a canonical basis of vector space Pn (polynomials with degree <= n). Pn has dimension n+1
// input: n - specify vector space Pn
// output: a vector of Polynomials
vector<Polynomial> polynomialCanonicalBasis(int n);
