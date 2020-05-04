#ifndef H_BANKACCOUNT
#define H_BANKACCOUNT
#include "bankaccount.h"
#include <iostream>
#include <string>


class bankAccount {
public:
	void setName(std::string inputName);
	void setAccountNumber(int accountNumber);
	void setBalance(double balance);
	std::string getName() const;
	int getAccountNumber() const;
	double getBalance() const;

	virtual void makeDeposit(double) = 0;
	virtual void withdrawMoney(double) = 0;
	virtual void monthlyStatement(double) = 0;
	bankAccount(std::string name = "", int accountNumber = 0, double balance = 0);

private:
	std::string name;
	int accountNumber;
	double balance;
};

class checkingAccount : public bankAccount {
public:
	virtual void writeCheck(double) = 0;
	void bankAccount:: makeDeposit(double);
	void bankAccount:: withdrawMoney(double);
	void bankAccount:: monthlyStatement(double);
};

class serviceChargeChecking : public checkingAccount {
public:
	void checkingAccount::writeCheck(double);

private:
	const int ALLOWED_CHECKS = 5;
	const double interestRate = 0;
	const double minimumBalance = 0;
};

class noServiceChargeChecking : public checkingAccount {
public:
	void checkingAccount::writeCheck(double);
private:
	const double interestRate = 2.7;
	const double minimumBalance = 5000.0;
	const int monthlyCharge = 0;
};

class highInterestChecking : public noServiceChargeChecking {
public:
	void checkingAccount::writeCheck(double);

private:
	const double interestRate = 5.0;
	const double minimumBalance = 50000.0;
};

class savingsAccount : public bankAccount {
public:
	void bankAccount::makeDeposit(double);

private:
	const double paidInterestRate = 2.0;
};

class highInterestSavings : public savingsAccount {
	const double minimumBalanceSavings = 50000.0;

};

class certificateOfDeposit : public bankAccount {
public:

private:
	int maturityMonths, currentMonth;
	double cdInterestRate;

};


#endif H_BANKACCOUNT