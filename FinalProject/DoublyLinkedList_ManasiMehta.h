#ifndef DoublyLinkedList_ManasiMehta_H
#define DoublyLinkedList_ManasiMehta_H
#include<iostream>
#include<string>
#include <time.h>
#include "Node_ManasiMehta.h"
#include "Account_ManasiMehta.h"

using namespace std;

class DoublyLinkedList : public Account
{
public:
	DoublyLinkedList();
	void insert(Node *);
	void begin();
	void remove(Node*);
	void Print();
	void sortList();
	double PricePerShare(string);
	int getNumber(string);
	int s;
	static float total_portfolio_value;

private:
	Node *firstPtr;
	Node *lastPtr;
};

#endif



