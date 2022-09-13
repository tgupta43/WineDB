
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "updateWine.h"
#include "dbconnect.h"
#include "display.h"


/**
 * Purpose: Will update the price of a wine that user
 * wants to change it to
 * */
void updateWine()
{
	string name1;
	double price1;
	  cout << "What is the name of the wine whose price you want to update?" << endl;
		cin.ignore();
		getline(cin, name1);
		while(cin.fail())
				{
					cout << "enter in a name" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					getline(cin, name1);
				}
		
		cout << "What is the new price?" << endl;
		cin >> price1;
		while(cin.fail() || price1<0)
				{
					cout << "enter in a number (digits)" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> price1;
				}
		
		//update and edit a wine command		
		string pt1="update wineInfo set price = ";
		string price2=to_string(price1);
		string pt2=" where name = ";
		string  pt3= "'";
		string command=pt1+price2+pt2+pt3+name1+pt3;
		
		//Choosing the certain wine to diplay command
		string part1="select * from wineInfo where name= '";
		string part2="'";
		string command1=part1+name1+part2;
		
		
	// will use sql statements to get info from database and print out wines
	displayNewUpdate(command, command1);
}
	
