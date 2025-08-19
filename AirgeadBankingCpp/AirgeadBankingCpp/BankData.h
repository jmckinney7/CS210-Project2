#ifndef AIRGEAD_HEADER_BANKDATA_H_
#define AIRGEAD_HEADER_BANKDATA_H_

#include <iostream>
#include <string>

/*
	BankData:
	This header file contains a class that is used to collect user bank information based on:
	- interest rate
	- monthly deposit, 
	- initial investments
	- number of years

	Here are the following variables used for this data:
	- m_initialInvestmentAmount
	- m_monthlyDeposit
	- m_annualInterest
	- m_numberOfYears

	Private member:
	printDataInputHeader is a private helper method that I use inside the 
	'obtainUserData' public method.

	obtainUserData:
	This public method is used to obtain user data based on the private members through
	ostream prompts (cout).
*/

class BankData {
private:
	double m_initialInvestmentAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	unsigned int m_numberOfYears;
	void printDataInputHeader() const;

public:
	BankData();
	void setInitialInvestment(double t_initial);
	void setMonthlyDeposit(double t_mDeposit);
	void setAnnualInterestRate(double t_aInterest);
	void setNumberOfYears(unsigned int t_years);
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterestRate() const;
	unsigned int getNumberOfYears() const;
	void obtainUserData();
};

#endif //AIRGEAD_HEADER_BANKDATA_H_
