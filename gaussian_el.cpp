#include <cstdio>
#include <iostream>
#include <algorithm>
#include "gaussian_el.hpp"

using namespace std;
 
void matrix_get(std::vector<std::vector<double> > &matrix)
{
	int N;
	double val;
	cout << "Enter dimension" << endl;
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		vector<double> newrow;
		for (int j = 0; j < N; j++) 
		{
			printf("Enter matrix[%d][%d]\n", i, j);
			cin >> val;
			newrow.push_back(val);
		}
		matrix.push_back(newrow);
	}
	matrix_print(matrix);
}

void triangulate_fw(
		std::vector<std::vector<double> > &matrix, 
		std::vector<double> & right)
{
	if (matrix.size() > right.size())
		throw Dimension_match_exception(
				"Matrix and right-side vector dimensions doesn't match");
	int N = matrix.size();
	for (int i = 0; i < N; i++) 
	{
		for (int j = i; j < N; j++) 
		{
			if(matrix[i][i] < matrix[j][i])
			{
				swap (matrix[i], matrix[j]);
				swap (right[i],right[j]);
			}
		}
		double x0 = matrix[i][i];
		for(double &el : matrix[i])
			el /= x0;
		right[i] /= x0;
		for (int j = i+1; j < N; j++) 
		{
			double xj0 = matrix[j][i];
			for (int k = i; k < N; k++) 
			{
				matrix[j][k] -= xj0*matrix[i][k];
			}
			right[j] -= xj0*right[i];
		}
	}
}
void triangulate_bw(
		std::vector<std::vector<double> > &matrix, 
		std::vector<double> & right)
{
	if (matrix.size() > right.size())
		throw Dimension_match_exception(
				"Matrix and right-side\
				vector dimensions doesn't match");
	int N = matrix.size();
	for (int i = N-1; i >= 0; i--) 
	{
		double x0 = matrix[i][i];
		for (int j = i-1; j >= 0; j--) 
		{
			double xj0 = matrix[j][i];
			for (int k = i; k >= 0; k--) 
			{
				matrix[j][k] -= xj0*matrix[i][k];
			}
			right[j] -= xj0*right[i];
		}
	}
}

void matrix_print(const std::vector<std::vector<double> > matrix)
{
	for(vector<double> row : matrix)
	{
		for (double el : row)
			cout << el << "\t";
		cout << endl;
	}
}
void matrix_ext_print(
		const std::vector<std::vector<double> > matrix,
		const std::vector<double> right)
{
	int r = 0;
	for (vector<double> row : matrix)
	{
		for(double val : row)
			cout << val << "\t";
		cout << right[r++];
		cout << endl;
	}
}
