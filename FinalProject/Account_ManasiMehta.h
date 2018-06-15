#ifndef Account_ManasiMehta_H
#define Account_ManasiMehta_H
#include<iostream>

using namespace std;

class Account
{
public:
	double CASH_BALANCE;

	Account();
	
 double getCashBalance()
	{
		return CASH_BALANCE;
	}
	
    virtual void setCashBalance(double c);
};
#endif

