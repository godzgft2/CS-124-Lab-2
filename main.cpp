//CS 124 Lab 2 Sorting Algorithms
//Yosuf Wakili
//March 18, 2022
//This code will read three text files and create vectors of words then allow the user to choose to compare the average 
//timings of either two sorting or two searching algorithms. The timings will be output in a table and the user will have
//the choice to output either the last or first fifty words of the sorted vectors of words.
//main.cpp

#include <iostream>		//Input and output from terminal
#include <fstream>		//Reading files
#include <string>		//String data type
#include <vector>		//Vector data type
#include "sorts.h"
#include "generalfx.h"
#include "searches.h"
#include "linkedlist.h"
#include "timing.h"

int main()
{
	char choice = 'y';
	while(toupper(choice) != 'N')			//accepts lowercase and uppercase letters
	{
		int option, sort1, sort2;
		std::cout << "Welcome to the program. This code will read three text files and create vectors of words then "
				  << "allow you to choose to compare the average timings of either two sorting or two searching algorithms. "
				  << "The timings will be output in a table and you will have the choice to output either the last or first "
				  << "fifty words of the sorted vectors of words. \n\n";
		std::cout << "Would you like to run this program?(y/n): ";
		std::cin >> choice;
		std::cout << "Running program..." << std::endl;
		
		std::vector<std::string> file1 = readfile("splendidsuns5k.txt");//A Thousand Splendid Suns
		std::vector<std::string> file2 = readfile("artofwar10k.txt");	//Art of War
		std::vector<std::string> file3 = readfile("sisyphus20k.txt"); 	//Myth of Sisyphus
		
		std::cout << "Please enter a number to choose to compare two sorting algorithms or two searching algorithms\n"
				  << "1. Compare Sorts\n2. Compare Searches\n";
		std::cin >> option;
		if(option==1)
		{
			std::cout << "Choose a sort to compare:\n"
			<< "1. Bubble Sort\n2. Selection Sort\n3. Merge Sort\n4. Insertion Sort\n5. Quick Sort\n";
			std::cin >> sort1;
			std::cout << "Choose second sort: ";
			std::cin >> sort2;
			std::cout << "Starting sorts...\n";
			//Each vector contains unsorted average time and sorted average time for a certain file and sort
			std::vector<double> timesf1s1 = sorttime(file1, sort1);
			std::cout << "File 1 Sort 1 complete\n";
			std::vector<double> timesf2s1 = sorttime(file2, sort1);
			std::cout << "File 2 Sort 1 complete\n";
			std::vector<double> timesf3s1 = sorttime(file3, sort1);
			std::cout << "File 3 Sort 1 complete\n";
			std::vector<double> timesf1s2 = sorttime(file1, sort2);
			std::cout << "File 1 Sort 2 complete\n";
			std::vector<double> timesf2s2 = sorttime(file2, sort2);
			std::cout << "File 2 Sort 2 complete\n";
			std::vector<double> timesf3s2 = sorttime(file3, sort2);
			std::cout << "File 3 Sort 2 complete\n";
			sortdata(timesf1s1, timesf2s1, timesf3s1, timesf1s2, timesf2s2, timesf3s2, sort1, sort2);
		}
		else if(option==2)
		{
			searchtime(file1, file2, file3);
			merge_sort(file1, 0, file1.size()-1);
			merge_sort(file2, 0, file2.size()-1);
			merge_sort(file3, 0, file3.size()-1);
		}
		else
		{
			std::cout << "Not a valid choice. Exiting program.\n";
			choice = 'n';
		}

		print(file1, file2, file3);
		
		std::cout << "\nWould you like to repeat the program?(y/n): ";
		std::cin >> choice;
	}
	std::cout << "Exiting program.\n";
	return 0;
}
