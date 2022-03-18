//timing.cpp
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "searches.h"
#include "sorts.h"
#include "linkedlist.h"

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
	std::cout << "Linear searches:\n";
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
	
	//Sorted vectors using merge sort because its expected time is O(nlog(n)) and the extra memory needed is not
	//an issue since it is deleted once the function is exited, freeing the memory as the program continues. It also
	//was the fastest sort at least for my computer
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	merge_sort(file1, 0, file1.size()-1);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
	bitotal1 += time_span1.count();
			
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	merge_sort(file2, 0, file2.size()-1);
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
	bitotal2 += time_span2.count();
			
	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	merge_sort(file3, 0, file3.size()-1);
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
	std::cout << "Binary searches:\n";
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
	std::cout << "                           " << std::setw(12) << std::left << "File 1" << std::setw(12) << std::left << "File 2" << "File 3\n";
	std::cout << "Linear search averages: " << std::setw(12) << std::left << linaverage1 << std::setw(12) << std::left << linaverage2 << std::setw(12) << std::left << linaverage3 << "\n";
	std::cout << "Binary search averages: " << std::setw(12) << std::left << biaverage1 << std::setw(12) << std::left << biaverage2 << std::setw(12) << std::left << biaverage3 << "\n";
}

//Finds timing of two sorting functions chosen by user
std::vector<double> sorttime(std::vector<std::string> &file, int choice)
{
    using namespace std::chrono;
    double sorttotal=0, unsorttotal=0, unsortavg=0, sortavg=0, listtime=0, listavg=0;
    std::vector<std::string> copy = file;
    std::vector<double> avg;
	List list;
	high_resolution_clock::time_point t5;
	high_resolution_clock::time_point t6;
	duration<double> time_span3;
    switch(choice)
    {
        case 1:			//Bubble
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                bubble_sort(copy, copy.size());
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
                unsorttotal += time_span1.count();
                copy = file;
            }
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t3 = high_resolution_clock::now();
                bubble_sort (file, file.size());
                high_resolution_clock::time_point t4 = high_resolution_clock::now();
                duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
                sorttotal += time_span2.count();
            }
            break;
        case 2:			//Selection
			for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                selection_sort(copy, copy.size());
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
                unsorttotal += time_span1.count();
                copy = file;
            }
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t3 = high_resolution_clock::now();
                selection_sort(file, file.size());
                high_resolution_clock::time_point t4 = high_resolution_clock::now();
                duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
                sorttotal += time_span2.count();
            }
            break;
        case 3:			//Merge
			for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                merge_sort(copy, 0, copy.size()-1);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
                unsorttotal += time_span1.count();
                copy = file;
            }
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t3 = high_resolution_clock::now();
                merge_sort(file, 0, file.size()-1);
                high_resolution_clock::time_point t4 = high_resolution_clock::now();
                duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
                sorttotal += time_span2.count();
            }
            break;
        case 4:			//Insertion
			for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                insertion_sort(copy, copy.size());
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
                unsorttotal += time_span1.count();
                copy = file;
            }
            for(int i = 0; i < 9; i++)
			{
				for(unsigned int i = 0; i < file.size(); i++)
					list.addback(file[i]);
				t5 = high_resolution_clock::now();
            	list.insertionsort();
            	t6 = high_resolution_clock::now();
            	time_span3 = duration_cast<duration<double>> (t6-t5);
            	listtime = time_span3.count();
				list.remove();
			}
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t3 = high_resolution_clock::now();
                insertion_sort(file, file.size());
                high_resolution_clock::time_point t4 = high_resolution_clock::now();
                duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
                sorttotal += time_span2.count();
            }
            break;
        case 5:			//Quick
			for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                quicksort(copy, 0, copy.size()-1);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
                unsorttotal += time_span1.count();
                copy = file;
            }
            for(int i = 0; i < 9; i++)
            {
                high_resolution_clock::time_point t3 = high_resolution_clock::now();
                quicksort(file, 0, file.size()-1);
                high_resolution_clock::time_point t4 = high_resolution_clock::now();
                duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
                sorttotal += time_span2.count();
            }
            break;
    }
	unsortavg = unsorttotal/10;
    sortavg = sorttotal/10;
    avg.push_back(unsortavg);
    avg.push_back(sortavg);
	if(choice==4)
	{
		listavg = listtime/10;
		avg.push_back(listavg);
		list.remove();
	}
    return avg;
}
