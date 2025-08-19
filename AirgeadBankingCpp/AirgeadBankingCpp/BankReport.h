#ifndef AIRGEAD_HEADER_BANKREPORT_H_
#define AIRGEAD_HEADER_BANKREPORT_H_

#include "BankData.h"
#include "BankUtil.h"

#include <string>
#include <iomanip>

/*
	BankReport:
	This header contains a class called BankReport. This class handles displaying bank reports
	with or without monthly deposits.

	Private members:
	printReportHeader - Used to display custom header for report
	printReportDetails - Used like printDetails but instead is named printReportDetails

	Bank Report methods:
	generateReportWithoutMonthlyDeposit - Generates bank report without monthly deposit using user info
	generateReportWithMonthlyDeposit - Calculates and prints a bank report based on monthly deposits 
	and compound interest. Returns the final balance after all years.
*/

class BankReport {
private:
	BankData m_userBankData;
	void printReportHeader(const std::string& t_title) const;
	void printReportDetails(int t_year, double t_yearEndBalance, double t_interestEarned) const;

public:
	BankReport() = default;
	BankReport(const BankData& t_userData);
	double generateReportWithoutMonthlyDeposit(const std::string& t_title);
	double generateReportWithMonthlyDeposit(const std::string& t_title);
};

#endif //AIRGEAD_HEADER_BANKREPORT_H_