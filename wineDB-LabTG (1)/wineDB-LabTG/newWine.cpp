
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "newWine.h"
#include "dbconnect.h"
#include "display.h"

/*
 * Purpose: Will insert a new wine with all user inputted information
 * into mysql table
 * */
void newWine()
{
	string name1; 
	int vintage1; 
	int rating1; 
	double price1; 
	string type1;
	
	  cout << "Enter in a name of wine to enter: " << endl;
	  cin.ignore();
		getline(cin, name1);
		while(cin.fail())
				{
					cout << "enter in a name" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					getline(cin, name1);
				}
		
		cout << "Enter in a vintage (year) (positive number) of wine to enter: " << endl;
		cin >> vintage1;
		while(cin.fail() || vintage1<0)
				{
					cout << "enter in a vintage (positive number)" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> vintage1;
				}
				
		cout << "Enter in a rating (postive number) of wine to enter: " << endl;
		cin >> rating1;
		while(cin.fail() || rating1<0)
				{
					cout << "enter in a rating (positive number)" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> rating1;
				}
				
		cout << "Enter in a price (positive number) of wine to enter: " << endl;
		cin >> price1;
		while(cin.fail() || price1<0)
				{
					cout << "enter in a price (positive number)" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> price1;
				}
				
		cout << "Enter in a type of wine to enter (Red or White): " << endl;
		cin >> type1;
		while(cin.fail() || (type1.compare("Red")!=0 && type1.compare("White")!=0))
				{
					cout << "enter in a type 'Red' or 'White'" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> type1;
				}
		
		
		//editing database table command	
		string pt1="insert into wineInfo (name, vintage, score, price, type) values ('";
		string pt2="', ";
		string pt4=", ";
		string pt5=", '";
		string vintage=to_string(vintage1);
		string rating=to_string(rating1);
		string price2=to_string(price1);
		string pt3="');";
		string command1=pt1+name1+pt2+vintage+pt4+rating+pt4+price2+pt5+type1+pt3;
		
		//Choosing the certain wine to diplay command
		string part1="select * from wineInfo where name= '";
		string part2="'";
		string command=part1+name1+part2;
		
		// will use sql statements to get info from database and print out wines
		displayNewUpdate(command1, command);
}
	

