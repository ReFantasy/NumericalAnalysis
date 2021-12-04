#include <iostream>
#include <chrono>
#include <immintrin.h>

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

double f(double x)
{
	return std::pow(10 - 4 * x * x, 1.0 / 3);
}

int main(int argc, char* argv[])
{

	Timer timer;

	
	
	return 0;
}
