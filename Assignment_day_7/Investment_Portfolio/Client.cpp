#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentAsset.h"
#include "EquityStock.h"
#include "RealEstateTrust.h"
#include "CryptoStaking.h"
using namespace std;
int main() {
    int N, durationYears;
    cout << "=== AUTOMATED INVESTMENT PORTFOLIO & YIELD ANALYZER ===\n";
    cout << "Enter number of assets (N): ";
    cin >> N;
    cout << "Enter investment duration horizon (years): ";
    cin >> durationYears;
    cout << "\n";

    InvestmentAsset** portfolio = new InvestmentAsset * [N];

 
    for (int i = 0; i < N; ++i) {
        int type;
        string ticker, name;
        double principal;

        cout << "Asset #" << (i + 1) << " Entry\n";
        cout << "Select Type (1: Equity Stock, 2: REIT, 3: Crypto Staking): ";
        cin >> type;
        cout << "Enter Ticker: ";
        cin >> ticker;
        cin.ignore();
        cout << "Enter Asset Name: ";
        getline(cin, name);
        cout << "Enter Initial Principal ($): ";
        cin >> principal;

        if (type == 1) {
            double growth, divYield, beta;
            cout << "Enter Expected Annual Growth Rate (e.g. 0.10): "; cin >> growth;
            cout << "Enter Annual Dividend Yield (e.g. 0.015): "; cin >> divYield;
            cout << "Enter Beta: "; cin >> beta;
            portfolio[i] = new EquityStock(ticker, name, principal, growth, divYield, beta);
        }
        else if (type == 2) {
            double capRate, appRate, feeRate;
            cout << "Enter Rental Cap Rate (e.g. 0.05): "; cin >> capRate;
            cout << "Enter Property Appreciation Rate (e.g. 0.03): "; cin >> appRate;
            cout << "Enter Management Fee Rate (e.g. 0.01): "; cin >> feeRate;
            portfolio[i] = new RealEstateTrust(ticker, name, principal, capRate, appRate, feeRate);
        }
        else if (type == 3) {
            double apy, penalty;
            cout << "Enter Staking APY (e.g. 0.07): "; cin >> apy;
            cout << "Enter Network Slashing Risk Penalty (e.g. 0.005): "; cin >> penalty;
            portfolio[i] = new CryptoStaking(ticker, name, principal, apy, penalty);
        }
        cout << "-------------------------------------------\n";
    }

    cout << "\n==== PORTFOLIO PERFORMANCE REPORT ====\n\n";
    double totalInitial = 0.0;
    double totalProjected = 0.0;
    double weightedRiskSum = 0.0;

    for (int i = 0; i < N; ++i) {
        portfolio[i]->displayStatement(durationYears);

        double principal = portfolio[i]->getInitialPrincipal();
        double projected = portfolio[i]->calculateProjectedValue(durationYears);
        double risk = portfolio[i]->calculateRiskScore();

        totalInitial += principal;
        totalProjected += projected;
        weightedRiskSum += (risk * principal);
    }

    double totalProfit = totalProjected - totalInitial;
    double aggregateGrowthPct = (totalProfit / totalInitial) * 100.0;
    double weightedAvgRisk = weightedRiskSum / totalInitial;

   
    cout << "===========================================\n";
    cout << "PORTFOLIO AGGREGATE SUMMARY:\n";
    cout << "Total Invested Principal : $" << fixed << setprecision(2) << totalInitial << "\n";
    cout << "Total Projected Value    : $" << totalProjected << "\n";
    cout << "Total Projected Profit   : $" << totalProfit << " (+" << aggregateGrowthPct << "%)\n";
    cout << "Weighted Avg Risk Score  : " << setprecision(2) << weightedAvgRisk << " / 10.00\n";
    cout << "===========================================\n";

   
    for (int i = 0; i < N; ++i) {
        delete portfolio[i];
    }
    delete[] portfolio;
    portfolio = nullptr;

    cout << "\nMemory cleaned up successfully. " << N << " asset instances deallocated.\n";

    return 0;
}