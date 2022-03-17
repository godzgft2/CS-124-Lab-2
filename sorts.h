//sorts.h
#ifndef SORTS_H
#define SORTS_H
#include <string>
#include <vector>

void swap (std::string &x, std::string &y);
void bubble_sort (std::vector<std::string> &a, int size);
int min_position(std::vector<std::string> a, int from, int to);
void selection_sort(std::vector<std::string> &a, int size);
void merge(std::vector<std::string> &a, int from, int mid, int to);
void merge_sort(std::vector<std::string> &a, int from, int to);
int partition(std::vector<std::string> &a, int from, int to);
void quicksort(std::vector<std::string> &a, int from, int to);
void insertion_sort(std::vector<std::string> &a, int size);

#endif
