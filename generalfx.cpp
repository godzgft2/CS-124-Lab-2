//generalfx.cpp
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
//Prints first and last twenty words in vector
void print(std::vector<std::string> a)
{
	std::cout << "\nFirst 20 words: ";
	for(unsigned int i = 0; i < 19; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\nLast 20 words: ";
	for(unsigned int j = (a.size()-1); j > (a.size()-21); j--)
	{
		std::cout << a[j] << " ";
	}
	std::cout << std::endl;
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

