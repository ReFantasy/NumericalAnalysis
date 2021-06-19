#include <iostream>
#include <chrono>
#include <immintrin.h>
#include "Eigen/Dense"
#include "nonlinear_equation.h"
#include <chrono>

using namespace std;
using namespace Eigen;

class Timer
{
public:
	void Start()
	{
		t1 = std::chrono::high_resolution_clock::now();
	}
	void Stop()
	{
		t2 = std::chrono::high_resolution_clock::now();
	}

	template<typename T = std::chrono::milliseconds>
	unsigned long long Elapsed()
	{
		return std::chrono::duration_cast<T>(t2 - t1).count();
	}
private:
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

};

int main(int argc, char* argv[])
{
	Timer timer;

	Eigen::MatrixXf A(3, 3);
	A << 4, -2, -4, -2, 17, 10, -4, 10, 9;

	Eigen::VectorXf b(3);
	b << 10, 3, -7;

	timer.Start();
	GaussSeide(A, b, 0.0000001);
	timer.Stop();
	std::cout << timer.Elapsed<std::chrono::microseconds>() << std::endl;

	timer.Start();
	SOR(A, b, 1.46, 0.0000001);
	timer.Stop();
	std::cout << timer.Elapsed<std::chrono::microseconds>() << std::endl;
	return 0;
}
