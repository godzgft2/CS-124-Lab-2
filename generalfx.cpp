//generalfx.cpp
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

//Prints first and last twenty words in vector
void print(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3)
{
	int choice;
	std::cout << "Which words would you like to see of the sorted list?\n";
	std::cout << "1. First 50 words\n2. Last 50 words\n";
	std::cin >> choice;
	switch(choice)
	{
		case 1:
			std::cout << "\nFirst 50 words\n";
			std::cout << "File 1: ";
			for(unsigned int i = 0; i < 49; i++)
				std::cout << file1[i] << " ";
			std::cout << "\nFile 2: ";
			for(unsigned int i = 0; i < 49; i++)
				std::cout << file2[i] << " ";
			std::cout << "\nFile 3: ";
			for(unsigned int i = 0; i < 49; i++)
				std::cout << file3[i] << " ";
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "\nLast 50 words\n";
			std::cout << "File 1: ";
			for(unsigned int j = (file1.size()-1); j > (file1.size()-51); j--)
				std::cout << file1[j] << " ";
			std::cout << "\nFile 2: ";
			for(unsigned int j = (file2.size()-1); j > (file2.size()-51); j--)
				std::cout << file2[j] << " ";
			std::cout << "\nFile 3: ";
			for(unsigned int j = (file3.size()-1); j > (file3.size()-51); j--)
				std::cout << file3[j] << " ";
			std::cout << std::endl;
			break;
	}
}

//Read file, eliminate some punctuation, words, and digits
std::vector<std::string> readfile(std::string filename)
{
	std::ifstream in;
	in.open(filename);
	std::vector<std::string> words;
	std::string temp;
	while(in >> temp)
	{
		for(unsigned int i = 0; i < temp.length(); i++)
		{
			//Erases digits and punctuation from words because words may have punctuation attached to them
			if(isdigit(temp[i]) || ispunct(temp[i]))	
			{
					temp.erase(i, 1);
					i--;
			}
		}
		//This condition ensures that unnecessary words, or empty strings are not added to the vector
		if(temp != "a" && temp != "an" && temp != "the" &&
			temp != "The" && temp != "A" && temp != "An" &&
			!isdigit(temp[0]) && (temp.length() != 0))
				words.push_back(temp);
	}
	in.close();
	return words;
}

//Outputs sort timing data in a table
void sortdata(std::vector<double> f1s1,std::vector<double> f2s1,std::vector<double> f3s1,
			  std::vector<double> f1s2,std::vector<double> f2s2,std::vector<double> f3s2, int sort1, int sort2)
{
	std::cout << "\t\t\t---Sort Timing Data---\n";
	std::cout << "     ";
	switch(sort1)
	{
		case 1:		//Bubble
			std::cout << std::setw(25) << "Bubble Sort";
			break;
		case 2:		//Selection
			std::cout << std::setw(25) << "Selection Sort";
			break;
		case 3:		//Merge
			std::cout << std::setw(25) << "Merge Sort";
			break;
		case 4:		//Insertion
			std::cout << std::setw(25) << "Insertion Sort";
			break;
		case 5:		//Quick
			std::cout << std::setw(25) << "Quick Sort";
			break;
	}
	switch(sort2)
	{
		case 1:		//Bubble
			std::cout << std::setw(25) << "Bubble Sort\n";
			break;
		case 2:		//Selection
			std::cout << std::setw(25) << "Selection Sort\n";
			break;
		case 3:		//Merge
			std::cout << std::setw(25) << "Merge Sort\n";
			break;
		case 4:		//Insertion
			std::cout << std::setw(25) << "Insertion Sort\n";
			break;
		case 5:		//Quick
			std::cout << std::setw(25) << "Quick Sort\n";
			break;
	}
	std::cout << "     ";
	std::cout << std::setw(15) << "Unsorted" << std::setw(15) << "Sorted" << std::setw(15) << "Unsorted" << std::setw(15) << "Sorted\n";
	std::cout << std::setw(12) << std::left << "File 1" << std::setw(17) << std::left << f1s1[0] << std::setw(13) << std::left << f1s1[1] << std::setw(16) << std::left << f1s2[0] << std::setw(15) << std::left << f1s2[1] << std::endl;
	std::cout << std::setw(12) << std::left << "File 2" << std::setw(17) << std::left << f2s1[0] << std::setw(13) << std::left << f2s1[1] << std::setw(16) << std::left << f2s2[0] << std::setw(15) << std::left << f2s2[1] << std::endl;
	std::cout << std::setw(12) << std::left << "File 3" << std::setw(17) << std::left << f3s1[0] << std::setw(13) << std::left << f3s1[1] << std::setw(16) << std::left << f3s2[0] << std::setw(15) << std::left << f3s2[1] << std::endl;
	if(f1s1.size()>2)
		std::cout << "Linked list times: " << f1s1[2] << "   " << f2s1[3] << "   " << f3s1[3] << std::endl;
	if(f1s2.size()>2)
		std::cout << "Linked list times: " << f1s2[2] << "   " << f2s2[3] << "   " << f3s2[3] << std::endl;
}