
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "displayByScore.h"
#include "display.h"
#include "dbconnect.h"

/**
 * Purpose: This program asks user a score range and all wines within that
 * score range will be displayed
 * */
void displayByScore()
{
	int x,y;
	  cout << "Enter in a range of wine scores to pick within. (0-100)" << endl;
		cout << "Starting value?" << endl;
		cin >> x;
		while(cin.fail() || x<0 || x>=100)
				{
					cout << "enter in a number (digits) and between 0-100" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> x;
				}
		
		cout << "Ending value?" << endl;
		cin >> y;
		while(cin.fail() || y<=0 || y>100)
				{
					cout << "enter in a number (digits) and between 0-100" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> y;
				}
				
		string pt1="select * from wineInfo where score between ";
		string xvar=to_string(x);
		string pt2=" and ";
		string yvar=to_string(y);
		string  pt3= " order by score";
		string equal="select * from wineInfo where score = ";
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
	
