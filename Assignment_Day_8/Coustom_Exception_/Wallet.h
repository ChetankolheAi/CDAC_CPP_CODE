#pragma once
#include<iostream>
#include"InsufficientBalanceException.h"
#include"InvalidAmountException.h"
using namespace std;

class Wallet {

private:

	int walletID;
	string holderName;
	double balance;
public:
	Wallet() {
		walletID = 0;
		holderName = "";
		balance = 0.0;
	}
	//void accept() {
	//	cout << "\nEnter the Wallet ID :- ";
	//	cin >> walletID;
	//	cout << "\n Enter Holder Name :- ";
	//	cin >> holderName;
	//	cout << "\n Enter The Balance :- ";
	//	cin >> balance;
	//}
	//void display() {
	//	cout << "Wallet ID    :" << walletID<<endl;
	//	cout << "Holder Name  : " << holderName << endl;
	//	cout << "Balance      :" << balance << endl;
	//}

	friend istream& operator>>(istream& in, Wallet& w)
	{
		cout << "\nEnter the Wallet ID :- ";
		in >> w.walletID;

		cout << "\nEnter Holder Name :- ";
		in >> w.holderName;

		cout << "\nEnter The Balance :- ";
		in >> w.balance;

		return in;
	}

	friend ostream& operator<<(ostream& out, const Wallet& w)
	{
		out << "Wallet ID    : " << w.walletID << endl;
		out << "Holder Name  : " << w.holderName << endl;
		out << "Balance      : " << w.balance << endl;

		return out;
	}
	void depositMoney(int amount) {
		if (amount < 0) {
			throw InvalidAmountException("Invalid Amount");
		}
		balance += amount;
		cout << "\n Balance :- " << balance << endl;
	}

	void withdrawMoney(int amount) {
		if (amount < 0) {
			throw InvalidAmountException("Invalid Amount");
		}
		else if (amount <= balance) {
			balance -= amount;
			cout << "\n Balance :- " << balance << endl;

		}
		else {
			throw InsufficientBalanceException("Insufficient Balance");
		}
	}
	

};