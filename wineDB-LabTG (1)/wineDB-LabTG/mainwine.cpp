
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "displayByScore.h"
#include "displayByPrice.h"
#include "printMeFirst.h"
#include "topTen.h"
#include "newWine.h"
#include "updateWine.h"
#include "dbconnect.h"

using namespace std;

int main()
{
	printMeFirst("Tanya Gupta", "Wine-SQL, Lab 8, Spring 2020");
	int number;
	
	while(number != 6)
	{
		cout << " Choose a number \n"
		     << "	1. Display all wines with scores between x and y \n"
		     << "	2. Display all wines with prices between x and y \n"
		     << "	3. Display top ten wines                         \n"
		     << "	4. Insert new wine                               \n"
		     << "	5. Update price of wine                          \n"
		     << "	6. Quit Program" << endl;
		     
		     cout << "Select number: ";
		     cin >> number;
		     cout << " " << endl;
		     
		     if(number==1)
		     { displayByScore();}
		     
		     else if(number==2)
		     { displayByPrice();}
		     
		     else if(number==3)
		     { topTen();}
		     
		     else if(number==4)
		     { newWine();}
		     
		     else if(number==5)
		     { updateWine();}
		     
		 
		 
	 }
	 
	 return 0;
 }
			
 
