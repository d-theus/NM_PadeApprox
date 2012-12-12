#include <vector>
typedef struct frac_t 
{
	std::vector<double> numerator;
	std::vector<double> denominator;

} frac_t;

frac_t calculate(std::vector<double> &, int, int);
