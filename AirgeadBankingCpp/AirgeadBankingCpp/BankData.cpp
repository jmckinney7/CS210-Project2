#include "BankData.h"
#include "BankUtil.h"

// @brief Prints the 'Data Input' page header
void BankData::printDataInputHeader() const
{
	const std::string TITLE = "Data Input";
	const std::string TOP_BORDER = BankUtil::nCharString(32, '*');
	const std::string P_BORDER = BankUtil::nCharString(10, '*');
	std::cout << TOP_BORDER << std::endl << P_BORDER << ' ' << TITLE << ' ' << P_BORDER << std::endl;
}

// @brief Basic constructor for BankData class
BankData::BankData()
{
	m_initialInvestmentAmount = 0;
	m_monthlyDeposit = 0;
	m_annualInterest = 0;
	m_numberOfYears = 0;
}

// @brief Sets initial investment to t_initial
void BankData::setInitialInvestment(double t_initial)
{
	m_initialInvestmentAmount = t_initial;
}

// @brief Set's monthly deposit to t_mDeposit
void BankData::setMonthlyDeposit(double t_mDeposit)
{
	m_monthlyDeposit = t_mDeposit;
}

// @brief Set's annual interest to t_aInterest
void BankData::setAnnualInterestRate(double t_aInterest)
{
	m_annualInterest = t_aInterest;
}

// @brief Set's number of years to t_years
void BankData::setNumberOfYears(unsigned int t_years)
{
	m_numberOfYears = t_years;
}

// @brief Returns initial investment
double BankData::getInitialInvestment() const
{
	return m_initialInvestmentAmount;
}

// @brief Returns monthly deposit
double BankData::getMonthlyDeposit() const
{
	return m_monthlyDeposit;
}

// @brief Returns annual interest rate
double BankData::getAnnualInterestRate() const
{
	return m_annualInterest;
}

// @brief Returns the number of years (amount)
unsigned int BankData::getNumberOfYears() const
{
	return m_numberOfYears;
}

// @brief Prompts user and collects validated bank input data.
void BankData::obtainUserData()
{
	printDataInputHeader();

	double initialInvestment = BankUtil::getValidatedPositiveInput("Initial Investment Amount: ");
	double monthlyDeposit = BankUtil::getValidatedPositiveInput("Monthly Deposit: ");
	double annualInterest = BankUtil::getValidatedPositiveInput("Annual Interest: ");
	int numberOfYears = static_cast<int>(BankUtil::getValidatedPositiveInput("Number of years: "));

	setInitialInvestment(initialInvestment);
	setMonthlyDeposit(monthlyDeposit);
	setAnnualInterestRate(annualInterest);
	setNumberOfYears(numberOfYears);
}
