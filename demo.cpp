#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <chrono>

#include "include/innerproduct.hpp"
#include "include/orthogonalProjection.hpp"

using namespace std::chrono;




// test functions
double testFunc(double x) { return pow(1.2,x)*cos(x)*log(x+1);}

// main program
int main(int argc, char** argv) {
  
  // test functions
  // std::function<double(double)> testFunc1 = [](double x) -> double { return sin(x); };
  
  // test 1
  //Polynomial p = orthoProjection(testFunc1, 5, -M_PI, M_PI);
  //printf("Test 1: f = sin(x), n = 5, interval [-pi,pi]\n");
  // printf("Best polynomial: %s\n\n", &p.toString()[0]);

  assert(argc >=3);

  // test 2
  double a = 0.0, b= 10.0;
  int n = atoi(argv[1]);
  int N = atoi(argv[2]);
  
  // time function (in ms)
  auto start = high_resolution_clock::now();
  Polynomial p = orthoProjection(&testFunc, n, a, b, N);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  
  // print info
  printf("n = %d, N = %d, P = %d\n", n, N, atoi(getenv("OMP_NUM_THREADS")));

  if (argc == 4) {
  	char flag = argv[3][0];
  	
  	// print polynomial
  	if (flag == 'P' || flag == 'A') {
  		printf("Best polynomial: ");
  		p.print();
  		printf("\n");
  	}
  
  	// error evaluation
  	if (flag == 'E' || flag == 'A') {
	  	std::function<double(double)> f_minus_p = [&p](double x) -> double { return testFunc(x)-p.evaluate(x); };
  		printf("Error: %.3e\n", sqrt(innerProduct(f_minus_p, f_minus_p, a, b, 100000000)));
  	}
  	
  	// print time
  	if (flag == 'T' || flag == 'A') {
	  	printf("Time: %ld ms \n", duration.count());
  	}
  }
  
 
  return 0;
}
