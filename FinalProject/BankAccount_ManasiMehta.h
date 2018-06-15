#include "Account_ManasiMehta.h"
#include "DoublyLinkedList_ManasiMehta.h"
#include <time.h>
#ifndef BankAccount_H
#define BankAccount_H

class BankAccount : public Account
{
public:
	BankAccount();
	void viewAccountBalance();
	void DepositMoney(double);
	void WithdrawMoney(double);
	void PrintHistory();
	void setBalance(double);
	void getBalance();
	string getTime();
	string getDate();

private:
	double deposit;
	double withdraw;
};
#endif