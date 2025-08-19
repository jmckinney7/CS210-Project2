#ifndef AIRGEAD_HEADER_BANKUTIL_H_
#define AIRGEAD_HEADER_BANKUTIL_H_
#define NOMINMAX

#include <iostream>
#include <string>
#include <Windows.h>

/*
	BankUtil:
	This header contains any utility methods needed for this program.

	AirgeadConsoleColors:
	This is an enumerator that contains WORD type color codes for the STD_HANDLE_OUTPUT handler.
	In other words, specific numbers are used to change the console to that color.

	validateNumericData:
	This double method is used to obtain the numerical value from a string value and return it as 
	a double.

	getValidatedPositiveInput:
	This method is used to make sure the number being input by the user is a real positive number.

	nCharString:
	Returns a string consisting of `t_n` characters of `t_c` (used for headers/separators).
*/

enum class AirgeadConsoleColors {
	Default = 7,
	Green = 10,
	Red = 12
	//I can add more here
};

class BankUtil {
public:
	BankUtil() = default; //explicit constructor
	static void changeConsoleColor(AirgeadConsoleColors t_color);
	static std::string nCharString(size_t t_n, char t_c);
	static double validateNumericalData(const std::string& t_inputData);
	static double getValidatedPositiveInput(const std::string& t_prompt);
};

#endif //AIRGEAD_HEADER_BANKUTIL_H_