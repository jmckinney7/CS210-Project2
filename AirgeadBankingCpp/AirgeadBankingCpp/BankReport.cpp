#include "BankReport.h"

// @brief Prints the bank report header (with custom titles)
void BankReport::printReportHeader(const std::string& t_title) const
{
	const int LINE_WIDTH = 60;
	int padding = static_cast<int>((LINE_WIDTH - t_title.length()) / 2);

	std::cout << BankUtil::nCharString(LINE_WIDTH, '=') << "\n"
		<< std::string(padding, ' ') << t_title << "\n"
		<< BankUtil::nCharString(LINE_WIDTH, '=') << "\n"
		<< std::setw(10) << "Year"
		<< std::setw(24) << "Year End Balance"
		<< std::setw(24) << "Interest Earned" << "\n"
		<< BankUtil::nCharString(LINE_WIDTH, '-') << "\n";
}

// @brief Prints a one line bank report based on year, annual balance, and interest earned
void BankReport::printReportDetails(int year, double yearEndBalance, double interestEarned) const
{
	std::cout << std::fixed << std::setprecision(2);

	std::cout << std::right 
		<< std::setw(2) << year 
		<< std::setw(20) << "$" << std::setw(9) << yearEndBalance
		<< std::setw(12) << "$" << std::setw(9) << interestEarned
		<< std::endl;
}

// @brief Basic constructor with a BankData param
BankReport::BankReport(const BankData& t_userData) : m_userBankData(t_userData) {}

// @brief Generates bank report without monthly deposit included
double BankReport::generateReportWithoutMonthlyDeposit(const std::string& t_title)
{
	printReportHeader(t_title);

	double balance = m_userBankData.getInitialInvestment();
	double monthlyRate = (m_userBankData.getAnnualInterestRate() / 100.0) / 12.0;
	int numberOfYears = m_userBankData.getNumberOfYears();
	double yearlyInterest = 0.0;

	for (unsigned int year = 1; year <= numberOfYears; ++year) {
		yearlyInterest = 0.0;

		for (unsigned int month = 1; month <= 12; ++month) {
			double interest = balance * monthlyRate;
			balance += interest;
			yearlyInterest += interest;
		}

		printReportDetails(year, balance, yearlyInterest);
	}

	return balance;
}

// @brief Generates a bank report with monthly deposit included
double BankReport::generateReportWithMonthlyDeposit(const std::string& t_title)
{
	printReportHeader(t_title);

	double balance = m_userBankData.getInitialInvestment();
	double monthlyRate = (m_userBankData.getAnnualInterestRate() / 100.0) / 12.0;
	int numberOfYears = m_userBankData.getNumberOfYears();
	double yearlyInterest = 0.0;

	for (unsigned int year = 1; year <= numberOfYears; ++year) {
		yearlyInterest = 0.0;

		for(unsigned int month = 1; month <= 12; ++month){
			balance += m_userBankData.getMonthlyDeposit();
			double interest = balance * monthlyRate;
			balance += interest;
			yearlyInterest += interest;
		}

		printReportDetails(year, balance, yearlyInterest);
	}

	return balance;
}

