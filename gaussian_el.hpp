#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <stdexcept>

#ifndef GELIMINATION
#define GELIMINATION

void triangulate_fw(std::vector<std::vector<double> > &, std::vector<double> &);
void triangulate_bw(std::vector<std::vector<double> > &, std::vector<double> &);

void matrix_print(const std::vector<std::vector<double> >);
void matrix_ext_print(const std::vector<std::vector<double> >,const std::vector<double>);

struct Dimension_match_exception: public std::runtime_error
{
	Dimension_match_exception(const std::string& msg): std::runtime_error(msg) {}
};

#endif
