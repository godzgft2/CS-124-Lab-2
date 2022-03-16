//linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

//Taken from textbook, set initial values
class Node
{
	public:
		Node(std::string element);
	private:
		Node *next = nullptr;
		Node *prev = nullptr;
		std::string data = "";
	friend class List;
};

//Mostly taken from textbook, functions altered
class List
{
	public:
		void addfront(std::string element);
		void addback(std::string element);
		void addorder(std::string element);
		void remove();
	private:
		Node *headptr = nullptr;
		Node *tailptr = nullptr;
};

#endif
