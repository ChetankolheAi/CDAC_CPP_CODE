#pragma once
#include "Patient.h"
#include <iostream>
#include <string>

using namespace std;

class OutPatient : public Patient {
private:
    double diagnosticTestsFees;
    double medicineFees;

public:
    // Fixed syntax error in parameter list: double diagnosticTestsFees
    OutPatient(int patientID, string patientName, int age, int noOfDays,
        double consultationFees, double diagFees, double medFees)
        : Patient(patientID, patientName, age, noOfDays, consultationFees) {

        this->diagnosticTestsFees = diagFees;
        this->medicineFees = medFees;
    }

    // Override keyword added for safety and clarity
    double calculateBill() override {
        return getConsultationFees() + diagnosticTestsFees + medicineFees;
    }

    void displayPatientDetails() override {
        Patient::displayPatientDetails();
        cout << "Diagnostic Tests Fees : " << diagnosticTestsFees << endl;
        cout << "Medicine Fees         : " << medicineFees << endl;
        cout << "Total Bill            : " << calculateBill() << endl;
    }
};