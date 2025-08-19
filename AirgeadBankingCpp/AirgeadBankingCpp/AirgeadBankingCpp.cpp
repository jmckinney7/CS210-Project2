#include <iostream>

#include "BankUtil.h"
#include "BankData.h"
#include "BankApp.h"

using namespace std;

/*
    Developed by: Joshua McKinney
    Start Date: 7/22/2025
    Course: CS-210
    Project Two: Airgead Banking
*/

int main()
{
    //ANSI Escape Sequence for changing window title
    std::cout << "\033]0;" << "Airgead Banking" << "\007";
    BankUtil::changeConsoleColor(AirgeadConsoleColors::Green); //Changed color to Green
    BankData myData; //My bank data
    BankApp::begin(myData); // starting app
    return 0;
}
