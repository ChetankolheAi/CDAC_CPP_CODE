#pragma once
#include <iostream>
#include <string>
#include "FlightTicket.h"

using namespace std;

class EconomyTicket : public FlightTicket {
private:
    double extraBagFeePerKg;
    double seatSelectionFee;

public:
    EconomyTicket(double bFees, double seatFees, string Pname, string Fnumber, double basefare , int baggageCount, double totalWeightKg )
        : FlightTicket(Pname, Fnumber, basefare, baggageCount, totalWeightKg) {
        extraBagFeePerKg = bFees;
        seatSelectionFee = seatFees;
    }

    double calculatePenalty() {
        if (totalWeightKg <= 15 || baggageCount <= 0) return 0.0;

        int extraBaggageCount = baggageCount - 1;
        double weightPenalty = (totalWeightKg - 15) * extraBagFeePerKg;

        return weightPenalty + (50.0 * extraBaggageCount);
    }

    double calculateTotalFare() {
        return baseFare + seatSelectionFee + calculatePenalty();
    }

    void printBoardingPass() {
        cout << "[BOARDING PASS - ECONOMY CLASS]\n";
        cout << "Passenger       : " << passengerName << "\n";
        cout << "Flight Number   : " << flightNumber << "\n";
        cout << "Base Fare       : $" << baseFare << "\n";
        cout << "Seat Surcharge  : $" << seatSelectionFee << "\n";
        cout << "Baggage Charge  : $" << calculatePenalty() << "\n";
        cout << "Total Fare      : $" << calculateTotalFare() << "\n";
    }
};