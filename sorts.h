//sorts.h
#ifndef SORTS_H
#define SORTS_H
#include <string>
#include <vector>

void swap (std::string &x, std::string &y);
int bubble_sort (std::vector<std::string> &a, int size);
int min_position(std::vector<std::string> a, int from, int to);
int selection_sort(std::vector<std::string> &a, int size);
void merge(std::vector<std::string> a, int from, int mid, int to);
void merge_sort(std::vector<std::string> a, int from, int to);
int partition(std::vector<std::string> a, int from, int to);
void quicksort(std::vector<std::string> a, int from, int to);
void sorttime(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3, int sort1, int sort2);

#endif
