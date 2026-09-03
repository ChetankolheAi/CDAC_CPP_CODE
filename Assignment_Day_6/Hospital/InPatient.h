#pragma once
#include"Patient.h"
class InPatient : public Patient {
protected:
	double RoomCharges;
	double Medicine;
public:
	InPatient(double Rc , double med , int Patient_ID, string Patient_Name, int Age, int NoOfDaysAdmitted, double ConsultationFees):Patient(Patient_ID,Patient_Name, Age,NoOfDaysAdmitted, ConsultationFees){
		RoomCharges = Rc;
		Medicine = med;
	}

	double calculateBill() override {
		double Total = (RoomCharges*NoOfDaysAdmitted) + Medicine + ConsultationFees;
		return Total;
	}
	void displayPatientDetails() override {
		Patient::displayPatientDetails();
		cout << "RoomCharges          :- " << RoomCharges << endl;
		cout << "Medicine             :- " << Medicine << endl;
		cout << "Total Bill           :- " << calculateBill() << endl;
		
	}
};


