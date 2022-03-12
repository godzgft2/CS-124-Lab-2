//searches.cpp
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include "sorts.h"
//Taken from textbook, adjusted for vectors of strings
int linear_search(std::vector<std::string> a, int size, std::string value)
{  
   for (int i = 0; i < size; i++)
   {  
      if (a[i] == value)
      {
         return i;
      }
   }
   return -1;
}

//Taken from textbook, adjusted for vectors of strings
int binary_search(std::vector<std::string> a, int from, int to, std::string value)
{  
   if (from > to) 
   { 
      return -1; 
   }

   int mid = (from + to) / 2;
   if (a[mid] == value)
   {
      return mid;
   }
   else if (a[mid] < value)
   {
      return binary_search(a, mid + 1, to, value);
   }
   else
   {
      return binary_search(a, from, mid - 1, value);
   }
}

//Runs linear and binary search on three files twenty times and finds average time
//Binary search includes sorting time of bubble sort, chosen because it is optimized and does not need more memory
void searchtime(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3)
{
	using namespace std::chrono;
	int index1, index2, index3;
	double lintotal1=0, lintotal2=0, lintotal3=0, bitotal1=0, bitotal2=0, bitotal3=0;
	std::string searchterm;
	std::cout << "Enter a word to be searched for: ";
	std::cin >> searchterm;
	for(int i = 0; i < 19; i++)
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		index1 = linear_search(file1, file1.size(), searchterm);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
		lintotal1 += time_span1.count();
				
		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		index2 = linear_search(file2, file2.size(), searchterm);
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
		lintotal2 += time_span2.count();
				
		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		index3 = linear_search(file3, file3.size(), searchterm);
		high_resolution_clock::time_point t6 = high_resolution_clock::now();
		duration<double> time_span3 = duration_cast<duration<double>> (t6-t5);
		lintotal3 += time_span3.count();
	}
	double linaverage1 = lintotal1/20;
	double linaverage2 = lintotal2/20;
	double linaverage3 = lintotal3/20;
	std::cout << "Linear search averages: " << linaverage1 << " " << linaverage2 << " " << linaverage3 << "\n";
			
	if(index1==-1)
		std::cout << "Search term not found in file 1.\n";
	else
		std::cout << "Search term found in file 1 at index " << index1 << "\n";
	if(index2==-1)
		std::cout << "Search term not found in file 2.\n";
	else
		std::cout << "Search term found in file 2 at index " << index2 << "\n";
	if(index3==-1)
		std::cout << "Search term not found in file 3.\n";
	else
		std::cout << "Search term found in file 3 at index " << index3 << "\n";
			
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	bubble_sort(file1, file1.size());
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
	bitotal1 += time_span1.count();
			
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	bubble_sort(file2, file2.size());
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
	bitotal2 += time_span2.count();
			
	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	bubble_sort(file3, file3.size());
	high_resolution_clock::time_point t6 = high_resolution_clock::now();
	duration<double> time_span3 = duration_cast<duration<double>> (t6-t5);
	bitotal3 += time_span3.count();
			
	for(int i = 0; i < 19; i++)
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		index1 = binary_search(file1, 0, file1.size(), searchterm);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
		bitotal1 += time_span1.count();
				
		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		index2 = binary_search(file2, 0, file2.size(), searchterm);
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
		bitotal2 += time_span2.count();
				
		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		index3 = binary_search(file3, 0, file3.size(), searchterm);
		high_resolution_clock::time_point t6 = high_resolution_clock::now();
		duration<double> time_span3 = duration_cast<duration<double>> (t6-t5);
		bitotal3 += time_span3.count();
	}
	double biaverage1 = bitotal1/20;
	double biaverage2 = bitotal2/20;
	double biaverage3 = bitotal3/20;
	std::cout << "Binary search averages: " << biaverage1 << " " << biaverage2 << " " << biaverage3 << "\n";
	if(index1==-1)
		std::cout << "Search term not found in file 1.\n";
	else
		std::cout << "Search term found in file 1 at index " << index1 << "\n";
	if(index2==-1)
		std::cout << "Search term not found in file 2.\n";
	else
		std::cout << "Search term found in file 2 at index " << index2 << "\n";
	if(index3==-1)
		std::cout << "Search term not found in file 3.\n";
	else
		std::cout << "Search term found in file 3 at index " << index3 << "\n";
}
