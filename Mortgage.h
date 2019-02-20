#pragma once
// header file for Mortgage class

#include <string>

using namespace std;

class Mortgage
{
private:
	//int numerator;
	//int denominator;
	//void reduce();
	double loanAmount;
	double annualRate;
	double term;
	int years;
	
	void getTerm(float annualRate, int years);
	void getTotalPaid();
	void getMonthlyPayment();

public:
	
	double monthlyPayment;
	double totalPaid;

	Mortgage(double loan, double annualRate, int years);
	
};