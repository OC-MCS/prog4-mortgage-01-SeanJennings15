// implementation file for Mortgage class
#include "Mortgage.h"
#include <cmath>

//======================================================
// Mortgage::Mortgage: constructor that accepts: total loan amount, interest rate, and years; then it calculates all term, monthly payment, and total payment for the mortgage
// parameters: 
// double inputLoanAmount: total amount inputted for the mortgage
// double inputInterestRate: interest rate inputted for the mortgage
// int inputYears: inputted total years for the mortage
// return type: constructor
//======================================================
Mortgage::Mortgage(double inputLoanAmount, double inputInterestRate, int inputYears)
{
	loanAmount = inputLoanAmount;
	years = inputYears;
	annualRate = inputInterestRate;

	getTerm(annualRate, years);
	getMonthlyPayment();
	getTotalPaid();
}

//======================================================
// Mortgage::getTerm(): calculates the term variable
// parameters: none
// return type: void
//======================================================
void Mortgage::getTerm(float annualRate, int years)
{
	term = pow((1 + (annualRate / 12)), (12 * years));
}

//======================================================
// Mortgage::getMonthlyPayment(): calculates the monthly payment
// parameters: none
// return type: void
//======================================================
void Mortgage::getMonthlyPayment()
{
	monthlyPayment = (loanAmount * (annualRate / 12) * term) / (term - 1);

	//return monthlyPayment;
}

//======================================================
// Mortgage::getTotalPaid(): multiplies the monthly payment by 12 * total years paying in order to get the total amount paid
// parameters: none
// return type: void
//======================================================
void Mortgage::getTotalPaid()
{
	totalPaid = monthlyPayment * 12 * years;
}