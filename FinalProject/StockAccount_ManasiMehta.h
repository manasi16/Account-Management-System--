#ifndef StockAccount_H
#define StockAccount_H

#include<iostream>
#include<string>

#include "Account_ManasiMehta.h"
#include "Node_ManasiMehta.h"
#include "DoublyLinkedList_ManasiMehta.h"
using namespace std;

class StockAccount : public Account
{
public:
	StockAccount();
	void DisplayStockPrice(string);
	void DisplayCurrentPortfolio();
	void BuyShares();
	void SellShares();
	void ViewGraph();
	void ViewTranHistory();
	void sortList();
	void setBalance(double);
	void getBalance();
	string getTime();
	string getDate();
};
#endif