
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "displayByPrice.h"
#include "display.h"
#include "dbconnect.h"

/*
 * Purpose: This program asks user a price range and all wines within that
 * price range will be displayed
 * */
void displayByPrice()
{
	int x,y;
	  cout << "Enter in a range of wine prices to pick within" << endl;
		cout << "Starting value?" << endl;
		cin >> x;
		while(cin.fail() || x<0)
				{
					cout << "enter in a number (digits) and positive prices" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> x;
				}
		
		cout << "Ending value?" << endl;
		cin >> y;
		while(cin.fail() || y<0)
				{
					cout << "enter in a number (digits) and positive prices" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> y;
				}
				
		string pt1="select * from wineInfo where price between ";
		string xvar=to_string(x);
		string pt2=" and ";
		string yvar=to_string(y);
		string  pt3= " order by price desc";
		string equal="select * from wineInfo where price = ";
		string command;
		
		
		if(x==y)
		{
			command=equal+xvar;
		}
		else
		{
			command=pt1+xvar+pt2+yvar+pt3;
		}
			
		// will use sql statements to get info from database and print out wines
		displayScorePrice(command);
	  
}
	
