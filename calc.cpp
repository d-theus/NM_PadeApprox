#include <iostream>
#include <cstdlib>
#include <Eigen/Dense>
#include "calc.hpp"
#include <stdexcept>
using namespace Eigen;
using namespace std;

frac_t calculate(vector<double> &original, int numDeg, int denDeg)
{
	int count = original.size();
	if(count < std::max(numDeg, denDeg) +2)
	{
		throw std::runtime_error("Not enough coefficients");
	}
	MatrixXd bs(numDeg+denDeg+1, denDeg );
	for (int i = 0; i < numDeg+denDeg+1; i++) 
	{
		for (int j = 1; j <= i && j <= denDeg; j++) 
		{
			bs(i,j-1) = -original[i-j];
		}
	}
	MatrixXd mat(numDeg+denDeg+1, numDeg+denDeg+1);
	mat.setZero();
	mat.topLeftCorner(numDeg+1,numDeg+1).setIdentity();
	mat.rightCols(denDeg) = bs;
	cout<<mat<<endl;
	VectorXd cs(numDeg+denDeg+1);
	for (int i = 0; i < numDeg+denDeg+1; i++) 
	{
		cs(i) = original[i];
	}
	cout<<cs<<endl;
	VectorXd sols(numDeg+denDeg+1);
	sols= mat.inverse()*cs;
	cout<<endl<<sols<<endl;
	frac_t frac;
	for (int i = 0; i < numDeg; i++) 
	{
		frac.numerator.push_back(sols(i));
	}
	for (int i = 0; i < denDeg; i++) 
	{
		frac.denominator.push_back(sols(i));
	}
	return frac;
}

