#include<iostream>
using namespace std;
int main() {
	int num1, num2;
	cout << "Enter the 2 numbers :- ";
	cin >> num1 >> num2;

	if (num1 > num2)cout << "\nNum1:="<<num1<<" is Greater than Num2:="<<num2<<endl;

	else if (num1 == num2)cout << "\n Both are Equal num1==num2 ";

	else cout << "\n Num2:="<<num2<<"is Greater than Num1:="<<num1<<endl;

	return 0;
}