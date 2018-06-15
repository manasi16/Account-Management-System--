#include<iostream>
#include<fstream>
#include<string>
#include"Account_ManasiMehta.h"
#include"BankAccount_ManasiMehta.h"
#include"StockAccount_ManasiMehta.h"

using namespace std;

int main()
{
	int choice;
	int choice1, choice2;
	double deposit, withdraw;
	string symbol;
	BankAccount B;
	StockAccount S;
start:
	cout << "Welcome to the Account Management System!";

	cout << "\n1. Stock Portfolio Account"
		<< "\n2. Bank Account"
		<< "\n3. Exit";

	cout << "\nPlease Select Account to Access : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	display:
		cout << "\nStock Portfolio account";
		cout << "\n1. Display the price for a Stock Symbol"
			<< "\n2. Display Current Portfolio"
			<< "\n3. Buy Shares"
			<< "\n4. Sell Shares"
			<< "\n5. View a Graph for the Portfolio Value"
			<< "\n6. View Transaction History"
			<< "\n7. Return to the Previous Menu";
		cout << "\nEnter Your Choice : ";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			cout << "Please enter the stock symbol: ";
			cin >> symbol;
			S.DisplayStockPrice(symbol);
			goto display;
			break;
		case 2:
			S.DisplayCurrentPortfolio();
			goto display;
			break;
		case 3:
			S.BuyShares();
			goto display;
			break;
		case 4:
			S.SellShares();
			goto display;
			break;
		case 5:
			S.ViewTranHistory();
			goto display;
			break;
		case 6: goto end;
			break;
		end:
			goto start;
			break;
		}
	case 2:
	display1:
		cout << "\nBank Account";
		cout << "\n1. View Account Balance"
			<< "\n2. Deposit Money"
			<< "\n3. Withdraw Money"
			<< "\n4. Print History"
			<< "\n5. Return to Previous Menu";
		cout << "\nEnter Your Choice : ";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			B.viewAccountBalance();
			goto display1;
			break;
		case 2:
			cout << "Please select the amount you wish to deposit:";
			cin >> deposit;
			B.DepositMoney(deposit);
			goto display1;
			break;
		case 3:
			cout << "Please select the amount you wish to withdraw:";
			cin >> withdraw;
			B.WithdrawMoney(withdraw);
			goto display1;
			break;
		case 4:
			B.PrintHistory();
			goto display1;
			break;
		case 5: goto end1;
			break;
		end1:
			goto start;
		}
	}
}