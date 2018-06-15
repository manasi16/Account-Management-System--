#include<iostream>
#include "Account_ManasiMehta.h"

using namespace std;


Account::Account()
{
	CASH_BALANCE = 10000.0;
}

void Account::setCashBalance(double c)
{
	CASH_BALANCE = c;
}

