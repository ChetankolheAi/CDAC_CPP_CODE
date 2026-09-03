#pragma once
#include<iostream>
#include<string.h>
#include<cstring>

using namespace std;
class Patient {
protected:
	int Patient_ID;
	string Patient_Name;
	int Age;
	int NoOfDaysAdmitted;
	double ConsultationFees;
public:
	Patient(int Patient_ID, string Patient_Name , int Age , int NoOfDaysAdmitted ,double ConsultationFees) {

		this->Patient_ID = Patient_ID;
		this->Patient_Name = Patient_Name;
		this->Age = Age;
		this->NoOfDaysAdmitted = NoOfDaysAdmitted;
		this->ConsultationFees = ConsultationFees;
	}
	virtual ~Patient() {}
	virtual double calculateBill() = 0;

	int getPatientID() const
	{
		return Patient_ID;
	}

	double getConsultationFees() const
	{
		return ConsultationFees;
	}
	virtual void displayPatientDetails() {
		cout << "\n----------------------------------------" << endl;
		cout << "Patient ID            :- " << Patient_ID << endl;
		cout << "Patient Name          :- " << Patient_Name << endl;
		cout << "Patient Age           :- " << Age << endl;
		cout << "No of Days Admitted   :- " << NoOfDaysAdmitted << endl;
	}
};