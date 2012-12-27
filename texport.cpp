#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

void texport_polinome(
		const std::vector<double>&coefs, 
		ofstream *of)
{
	vector<double>::const_iterator it;
	for (it = coefs.begin(); it != coefs.end(); it++) 
	{
		cout << *it << endl;
		int deg = it - coefs.begin();
		char sgn = *it > 0 ? '+' :' ';
		if (*it != 0)
		{
			if (deg == 0)
			{
				*of << *it;
			}
			else
				if (deg != 1)
				{
					if (*it != 1)
						*of << sgn << *it 
							<< "x^{" 
							<< deg 
							<< "}"; 
					else
						*of << sgn 
							<< "x^{" 
							<< deg 
							<< "}"; 
				}
				else
				{
					if (*it != 1)
						*of << sgn 
							<< *it 
							<< "x"; 
					else
						*of << sgn 
							<< "x"; 
				}
		}
	}
}
void texport_rational(const vector<double> &numerator,const vector<double> &denominator, ofstream *of)
{

	*of << "\\frac{";
	texport_polinome(numerator, of);
	*of << "}{";
	texport_polinome(denominator, of);
	*of << "}\n";
}
