#include <iostream>
#include <chrono>
#include <immintrin.h>
#include "Eigen/Dense"
#include "nonlinear_equation.h"


using namespace std;
using namespace Eigen;

int main(int argc, char* argv[])
{
	
	Eigen::MatrixXf A(3,3);
	A << 10,3,1,2,-10,3,1,3,10;

	Eigen::VectorXf b(3);
	b << 14, -5, 14;
	
	std::cout << Jacobi(A, b) << std::endl;
	std::cout << GaussSeide(A,b) << std::endl;
	return 0;
}
