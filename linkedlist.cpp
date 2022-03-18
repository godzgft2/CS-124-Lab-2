//linkedlist.cpp
#include <string>
#include "linkedlist.h"

Node::Node(std::string element)
{
	data = element;
}

//Adds node to start of list
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

//Adds node to end of list
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

//Adds node to list in order of element
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

//Adds new node placed before node pointer given to function
void List::addatpos(std::string element, Node* pos)
{
	if(headptr==nullptr)
	{
		Node *newnode = new Node(element);
		headptr = newnode;
		tailptr = newnode;
	}
	else if(headptr == pos)
	{
		addfront(element);
	}
	else
	{
		Node *newnode = new Node(element);
		newnode->next = pos;
		newnode->prev = pos->prev;
		pos->prev->next = newnode;
		pos->prev = newnode;
	}
}

//Removes all nodes from the list
void List::remove()
{
	Node* traverse = headptr;
	Node* next = nullptr;
	while(traverse!=nullptr)
	{
		next = traverse->next;
		delete traverse;
		traverse = next;
	}
	headptr = nullptr;
	tailptr = nullptr;
}

//Performs insertion sort algorithm using nodes
void List::insertionsort()
{
	Node* traverse = headptr->next;
	while(traverse!=nullptr)
	{
		Node* insertpos = traverse->prev;
		while(traverse->data <= insertpos->data && insertpos->prev!=nullptr)
		{
			insertpos = insertpos->prev;
		}
		if(traverse->data < insertpos->data)
		{
			this->addatpos(traverse->data, insertpos);
			traverse->next->prev = traverse->prev;
			traverse->prev->next = traverse->next;
			delete traverse;
		}
		/*if(traverse->data <= insertpos->data)
		{
			if(traverse!=tailptr)
			{
				traverse->next->prev = traverse->prev;
				traverse->prev->next = traverse->next;
			}
			else
				traverse->prev->next = nullptr;
			if(insertpos!=headptr)
			{
				traverse->next = insertpos;
				traverse->prev = insertpos->prev;
				insertpos->prev->next = traverse;
				insertpos->prev = traverse;
			}
			else
			{
				traverse->next = insertpos;
				insertpos->prev = traverse;
			}
		}*/
		traverse = traverse->next;
	}
}
