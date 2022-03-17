//generalfx.h
#ifndef GENERALFX_H
#define GENERALFX_H
#include <vector>
#include <string>

void print(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3);
std::vector<std::string> readfile(std::string filename);
void sortdata(std::vector<double> f1s1,std::vector<double> f2s1,std::vector<double> f3s1,
			  std::vector<double> f1s2,std::vector<double> f2s2,std::vector<double> f3s2, int sort1, int sort2);

#endif
