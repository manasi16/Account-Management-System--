#include "BankAccount_ManasiMehta.h"
#include "Account_ManasiMehta.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<cstdlib>
using namespace std;

BankAccount::BankAccount()
{

}

string BankAccount::getDate()
{
	char datestr[20];
	_strdate_s(datestr);
	return datestr;
}

string BankAccount ::getTime()
{
	char timestr[20];
	_strtime_s(timestr);
	return timestr;
}


void BankAccount::viewAccountBalance()
{
	cout << "Cash Balance=" << getCashBalance();
}

void BankAccount::DepositMoney(double moneyd)
{
	CASH_BALANCE += moneyd;
	cout << "Your cash balance after depositing " << moneyd << "$ is " << CASH_BALANCE << "$" << endl;
	ofstream file;

	file.open("bank_transaction_history.txt", ios::app);
	file << "Deposit" << setw(20) << moneyd << setw(20) << getCashBalance() << setw(20) << getDate() << setw(20) << getTime() << endl;
}


void BankAccount::WithdrawMoney(double moneyw)
{
	CASH_BALANCE -= moneyw;
		cout << "Your cash balance after withdrawal of " << moneyw << "$ is " << CASH_BALANCE << "$" << endl;
		ofstream file;

		file.open("bank_transaction_history.txt", ios::app);
		file << "Withdraw" << setw(20) << moneyw << setw(20) << getCashBalance() << setw(20) << getDate() << setw(20) << getTime() << endl;

}

void BankAccount::PrintHistory()
{
	ifstream file;
	string line;
	
	file.open("bank_transaction_history.txt", ios::app);
	cout << "\nEVENT" << setw(20) << "AMOUNT" << setw(20) << "BALANCE" << setw(20) << "DATE" << setw(20) << "TIME" << endl;
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

void BankAccount::setBalance(double newBalance)
{
	CASH_BALANCE = newBalance;
}

void BankAccount::getBalance()
{
	cout << "\n\nYou have $" << getCashBalance() << " in your bank account";
}
