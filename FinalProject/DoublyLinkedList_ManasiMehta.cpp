#include "DoublyLinkedList_ManasiMehta.h"
#include "Node_ManasiMehta.h"
#include "Account_ManasiMehta.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<cstdlib>
using namespace std;
float DoublyLinkedList::total_portfolio_value = 0;


DoublyLinkedList::DoublyLinkedList()
{
	firstPtr = NULL;
	lastPtr = NULL;
}

void DoublyLinkedList::insert(Node *newPtr)
{
	Node *tempPtr = NULL;
	int found = 0;
	tempPtr = firstPtr;
	if (firstPtr != NULL)
	{
		if (firstPtr->symbol == newPtr->symbol)
		{
			firstPtr->number += newPtr->number;
			found = 1;
		}
		else if (lastPtr->symbol == newPtr->symbol)
		{
			lastPtr->number += newPtr->number;
			found = 1;
		}
		else
		{
			while (tempPtr->prev != NULL)
			{
				if (tempPtr->symbol == newPtr->symbol)
				{
					tempPtr->number += newPtr->number;
					found = 1;
					break;
				}
				else
				{
					tempPtr = tempPtr->prev;
				}
			}
		}
	}
		if (s == 0)
		{
			firstPtr = lastPtr = newPtr;
			s++;
		}
		else if (s == 1 && found == 0)
		{
			firstPtr = newPtr;
			lastPtr->next = firstPtr;
			firstPtr->prev = lastPtr;
			s++;
		}
		else  if (s > 1 && found == 0)
		{
			Node *tempPtr = NULL;
			tempPtr = firstPtr;
			firstPtr = newPtr;
			tempPtr->next = firstPtr;
			firstPtr->prev = tempPtr;
			s++;
		}
	}

void DoublyLinkedList::begin()
{
	ifstream file("StockAccount_Info.txt", ios::in);
	string symbol, title1, title2;
	int number;
	file >> title1 >> title2;

	while (true)
	{
		file >> symbol >> number;
		if (file.eof())
			break;
		Node *newPtr = new Node(symbol, number);
		insert(newPtr);
	}
}

void DoublyLinkedList::remove(Node *newPtr)
{
	Node *currentPtr;
	Node *tempPtr;
	currentPtr = firstPtr;
	for (int i = 0; i < s; i++)
	{
		if (currentPtr->symbol == newPtr->symbol)
		{
			currentPtr->number -= newPtr->number;
			if (currentPtr->number == 0)
			{
				if (s == 1)
				{
					tempPtr = firstPtr;
					firstPtr = lastPtr = NULL;
					delete tempPtr;
					s--;
				}
				else
				{
					if (currentPtr == firstPtr)
					{
						tempPtr = firstPtr;
						firstPtr = firstPtr->prev;
						firstPtr->next = NULL;
						delete tempPtr;
						currentPtr = firstPtr;
						s--;
					}
					else if (currentPtr == lastPtr)
					{
						tempPtr = lastPtr;
						lastPtr = lastPtr->next;
						lastPtr->prev = NULL;
						delete tempPtr;
						s--;
					}
					else
					{
						tempPtr = currentPtr;
						currentPtr->prev->next = currentPtr->next;
						currentPtr->next->prev = currentPtr->prev;
						currentPtr = currentPtr->prev;
						delete tempPtr;
						s--;
					}
				}
			}
		}
		currentPtr = currentPtr->prev;
	}
}

void DoublyLinkedList::Print()
{
	Node *newPtr;
	newPtr = firstPtr;
	double sum = 0;

	cout << "\nCompany Symbol" << setw(15) << "Number" << setw(15) << "PricePerShare" << setw(15) << "TotalValue" << endl;
	if (s == 0)
	{
		cout << "---" << setw(20) << "--" << setw(20) << "--" << setw(20) << "--" << endl;
	}
	else {
		for (int i = 0; i < s; i++)
		{
			double price = PricePerShare(newPtr->symbol);
			cout << newPtr->symbol << setw(20) << newPtr->number << setw(20) << price << setw(20) << price*(newPtr->number) << endl;
			sum += price*(newPtr->number);
			newPtr = newPtr->prev;
		}
	}
	total_portfolio_value = sum + getCashBalance();
	cout << "\nTotal portfolio value is: $" << total_portfolio_value;

}

void DoublyLinkedList::sortList()
{
	Node *currentPtr = firstPtr;
	if (s == 0)
	{
		cout << "\nYou do not have any shares bought to sort";
	}
	else {
		string name, date;
		double price, big;
		ifstream file;

		srand(time(0));
		int n = rand();
		int m = n % 2;

		if (m == 1)
		{
			file.open("Result_1.txt");
		}
		else
		{
			file.open("Result_2.txt");
		}

		for (int k = 0; k < 49; k++)
		{
			file >> name >> price >> date;
			if (name == currentPtr->symbol)
			{
				big = (currentPtr->number)*price;
			}
		}
		file.close();
		Node *tempPtr = currentPtr->prev;
		for (int j = m + 1; j < s; j++)
		{
			srand(time(0));
			int num = rand() % 2;
			if (num == 1)
			{
				file.open("Result_1.txt");
			}
			else
			{
				file.open("Result_2.txt");
			}
			for (int l = 0; l < 49; l++)
			{
				file >> name >> price >> date;
				if (name == tempPtr->symbol)
				{
					if ((tempPtr->number)*price > big)
					{
						string temp1;
						int temp2;
						temp1 = currentPtr->symbol;
						temp2 = currentPtr->number;
						currentPtr->symbol = tempPtr->symbol;
						currentPtr->number = tempPtr->number;
						tempPtr->symbol = temp1;
						tempPtr->number = temp2;
						big = (currentPtr->number)*price;
					}
				}
			}
			file.close();
			if (m == 0)
			{
				firstPtr = currentPtr;
			}
			if (m == s - 1)
			{
				lastPtr = tempPtr;
			}
			tempPtr = tempPtr->prev;
		}
		currentPtr = currentPtr->prev;
	}
}

double DoublyLinkedList::PricePerShare(string symbol)
{
	string name, date;
	double price;

	ifstream file;
	srand(time(0));
	int number = rand();
	int num = number % 2;
	if (num == 1)
	{
		file.open("Result_1.txt");
	}
	else
	{
		file.open("Result_2.txt");
	}
	for (int i = 0; i < 49; i++)
	{
		file >> name >> price >> date;
		if (name == symbol)
		{
			return price;
		}
	}
}

int DoublyLinkedList ::getNumber(string symbol) 
{
	Node *tempPtr = firstPtr;
	for (int i = 0; i <s; i++)
	{
		if (tempPtr->symbol == symbol)
		{
			return tempPtr->number; 
		}
		tempPtr = tempPtr->prev;
	}
	return -1; 
}

