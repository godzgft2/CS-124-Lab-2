//searches.h
#ifndef SEARCHES_H
#define SEARCHES_H
#include <string>
#include <vector>

int linear_search(std::vector<std::string> a, int size, std::string value);
int binary_search(std::vector<std::string> a, int from, int to, std::string value);
void searchtime(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3);

#endif
