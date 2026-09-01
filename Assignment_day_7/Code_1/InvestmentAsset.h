#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class InvestmentAsset {
protected:
	string assetTicker;
	string assetName;
	double initialPrincipal;
public:
	InvestmentAsset(string ticker , string name, double principal){
		assetTicker = ticker;
		assetName = name;
		initialPrincipal = principal;
	}
	virtual ~InvestmentAsset() {}
	virtual double calculateProjectedValue(int durationYears) = 0;
	virtual double calculateRiskScore() = 0;
	virtual void displayStatement(int durationYears) = 0;
	double getInitialPrincipal() const { return initialPrincipal; }
	
};