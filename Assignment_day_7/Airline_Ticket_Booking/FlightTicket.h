#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class FlightTicket {
	protected:
		string passengerName;
		string flightNumber;
		double baseFare;
		int baggageCount;
		double totalWeightKg;
public:
	FlightTicket(string Pname, string Fnumber, double Bfare , int baggageCount , double totalWeightKg) {
		passengerName = Pname;
		flightNumber = Fnumber;
		baseFare = Bfare;
		this->baggageCount = baggageCount;
		this->totalWeightKg = totalWeightKg;
	}
	virtual double calculateTotalFare() = 0;
	virtual void printBoardingPass() = 0;
	
};