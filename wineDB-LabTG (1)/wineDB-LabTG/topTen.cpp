
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "displayByPrice.h"
#include "dbconnect.h"
#include "display.h"

/**
 * Purpose: This program displays top ten wines 
 * by price from highest price to lowest price
 * */
void topTen()
{
	  cout << "Here are top 10 wines by price (press enter): " << endl;
		
				
		string command="select * from wineInfo order by price desc";
		
		// will use sql statements to get info from database and print out wines
		displayTopTen(command);
			
				
				
	  
}
	
