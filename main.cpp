#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "texport.hpp"
#include "calc.hpp"

using namespace std;


int main(int argc, const char *argv[])
{
	vector<double> num, denom;
	vector<double> original;
	double val;

	ifstream infile("input.dat");
	while (infile >> val) 
	{
		original.push_back(val);
	}

	try
	{
		frac_t res = calculate(original, 3,4);
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
	}
	catch(string &message)
	{
		cout<<message<<endl;
	}

	return 0;
}
