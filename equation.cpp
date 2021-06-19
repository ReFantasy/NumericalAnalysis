#include "equation.h"

#ifdef LOGON
#include "easylogging++.h"
#endif

Eigen::VectorXf Jacobi(Eigen::MatrixXf A, Eigen::VectorXf b, double epsilon)
{
	if ((A.rows() != A.cols()) || (A.diagonal().prod() == 0) || (A.rows() != b.size()))
		return {};

	Eigen::MatrixXf U = A.triangularView<Eigen::StrictlyUpper>();
	Eigen::MatrixXf L = A.triangularView<Eigen::StrictlyLower>();
	Eigen::MatrixXf D = A - L - U;

	Eigen::MatrixXf B = D.inverse() * (-L - U);
	Eigen::MatrixXf f = D.inverse() * b;

	Eigen::VectorXf x = f;

	size_t n = 0;
	while (true)
	{
		Eigen::VectorXf tx = B * x + f;
		n++;

		if ((tx - x).lpNorm<Eigen::Infinity>() < epsilon)
		{
			x = tx;
			break;
		}

		x = tx;
	}
#ifdef LOGON
	LOG(INFO)<< "Jacobi Iterated: " << n << " times" ;
#endif
	return x;
}

Eigen::VectorXf GaussSeide(Eigen::MatrixXf A, Eigen::VectorXf b, double epsilon)
{
	if ((A.rows() != A.cols()) || (A.diagonal().prod() == 0) || (A.rows() != b.size()))
		return {};

	Eigen::MatrixXf U = A.triangularView<Eigen::StrictlyUpper>();
	Eigen::MatrixXf L = A.triangularView<Eigen::StrictlyLower>();
	Eigen::MatrixXf D = A - L - U;

	Eigen::MatrixXf B = (D + L).inverse() * (-U);
	Eigen::MatrixXf f = (D + L).inverse() * b;

	Eigen::VectorXf x = f;

	size_t n = 0;
	while (true)
	{
		Eigen::VectorXf tx = B * x + f;

		n++;

		if ((tx - x).lpNorm<Eigen::Infinity>() < epsilon)
		{
			x = tx;
			break;
		}

		x = tx;
	}
#ifdef LOGON
	LOG(INFO) << "GaussSeide Iterated: " << n << " times"; 
#endif
	return x;
}

Eigen::VectorXf SOR(Eigen::MatrixXf A, Eigen::VectorXf b, double w, double epsilon )
{
	if ((A.rows() != A.cols()) || (A.diagonal().prod() == 0) || (A.rows() != b.size()))
		return {};

	Eigen::MatrixXf U = A.triangularView<Eigen::StrictlyUpper>();
	Eigen::MatrixXf L = A.triangularView<Eigen::StrictlyLower>();
	Eigen::MatrixXf D = A - L - U;

	Eigen::MatrixXf B = (D + w * L).inverse() * ((1 - w) * D - w * U);
	Eigen::MatrixXf f = w * (D + w * L).inverse() * b;

	Eigen::VectorXf x = f;

	size_t n = 0;
	while (true)
	{
		Eigen::VectorXf tx = B * x + f;

		n++;

		if ((tx - x).lpNorm<Eigen::Infinity>() < epsilon)
		{
			x = tx;
			break;
		}

		x = tx;
	}
#ifdef LOGON
	LOG(INFO) << "SOR Iterated: " << n << " times";
#endif
	return x;
}