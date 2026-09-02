#pragma once
#pragma once
#include"FlightTicket.h"
class BusinessTicket :public FlightTicket {
private:
	double loungeAccessFee;
	double priorityBoardingFee;
public:
	BusinessTicket(double LAfees, double PBfees, string Pname, string Fnumber, double basefare, int baggageCount, double totalWeightKg) :FlightTicket(Pname, Fnumber, basefare, baggageCount, totalWeightKg) {
		loungeAccessFee = LAfees;
		priorityBoardingFee = PBfees;
	}
	int calculatePenalty() {
		int ExcessWeight = totalWeightKg - 32;
		if (ExcessWeight>0) {
			return ExcessWeight * 20;
		}
		return 0;
	}
	double calculateTotalFare( ) {
		return baseFare + loungeAccessFee + priorityBoardingFee + calculatePenalty();
	}
	void printBoardingPass() {
		cout << "[BOARDING PASS - ECONOMY CLASS]" << endl;
		cout << "Passenger	     :" << passengerName<<endl;
		cout << "Flight Number   :" << flightNumber << endl;
		cout << "Base Fare       :" << "$" << baseFare << endl;
		cout << "VIP Amenities   :" << "Louge "<<loungeAccessFee <<"+ Priority Boarding "<< priorityBoardingFee << endl;
		cout << "Baggage Charge  :" << "$" << calculatePenalty() << endl;
		cout << "Total Fare      :" << "$" << calculateTotalFare() << endl;

	}
};
