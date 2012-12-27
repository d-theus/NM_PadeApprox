#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <unistd.h>
#include "texport.hpp"
#include "calc.hpp"
#include "gaussian_el.hpp"

using namespace std;
int main(int argc, const char *argv[])
{
	vector<double> num, denom;
	vector<double> original;
	double val;
	int L,M;
	ifstream infile("input.dat");

	while (infile >> val) 
	{
		original.push_back(val);
	}
	if (original.size() < 1)
	{
		cout << "There is nothing to read from file "<< endl;
	}
	cout << "Ok, input file readable"<<endl;
	cout << "Enter numerator degree"<<endl;
	cin>>L;
	cout << "Enter denominator degree"<<endl;
	cin>>M;

	try
	{
		frac_t res = calculate(original, L,M);
		ofstream of("Approx.tex");
		of << "\\documentclass[a4paper, 14pt]{article}" << endl;
		of << "\\begin{document}"<< endl;
		of << "\\centering" << endl;
		of << "$";
		texport_rational(res.numerator, res.denominator, &of);
		of << "$" << endl;
		of << "\\end{document}";
		of.close();
		system("latex Approx.tex");
		sleep(1);
		system("okular Approx.dvi");
	}
	catch(std::exception& e)
	{
		cout<<e.what()<<endl;
	}
	return 0;
}
