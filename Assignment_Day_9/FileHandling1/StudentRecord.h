#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class StudentRecord {
private:
	int RollNo;
	char name[50];
	char Dept[20];
	float cgpa;
	bool status;
public:
	StudentRecord() {
		RollNo = 0;
		strcpy_s(name, "");
		strcpy_s(Dept, "");
		cgpa = 0.0f;
		status = false;
	}
	StudentRecord(int RollNo, char name[50], char Dept[50], float cgpa, bool status) {

		this->RollNo = RollNo;
		strcpy_s(this->name, name);
		strcpy_s(this->Dept, Dept);
		this->cgpa = cgpa;
		this->status = status;
	}
	void Display() {

		if (status == 1) {
			cout << "Student Data of Rollno :- " << RollNo << endl;
			cout << "Name	  		    	:" << name << endl;
			cout << "Department			    : " << Dept << endl;
			cout << "CGPA				    : " << cgpa << endl;
			if (status)
				cout << "Status		       		: Active" << endl;
			else
				cout << "Status			    	: InActive" << endl;
		}


	}
	void Accept() {
		cout << "Enter RollNo :- ";
		cin >> RollNo;
		cout << "\n Enter the name :- ";
		cin >> name;
		cout << "\nEnter the Dept :- ";
		cin >> Dept;
		cout << "\nEnter the cgpa :- ";
		cin >> cgpa;
		cout << "\nEnter the status :- ";
		cin >> status;
	}
	void SearchStudent(int StdRollNo) {
		if (StdRollNo == RollNo) {
			cout << "Student Data of Rollno :- " << RollNo << endl;
			cout << "Name	  		    	:" << name << endl;
			cout << "Department			    : " << Dept << endl;
			cout << "CGPA				    : " << cgpa << endl;
			if (status)
				cout << "Status		       		: Active" << endl;
			else
				cout << "Status			    	: InActive" << endl;
		}
		else {
			cout << "\n Student Not Found " << endl;
		}
	}
};