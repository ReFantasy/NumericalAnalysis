#ifndef __EQUATION_H__
#define __EQUATION_H__
#include <iostream>
#include <functional>
#include "Eigen/Dense"

/*****************************************************************************************************
 * 
 *                             线性方程组 Ax=b 的数值求解（迭代法）
 * 
 *****************************************************************************************************/

Eigen::VectorXf Jacobi(Eigen::MatrixXf A, Eigen::VectorXf b, double epsilon = 0.00001);

Eigen::VectorXf GaussSeide(Eigen::MatrixXf A, Eigen::VectorXf b, double epsilon = 0.00001);

Eigen::VectorXf SOR(Eigen::MatrixXf A, Eigen::VectorXf b, double w = 1.4, double epsilon = 0.00001);







template<typename T>
T Bisection(std::function<T(T)> f, T a, T b, int n = 10000000, double epsilon = 0.00001)
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
#endif//__EQUATION_H__
