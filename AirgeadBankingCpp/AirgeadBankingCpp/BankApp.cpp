#include "BankApp.h"
#include "BankReport.h"

// @brief Prompts user to press any key to continue (next page)
void BankApp::pressKeyToContinue()
{
	cout << "Press any key to continue..." << endl;
	(void)_getch();
	system("cls");
}

// @brief starts the bank application (the brain of the program)
void BankApp::begin(BankData& t_userData)
{
	MenuState state = MenuState::DataInput;

	while (true) {
		switch (state) {
		case MenuState::DataInput:
			t_userData.obtainUserData();
			state = MenuState::Report;
			break;
		case MenuState::Report:
			BankReport report(t_userData);

			auto grwithoutmd = report.generateReportWithoutMonthlyDeposit("Bank Report Without Monthly Deposit");

			//BANK REPORT WITH MONTHLY DEPOSIT
			auto grwithmd = report.generateReportWithMonthlyDeposit("Bank Report With Monthly Deposit");

			cout << endl;
			cout << "Final Balance without monthly deposit: $" << grwithoutmd << endl
				 << "Final Balance with monthly deposit: $" << grwithmd << endl;

			state = MenuState::DataInput;
			break;
		}

		pressKeyToContinue();
	}
}
