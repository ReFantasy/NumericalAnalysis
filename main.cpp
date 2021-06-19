#include <iostream>
#include <chrono>
#include <immintrin.h>
#include "easylogging++.h"
#include "equation.h"


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

INITIALIZE_EASYLOGGINGPP
int main(int argc, char* argv[])
{

	Timer timer;

	Eigen::MatrixXf A(3, 3);
	A << 8, -3, 2, 4, 11, -1, 6, 3, 12;

	Eigen::VectorXf b(3);
	b << 20, 33, 36;

	timer.Start();
	Jacobi(A, b, 0.0000001);
	timer.Stop();

	timer.Start();
	GaussSeide(A, b, 0.0000001);
	timer.Stop();
	std::cout << timer.Elapsed<std::chrono::microseconds>() << std::endl;

	timer.Start();
	SOR(A, b, 0.9, 0.0000001);
	timer.Stop();
	std::cout << timer.Elapsed<std::chrono::microseconds>() << std::endl;
	return 0;
}
