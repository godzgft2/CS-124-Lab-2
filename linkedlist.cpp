//linkedlist.cpp
#include <string>
#include "linkedlist.h"

Node::Node(std::string element)
{
	data = element;
}

void List::addfront(std::string element)
{
	Node *newnode = new Node(element);
	if(headptr==nullptr)
	{
		headptr = newnode;
		tailptr = newnode;
	}
	else
	{
		newnode->next = headptr;
		headptr->prev = newnode;
		headptr = newnode;
	}
}

void List::addback(std::string element)
{
	Node *newnode = new Node(element);
	if(headptr==nullptr)
	{
		headptr = newnode;
		tailptr = newnode;
	}
	else
	{
		newnode->prev = tailptr;
		tailptr->next = newnode;
		tailptr = newnode;
	}
}

void List::addorder(std::string element)
{
	if(element < headptr->data || headptr==nullptr)
		addfront(element);
	else if(element > tailptr->data || tailptr==nullptr)
		addback(element);
	else
	{
		Node *traverse = headptr;
		while(element > traverse->data && traverse->next != nullptr)
		{
			traverse = traverse->next;
		}
		if(traverse == tailptr)
			addback(element);
		else
		{
			Node *newnode = new Node(element);
			newnode->next = traverse;
			newnode->prev = traverse->prev;
			traverse->prev->next = newnode;
			traverse->prev = newnode;
		}
	}
}
