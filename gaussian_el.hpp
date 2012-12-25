#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

#ifndef GELIMINATION
#define GELIMINATION

void triangulate_fw(std::vector<std::vector<double> > &, std::vector<double> &, int);
void triangulate_bw(std::vector<std::vector<double> > &, std::vector<double> &, int);

void matrix_print(const std::vector<std::vector<double> >);
void matrix_ext_print(const std::vector<std::vector<double> >,const std::vector<double>);

#endif
