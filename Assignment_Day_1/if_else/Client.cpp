#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "Enter The Number To Determine Positive / Negative / Zero :- ";
	cin >> n;
	if (n < 0)cout << "\nThe Number Is Negative";
	else if (n == 0)cout << "\nThe Number Is Zero";
	else cout << "\n The Number Is Positive";
	return 0;
}