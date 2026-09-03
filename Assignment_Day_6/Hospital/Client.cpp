#include<iostream>
#include"Patient.h"
#include"InPatient.h"
#include"OutPatient.h"
#include"EmergencyPatient.h"
#include<vector>
#include<string>
using namespace std;


void identifyAndProcessPatient(Patient* ptr) {
    if (!ptr) return;

    // First display polymorphic details
    ptr->displayPatientDetails();

    // RTTI dynamic_cast demonstration to access derived-specific members
    EmergencyPatient* eptr = dynamic_cast<EmergencyPatient*>(ptr);
    if (eptr != nullptr) {
        cout << ">> [RTTI MATCH] Identified as EmergencyPatient dynamically!" << endl;
        cout << ">> Additional Fee : $"
            << (eptr->getEmergencyServiceCharges() + eptr->getAmbulanceCharges()) << endl;
    }
    else {
        InPatient* iptr = dynamic_cast<InPatient*>(ptr);
        if (iptr != nullptr) {
            cout << ">> [RTTI MATCH] Identified as Standard InPatient." << endl;
        }
        else {
            cout << ">> [RTTI MATCH] Identified as OutPatient." << endl;
        }
    }
}
int main() {
    vector<Patient*> hospitalRecords;
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "      HOSPITAL BILLING SYSTEM           " << endl;
        cout << "========================================" << endl;
        cout << "1. Add In-Patient" << endl;
        cout << "2. Add Out-Patient" << endl;
        cout << "3. Add Emergency Patient" << endl;
        cout << "4. Display All Patients & Bills" << endl;
        cout << "5. Inspect Patient Record via RTTI" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            int id, age, days = 0;
            string name;

            cout << "Enter Patient ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Patient Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;

            if (choice == 1) { // InPatient
                double roomRate, consultation, meds;
                cout << "Days Admitted: "; cin >> days;
                cout << "Room Charge per Day: "; cin >> roomRate;
                cout << "Doctor Consultation Fee: "; cin >> consultation;
                cout << "Medicine Charges: "; cin >> meds;

                hospitalRecords.push_back(new InPatient(roomRate , meds , id, name, age, days, consultation));
                cout << "InPatient added successfully!\n";

            }
            else if (choice == 2) { // OutPatient
                double consultation, tests, meds;
                cout << "Doctor Consultation Fee: "; cin >> consultation;
                cout << "Days Admitted: "; cin >> days;

                cout << "Diagnostic Tests Charges: "; cin >> tests;
                cout << "Medicine Charges: "; cin >> meds;

                // Correct constructor call order:
                hospitalRecords.push_back(
                    new OutPatient(
                        id,
                        name,
                        age,
                        days,
                        consultation,
                        tests,
                        meds
                    )
                );
                cout << "OutPatient added successfully!\n";

            }
            else if (choice == 3) { // EmergencyPatient
                double roomRate, consultation, meds, emergencyCharges, ambCharges;
                string type;

                cout << "Days Admitted: "; cin >> days;
                cout << "Room Charge per Day: "; cin >> roomRate;
                cout << "Doctor Consultation Fee: "; cin >> consultation;
                cout << "Medicine Charges: "; cin >> meds;
                cout << "Emergency Service Fee: "; cin >> emergencyCharges;
                cout << "Ambulance Fee: "; cin >> ambCharges;
                cin.ignore();
                cout << "Type of Emergency (e.g., Trauma, Cardiac): ";
                getline(cin, type);

                hospitalRecords.push_back(new EmergencyPatient(emergencyCharges , ambCharges , roomRate , meds, id , name, age, days ,consultation));
                cout << "Emergency Patient added successfully!\n";
            }
        }
        else if (choice == 4) {
            if (hospitalRecords.empty()) {
                cout << "No patient records available.\n";
            }
            else {
                for (const auto& p : hospitalRecords) {
                    p->displayPatientDetails(); // Runtime Polymorphism
                }
            }
        }
        else if (choice == 5) {
            if (hospitalRecords.empty()) {
                cout << "No patient records available.\n";
            }
            else {
                int searchId;
                cout << "Enter Patient ID to inspect with RTTI: ";
                cin >> searchId;
                bool found = false;

                for (const auto& p : hospitalRecords) {
                    if (p->getPatientID() == searchId) {
                        identifyAndProcessPatient(p); // RTTI Demonstration
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Patient ID not found.\n";
            }
        }

    } while (choice != 6);

    // Clean up dynamically allocated memory
    for (auto p : hospitalRecords) {
        delete p; // Calls appropriate virtual destructor
    }
    hospitalRecords.clear();

    cout << "\nProgram exited. All allocated memory freed cleanly." << endl;
    return 0;

}