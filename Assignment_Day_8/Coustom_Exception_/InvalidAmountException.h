#pragma once
#include<iostream>
#include<string>
using namespace std;

class InvalidAmountException {
	
	public:
		string mssg;
		InvalidAmountException(string mssg) {
			this->mssg = mssg;

		}
		friend ostream& operator<<(ostream& out,
			const InvalidAmountException& e)
		{
			out << e.mssg;
			return out;
		}
};

