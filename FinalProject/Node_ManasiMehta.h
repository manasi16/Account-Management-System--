#ifndef NODE_MANASIMEHTA_H
#define NODE_MANASIMEHTA_H
#include<iostream>
#include<string>

using namespace std;

class Node
{
	friend class DoublyLinkedList;

public:
	Node(string& name, int numb)
		:symbol(name), number(numb)
	{
		this->next = NULL;
		this->prev = NULL;
	}

private:
	string symbol;
	int number;
	Node *next;
	Node *prev;
};
#endif
