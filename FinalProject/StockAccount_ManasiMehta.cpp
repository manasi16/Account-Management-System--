
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib" )  
#pragma comment( lib, "libeng.lib" )

#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
#include <engine.h>


#include "StockAccount_ManasiMehta.h"
#include "Account_ManasiMehta.h"
#include "BankAccount_ManasiMehta.h"
#include "DoublyLinkedList_ManasiMehta.h"
#include "Node_ManasiMehta.h"
#include<iostream>
#include<string>
#include<iomanip>
#include <stdlib.h>
#include <fstream>
#include<time.h>
#include <cstdlib>



using namespace std;
DoublyLinkedList D;;

string StockAccount::getDate()
{
	char datestr[20];
	_strdate_s(datestr);
	return datestr;
}

string StockAccount::getTime()
{
	char timestr[20];
	_strtime_s(timestr);
	return timestr;
}

StockAccount::StockAccount()
{

}

void StockAccount::DisplayStockPrice(string symbol)
{
	int found = 0;
	double price;
	string name, date;

	ifstream file;
	
	srand(time(0));
	int n = rand();
	int num = n % 2;
	
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
			cout << "Company Symbol" << setw(20) << "Price per share" << endl;
			cout << symbol << setw(25) << "$" << price;
			found = 1;
		}
	}
	
	if (found == 0) 
	{
		cout << "Stock symbol is not present in the list";
	}
}

void StockAccount::DisplayCurrentPortfolio()
{
	cout << "Cash Balance= " << getCashBalance();
	D.Print();

}
	

void StockAccount::BuyShares()
{
	string symbol, name, date;
	double price, maxpershare;
	int number, found = 0;

	cout << "\nEnter the symbol of the stock you want to buy: ";
	cin >> symbol;
	cout << "\nEnter the number of shares you want to buy: ";
	cin >> number;
	cout << "\nEnter the maximum amount you are willing to pay per share: ";
	cin >> maxpershare;
	ifstream file;

	srand(time(0));
	int n = rand();
	int m= n % 2;

	if (m == 1)
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
		CASH_BALANCE = getCashBalance();

		if (name == symbol)
		{
			if (price > maxpershare)
			{
				cout << "\nTransaction Failed: The maximum amount you are willing to pay is less than the current stock price per share";
				found = 1;
			}
			else if (number*price > CASH_BALANCE)
			{
				cout << "\nTransaction Failed: You do not have enough balance in your account";
				found = 1;
			}
			else
			{
				Node *newPtr = new Node(symbol, number);
				D.insert(newPtr); 
				found = 1;
				CASH_BALANCE -= number*price;
				cout << "\nYou bought " << number << " shares and your balance is: $" << CASH_BALANCE;

				
				ofstream stockhistory("stock_transaction_history.txt", ios::app);
				stockhistory << "BUY" << setw(20) << symbol << setw(20) << number << setw(20) << price << setw(20) << number*price << setw(20) <<getDate()<<setw(20)<< getTime() << endl;
				ofstream bankhistory("bank_transaction_history.txt", ios::app);
				bankhistory << "Withdrawal" << setw(20) << number*price << setw(20) << getCashBalance() << setw(20) << getDate() << setw(20) << getTime() << endl;
			}
		}
	}
	if (found == 0)
	{
		cout << "\nThe symbol you entered is not found";
	}
}
void StockAccount::SellShares()
{
	string symbol, name, date;
	double price, minpershare;
	int number, found = 0;

	cout << "\nEnter the symbol of the stock you want to sell: ";
	cin >> symbol;
	cout << "\nEnter the number of shares you want to sell: ";
	cin >> number;
	cout << "\nEnter the minimum amount you are willing to sell per share: ";
	cin >> minpershare;
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

	for (int i = 0; i < 49; i++)
	{
		file >> name >> price >> date;
		if (name == symbol)
		{
			found = 1;
			int value = D.getNumber(symbol);

			if (value == -1)
			{
				cout << "\nTransaction Failed: You have no shares of this symbol";
			}
			if (number > value)
			{
				cout << "\nTransaction Failed: You do not have enough number of shares";
			}
			if (price < minpershare)
			{
				cout << "\nTransaction Failed: The minimum amount you are willing to sell is greater than the current share value";
			}
			else
			{
				Node *newPtr = new Node(symbol, number);
				D.remove(newPtr);
				found = 1;
				CASH_BALANCE += number*price;
				cout << "\nYou bought " << number << " shares and your balance is: $" << CASH_BALANCE;


				ofstream stockhistory("stock_transaction_history.txt", ios::app);
				stockhistory << "SELL" << setw(20) << symbol << setw(20) << number << setw(20) << price << setw(20) << number*price << setw(20) << getDate() << getTime() << endl;
				ofstream bankhistory("bank_transaction_history.txt", ios::app);
				bankhistory << "Deposit" << setw(20) << number*price << setw(20) << getCashBalance() << setw(20) << getDate() << setw(20) << getTime() << endl;
			}
		}
	}
	file.close();
	if (found == 0)
	{
		cout << "\nTransaction Failed: The symbol you entered is not present in your stocks";
	}
}

void StockAccount::ViewGraph()
{
	double a = 0, sum = 0;
	int n = 1000;

	double *d = new double[n];

	for (int i = 0; i <n; i++)
	{
		d[i] = i + 1;
	}

	// creating a pointer to the engine
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found." << endl;
		exit(1);
	}
	// end

	mxArray *A;
	A = mxCreateDoubleMatrix(1, n, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)d, n * sizeof(double));
	engPutVariable(ep, "xx", A);

	engEvalString(ep, "X=xx;");
	engEvalString(ep, "plot(X);");	//call plot function

	engEvalString(ep, "title('Successful!!!');");

	mxDestroyArray(A);

	system("pause");
}

void StockAccount::ViewTranHistory()
{
	ifstream file;
	string line;

	file.open("stock_transaction_history.txt", ios::app);
	cout << "\nEVENT" << setw(20) << "SYMBOL" << setw(20) << "NUMBER" << setw(20) << "PRICE" << setw(20)<<"AMOUNT"<<setw(20) << "DATE" <<setw(20)<<"TIME"<< endl;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
		}
		file.close();
	}
	else
		cout << "Error in opening the file.\n";
}

void StockAccount::sortList()
{
	D.sortList();
}

void StockAccount::setBalance(double newBalance)
{
	CASH_BALANCE = newBalance;
}

void StockAccount::getBalance()
{
	cout << "\n\nYou have $" << getCashBalance() << " in your bank account";
}
