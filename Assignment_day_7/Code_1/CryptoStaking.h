#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentAsset.h"

using namespace std;

class CryptoStaking : public InvestmentAsset {
private:
    double stakingAPY;
    double networkSlashingPenaltyRate;

public:

    CryptoStaking(string ticker, string assetName, double initialPrincipal, double apy, double penalty)
        : InvestmentAsset(ticker, assetName, initialPrincipal){
        stakingAPY = apy;
        networkSlashingPenaltyRate = penalty;

    }

    double calculateRiskScore() {
        double rawRisk = (stakingAPY * 100.0) + (networkSlashingPenaltyRate * 200.0);
        return min(10.0, rawRisk);
    }

    double calculateProjectedValue(int durationYears) override {
        double effectiveYield = stakingAPY - networkSlashingPenaltyRate;
        return initialPrincipal * pow(1.0 + effectiveYield, durationYears);
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double netGrowthPct = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        cout << "[Crypto Staking] " << assetTicker << " - " << assetName << "\n"
            << "  Initial Principal: $" << fixed << setprecision(2) << initialPrincipal << "\n"
            << "  Projected (" << durationYears << " Yrs): $" << projected
            << " (Net Growth: " << netGrowthPct << "%)\n"
            << "  Risk Score       : " << setprecision(2) << calculateRiskScore()
            << " / 10.00 (High Risk/Yield)\n\n";
    }
};