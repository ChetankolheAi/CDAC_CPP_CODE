#pragma once
#pragma once
#include"FlightTicket.h"
class FirstClassTicket :public FlightTicket {
private:
	double conciergeServiceFee;
public:
	FirstClassTicket(double cFees, string Pname, string Fnumber, double basefare, int baggageCount, double totalWeightKg) :FlightTicket(Pname, Fnumber, basefare, baggageCount, totalWeightKg) {
		conciergeServiceFee = cFees;
		
	}
	int calculatePenalty() {
		if (totalWeightKg >= 50) {
			return 100;
		}
		return 0;
	}
	double calculateTotalFare() {
		return baseFare + conciergeServiceFee + calculatePenalty();
	}
	void printBoardingPass() {
		cout << "[BOARDING PASS - ECONOMY CLASS]"<<endl;
		cout << "Passenger	     :" << passengerName << endl;
		cout << "Flight Number   :" << flightNumber << endl;
		cout << "Base Fare       :" << "$" << baseFare << endl;
		cout << "Concierge Fee   :" << "$ " << conciergeServiceFee << endl;
		cout << "Baggage Charge  :" << "$" << calculatePenalty() << endl;
		cout << "Total Fare      :" << "$" << calculateTotalFare() << endl;

	}
	
};
