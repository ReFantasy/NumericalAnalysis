#ifndef __NONLINEAR_EQUATION_H__
#define __NONLINEAR_EQUATION_H__
#include <iostream>
#include <functional>
#include "Eigen/Dense"

template<typename T>
T Bisection(std::function<T(T)> f, T a, T b, int n = 10000000, double epsilon = 0.0000001)
{
	if (f(a) * f(b) > 0) return T{};

	int cnt = 0;
	T ta = a;
	T tb = b;
	T x{};
	while (cnt < n)
	{
		x = ta + (tb - ta) / 2;

		if (f(ta) * f(x) == 0)break;

		if (f(ta) * f(x) > 0)
		{
			ta = x;
		}
		if (f(ta) * f(x) < 0)
		{
			tb = x;
		}

		if (std::abs(f(x)) <= epsilon)break;

		cnt++;
	}

	return x;
}


Eigen::VectorXf Jacobi(Eigen::MatrixXf A, Eigen::VectorXf b, double epsilon = 0.0000001);

#endif//__NONLINEAR_EQUATION_H__
