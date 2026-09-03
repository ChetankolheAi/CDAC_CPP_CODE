#include<iostream>
#include"StudentRecord.h"
#include"FileIO.h";
using namespace std;
int main() {
	StudentRecord s;
	char wish;
	do {
		int Choice;
		cout << "\n Select Choice \n 1.Add New Student \n2.Display All Active Records \n3.Search Student By RollNumber";
		cin >> Choice;
		switch (Choice) {
		case 1:

			FileIO::WriteData();
			cout << "\nStudent Records Added " << endl;
			break;
		case 2:
			FileIO::ReadData();
			break;
		case 3:
			int RollNo;
			cout << "\nEnter the RollNo to Find :- ";
			cin >> RollNo;
			FileIO::FindStudent(RollNo);
			break;
		default:
			cout << "\nInvalid Input :- ";
		}

		cout << "\nDo you want to Continue :- ";
		cin >> wish;
	} while (wish == 'y' || wish == 'Y');


	return 0;
}