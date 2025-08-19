#ifndef AIRGEAD_HEADER_BANKAPP_H_
#define AIRGEAD_HEADER_BANKAPP_H_

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "BankData.h"

using namespace std;

/*
	BankApp:
	This header file contains a class called BankApp that is responsible for program navigation.

	The begin() method houses the main functionality for navigating between the data input page
	and the bank report page.

	I used a enumerated class called MenuState to make this possible.

	Private member:
	pressKeyToContinue() is a method used to display the message for the user to press any key.
	This uses _getch(), which reads a single character from the console without requiring Enter.
*/

enum class MenuState {
	DataInput,
	Report
	//I can add more here.
};

class BankApp {
private:
	static void pressKeyToContinue();
public:
	BankApp() = default; //explicit constructor
	static void begin(BankData& t_userData);
};

#endif //AIRGEAD_HEADER_BANKAPP_H_