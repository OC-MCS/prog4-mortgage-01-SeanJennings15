//=====================================================
// Sean Jennings
// 2/19/2019
// Programming 2, Assignment #4
// Description: Mortgage Payment
//=====================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Mortgage.h"

using namespace std;

bool parseFloat(string, double&);
bool parseInt(string sval, int& val);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	string tempInterestRate, tempLoanAmount; //hold the inputted values that will be tested for stof
	double interestRate, loanAmount;	//hold the interest rate and total amount of money on the mortgage
	string tempYears;	//holds the inputted value that will be tested for stoi
	int years;	//value for total years on the mortgage
	bool isNumber = false;	//set to false to stay in the input loop until valid data is given
	
	bool validInput = false;
	while (!validInput)
	{
		cout << "\nWhat is the total amount of your loan? " << endl;
		getline(cin, tempLoanAmount);
		
		if (!parseFloat(tempLoanAmount, loanAmount))
			cout << "\nPlease enter a number for the loan amount.";
		else if (loanAmount < 0)
			cout << "\nEnter a positive number for the loan.";
		else
			validInput = true;
	}

	validInput = false;
	while (!validInput)
	{
		cout << "\nWhat is the interest rate of your loan? " << endl;
		getline(cin, tempInterestRate);

		if (!parseFloat(tempInterestRate, interestRate))
			cout << "\nPlease enter a number for the interest rate.";
		else if (loanAmount < 0)
			cout << "\nEnter a positive number for the interestRate.";
		else
			validInput = true;
	}

	validInput = false;
	while (!validInput)
	{
		cout << "\nHow many years is the loan for? " << endl;
		getline(cin, tempYears);

		if (!parseInt(tempYears, years))
			cout << "\nPlease enter a number for the years on the loan.";
		else if (loanAmount < 0)
			cout << "\nEnter a positive number for the years on your loan.";
		else
			validInput = true;
	}

	Mortgage loanInfo(loanAmount, interestRate, years);
	
	cout << "\n\nThe monthly payment is: $" << loanInfo.monthlyPayment;
	cout << "\nThe total amount of money paid will be: $" << loanInfo.totalPaid;

	return 0;
}

//======================================================
// parseFloat: checks to see if the user's input can be converted to a float and converts if possible
// parameters: 
// string sval: input to be tested 
// int& val: reference returned input as a float if it can be converted
// return type: bool: true if the conversion to float was successful
//======================================================
bool parseFloat(string sval, double& val)
{
	double num;	//temporary int to carry the test string
	bool success = true;
	try
	{
		num = stof(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

//======================================================
// parseInt: checks to see if the user's input can be converted to an int and converts if possible
// parameters: 
// string sval: input to be tested 
// float& val: reference returned input as an int if it can be converted
// return type: bool: true if the conversion to int was successful
//======================================================
bool parseInt(string sval, int& val)
{
	int num;	//temporary int to carry the test string
	bool success = true;
	try
	{
		num = stoi(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}