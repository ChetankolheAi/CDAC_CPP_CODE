#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentAsset.h"

using namespace std;

class RealEstateTrust : public InvestmentAsset {
private:
    double rentalCapRate;
    double propertyAppreciationRate;
    double managementFeeRate;

public:

    RealEstateTrust(string ticker, string assetName, double initialPrincipal, double capRate, double appRate, double feeRate) : InvestmentAsset(ticker, assetName, initialPrincipal){
        rentalCapRate = capRate;
        propertyAppreciationRate = appRate;
        managementFeeRate = feeRate;
    }

    double calculateProjectedValue(int durationYears) override {
        double netRate = rentalCapRate + propertyAppreciationRate - managementFeeRate;
        return initialPrincipal * pow(1.0 + netRate, durationYears);
    }

    double calculateRiskScore(){
        return 3.5;
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double netGrowthPct = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        cout << "[Real Estate] " << assetTicker << " - " << assetName << "\n"
            << "  Initial Principal: $" << fixed << setprecision(2) << initialPrincipal << "\n"
            << "  Projected (" << durationYears << " Yrs): $" << projected
            << " (Net Growth: " << netGrowthPct << "%)\n"
            << "  Risk Score       : " << setprecision(2) << calculateRiskScore()
            << " / 10.00 (Low-Moderate Volatility)\n\n";
    }
};