#include "BankUtil.h"

// @brief Can change console color based on predefined enum options
void BankUtil::changeConsoleColor(AirgeadConsoleColors t_color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(t_color));
}

// @brief Returns a string of size t_n characters of t_c
std::string BankUtil::nCharString(size_t t_n, char t_c) {
	return std::string(t_n, t_c);
}

// @brief Returns a validated double value based from user input
double BankUtil::validateNumericalData(const std::string& t_inputData)
{
	double result = 0;
	bool decimalFound = false;
	std::string cleanedData;

	for (unsigned int i = 0; i < t_inputData.length(); ++i) {
		char l = t_inputData[i];

		if (isdigit(l)) {
			cleanedData += l;
		}
		else if ((l == '.') && (!decimalFound)) {
			cleanedData += l;
			decimalFound = true;
		}
		else if ((l == '-') && i == 0) {
			cleanedData += l;
		}
	}

	if (cleanedData.empty() || cleanedData == "." || cleanedData == "-") {
		//Exception here
		throw std::invalid_argument("Input does not contain a valid number.");
	}

	result = std::stod(cleanedData);

	if (result <= 0.0) {
		//Exception here
		throw std::invalid_argument("Value must be greater than 0.");
	}

	return result;
}

// @brief Returns a validated positive real number based on user input
double BankUtil::getValidatedPositiveInput(const std::string& t_prompt)
{
	std::string input;
	double result = 0;
	bool valid = false;

	while (!valid) {
		std::cout << t_prompt;
		std::getline(std::cin, input);

		try {
			result = validateNumericalData(input);
			valid = true;
		}
		catch (const std::invalid_argument& e) {
			changeConsoleColor(AirgeadConsoleColors::Red);
			std::cout << "Invalid input: " << e.what() << " Please try again.\n";
			changeConsoleColor(AirgeadConsoleColors::Green);
		}
	}

	return result;
}
