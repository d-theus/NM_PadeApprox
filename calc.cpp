#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "calc.hpp"
#include "gaussian_el.hpp"

using namespace std;
frac_t calculate(vector<double> &original, int L, int M)
{
	int N = L+M+1;
	if(original.size() < L+M)
		throw Coefficient_exception(
				"Not enough coefficients\
				in input file");

	vector<vector<double> > matrix;
	for (int i = 0; i < N; i++) 
	{
		matrix.push_back(*(new vector<double>(N)));
	}
	for (int i = 0; i < N; i++) 
	{
		if (i < L+1)
		{
			matrix[i][i] = 1;
		}
		for (int j = L+1; j < N && i > 0; j++) 
		{
			matrix[i][j] = -original[L+i -(j)];
		}
	}
	triangulate_fw(matrix, original);
	triangulate_bw(matrix, original);
	frac_t frac;
	frac.denominator.push_back(1);
	for (int i = 0; i < N; i++) 
	{
		if(i < L+1)
			frac.numerator
				.push_back(original[i]);
		else
			frac.denominator
				.push_back(original[i]);
	}
	return frac;
}

