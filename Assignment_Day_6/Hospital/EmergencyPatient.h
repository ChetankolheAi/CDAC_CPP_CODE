#pragma once
#include"InPatient.h"

class EmergencyPatient : public InPatient {
private:
	double emergencyCharges;
	double ambulanceCharges;
public:
	EmergencyPatient(double emergencyCharges , double ambulanceCharges , double Rc, double med, int Patient_ID, string Patient_Name, int Age, int NoOfDaysAdmitted, double ConsultationFees) :InPatient( Rc,  med,  Patient_ID,  Patient_Name,  Age,  NoOfDaysAdmitted,  ConsultationFees){
		this->emergencyCharges = emergencyCharges;
		this->ambulanceCharges = ambulanceCharges;

	}
	double calculateBill() override {
		double Total = RoomCharges + Medicine + ConsultationFees + emergencyCharges + ambulanceCharges;
		return Total;
	}
	void displayPatientDetails() override {
		InPatient::displayPatientDetails();
		cout << "RoomCharges                :- " << RoomCharges << endl;
		cout << "Medicine                   :- " << Medicine << endl;
		cout << "Total Bill With Emergency  :- " << calculateBill() << endl;

	}
	double getEmergencyServiceCharges() const {
		return emergencyCharges;
	}
	double getAmbulanceCharges()const {
		return ambulanceCharges;
	}
};