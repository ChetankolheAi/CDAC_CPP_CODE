#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include "InvestmentAsset.h"

using namespace std;

class EquityStock : public InvestmentAsset {
protected:
    double annualGrowthRate;
    double dividendYield;
    double beta;

public:
    EquityStock(string ticker, string assetName, double initialPrincipal, double expectedGrowth, double divYield, double betaVal): InvestmentAsset(ticker, assetName, initialPrincipal)
    {
        annualGrowthRate = expectedGrowth;
        dividendYield = divYield;
        beta = beta;

    }

    double calculateProjectedValue(int durationYears) override {
        double totalReturn = annualGrowthRate + dividendYield;
        double base = 1.0 + totalReturn;

        if (base < 0.0) {
            base = 0.0;
        }

        return initialPrincipal * std::pow(base, durationYears);
    }

    double calculateRiskScore()  {
        return min(10.0, max(1.0, beta * 4.5));
    }

    void displayStatement(int durationYears) override {
        double projected = calculateProjectedValue(durationYears);
        double netGrowthPct = ((projected - initialPrincipal) / initialPrincipal) * 100.0;

        cout << "[Equity Stock] " << assetTicker << " " << assetName << "\n"
            << "  Initial Principal: $" << fixed << setprecision(2) << initialPrincipal << "\n"
            << "  Projected (" << durationYears << " Yrs): $" << projected
            << " (Net Growth: " << netGrowthPct << "%)\n"
            << "  Risk Score       : " << setprecision(2) << calculateRiskScore()
            << " / 10.00 (Volatility Benchmark)\n\n";
    }
};