#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

/*
Purpose- Print out the programmer's information such as name, class information,
and date/time when the program is run

@author Tanya Gupta
@version 1.0 2/3/2020

@param name- the name of the programmer
@param courseInfo- the name of the course
@return- none
*/

void printMeFirst(std::string name, std::string courseInfo)
{
	cout << "Program written by: " << name << endl;
	cout << "Course Info: " << courseInfo << endl;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "Date: " << dt << endl;
}
