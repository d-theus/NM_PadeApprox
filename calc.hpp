#include <vector>
#include <stdexcept>
/*
*	Структура,	содержащая	коэффициенты	двух	полиномов.
*	В	нашем	случае	отражает	числитель	и
*	знаменатель	рациональной	функции
 */
typedef struct frac_t 
{
	std::vector<double> numerator;
	std::vector<double> denominator;
} frac_t;

frac_t calculate(std::vector<double> &, int, int);

struct Coefficient_exception : public std::runtime_error 
{
	Coefficient_exception(const std:: string& msg) : std::runtime_error(msg){}
};
