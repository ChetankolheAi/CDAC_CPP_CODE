#pragma once
#include<iostream>
#include<string>
using namespace std;

class InsufficientBalanceException {
public:
	string mssg;
	InsufficientBalanceException(string mssg) {
		this->mssg = mssg;
	}
	friend ostream& operator<<(ostream& out,
		const InsufficientBalanceException& e)
	{
		out << e.mssg;
		return out;
	}
};
