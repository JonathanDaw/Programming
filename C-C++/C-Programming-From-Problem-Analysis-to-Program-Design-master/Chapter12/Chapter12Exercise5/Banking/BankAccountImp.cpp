#ifndef H_BANKACCOUNT
#define H_BANKACCOUNT
#include "bankaccount.h"
#include <iostream>
#include <string>

class bankAccount {
public:
	virtual void makeDeposit(double deposit) = 0;
	virtual void withdrawMoney(double withdraw) = 0;
	virtual void monthlyStatement(double statement) = 0;

	void setName(std::string inputName) {
		name = inputName;
	}
	void setAccountNumber(int inputNumber) {
		accountNumber = inputNumber;
	}
	void setBalance(double inputBalance) {
		balance = inputBalance;
	}
	std::string getName() const {
		return name;
	}
	int getAccountNumber() const {
		return accountNumber;
	}
	double getBalance() const {
		return balance;
	}
	bankAccount(std::string name = "", int accountNumber = 0, double balance = 0) {

	}


private:
	std::string name;
	int accountNumber;
protected:
	double balance;
};

// A checking account inherits properties from a bank account + has these functions
class checkingAccount : public bankAccount {
	virtual void writeCheck(double) = 0;

	void bankAccount::makeDeposit(double deposit) {
		balance += deposit;
	}
	void bankAccount::withdrawMoney(double withdraw) {
		balance -= withdraw;
	}
	void bankAccount::monthlyStatement(double statement) {
		std::cout << balance << std::endl;
	}
};

// A service charge checking account inherits most of its properties from the standard checking account, however, the variable values will be different
class serviceChargeChecking : public checkingAccount {
public:
	void checkingAccount::writeCheck(double) {

	}

private:
	const int ALLOWED_CHECKS = 5;
	const double interestRate = 0;
	const double minimumBalance = 0;
};

// A no charge checking account inherits properties from a checking account, but with separate values than the service charge account
class noServiceChargeChecking : public checkingAccount {
public:
	void checkingAccount::writeCheck(double) {
		std::cout << balance << std::endl;
	}
private:
	const double interestRate = 2.7;
	const double minimumBalance = 5000.0;
	const int monthlyCharge = 0;
};

// The high interest checking inherits properties from a checking account, but contains different values than both the service charge & no service charge accounts
class highInterestChecking : public noServiceChargeChecking {
public:
	void checkingAccount::writeCheck(double) {
		std::cout << balance << std::endl;
	}

private:
	const double interestRate = 5.0;
	const double minimumBalance = 50000.0;
};

// A savings account inherits properties from the main bank account class. The interest rate is different amongst the various savings accounts
class savingsAccount : public bankAccount {
public:
	void bankAccount::makeDeposit(double) {
		std::cout << balance << std::endl;
	}

private:
	const double paidInterestRate = 2.0;
};

class highInterestSavings : public savingsAccount {
	const double minimumBalanceSavings = 50000.0;

};

// The COD class inherits properties from the main bank account class
class certificateOfDeposit : public bankAccount {
public:

private:
	int maturityMonths, currentMonth;
	double cdInterestRate;

};
#endif H_BANKACCOUNT