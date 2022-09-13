
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include "display.h"
#include "dbconnect.h"


/*
 * Purpose: This methods displays wines 
 * displayed by score range and price range.
 * @param command - The mysql select command to display the wines
 * */
void displayScorePrice(string command)
{
	 MYSQL *conn;		// the connection
	  MYSQL_RES *res;	// the results
	  MYSQL_ROW row;	// the results row (line by line)
	 
	  struct connection_details mysqlD;
	  mysqlD.server = (char *)"localhost";  // where the mysql database is
	  mysqlD.user = (char *)"root";		// the root user of mysql	
	  mysqlD.password = (char *)"password"; // the password of the root user in mysql
	  mysqlD.database = (char *)"mysql";	// the databse to pick
	 
	  // connect to the mysql database
	  conn = mysql_connection_setup(mysqlD);
	  
	  
		 // use wine database
		 res = mysql_perform_query(conn, (char *)"use wine");
		 res = mysql_perform_query(conn, const_cast<char*> (command.c_str()));
		 
	  displayHeader();
	
	int count=0;
	double price=0;
	int totalscore=0;
	int rcount=0;
	double rprice=0;
	int rscore=0;
	int wcount=0;
	double wprice=0;
	int wscore=0;
	string w="White ";
	string r="Red ";


		
	  while (((row = mysql_fetch_row(res)) !=NULL))
	  {
		  count++;
		  totalscore=totalscore+stoi(row[2]);
		  price=price+stod(row[3]);
	      

		  if(((string)(row[4])).compare(w)==0)
		  {
			  wcount++;
			  wscore=wscore+stoi(row[2]);
			  wprice=wprice+stod(row[3]);
		  }
		  else if(((string)(row[4])).compare(r)==0)
		  {
			  rcount++;
			  rscore=rscore+stoi(row[2]);
			  rprice=rprice+stod(row[3]);
		  }
			  
			  /* print out each row of the data extracted from
			   * MySQL database
			   * Make sure the output is line up with the header
			   * Hint: use left and setw
			   */

		 cout << left << setw(40) << row[0]  << left << setw(14) // coulumn (field) #1 - Wine Name
		  << row[1] << left << setw(12) // field #2 - Vintage
		  << row[2] << left << setw(13) // field #3 - Rating
		 << row[3] << left << setw(10) // field #4 - Price
		  << row[4]  // field #5 - Wine type
		  << endl; // field #7 - UPC
	  }
	
	 displayAverage(count, price, totalscore, rcount, rprice, rscore, wcount, wprice, wscore, w, r);

	  /* clean up the database result set */
	  mysql_free_result(res);
	  /* clean up the database link */
	  mysql_close(conn);
}


/*
 * Purpose: This methods displays the topTen wines by price
 * @param command - The mysql select command to display ONLY the ten wines
 * */
void displayTopTen(string command)
{
	 MYSQL *conn;		// the connection
	  MYSQL_RES *res;	// the results
	  MYSQL_ROW row;	// the results row (line by line)
	 
	  struct connection_details mysqlD;
	  mysqlD.server = (char *)"localhost";  // where the mysql database is
	  mysqlD.user = (char *)"root";		// the root user of mysql	
	  mysqlD.password = (char *)"password"; // the password of the root user in mysql
	  mysqlD.database = (char *)"mysql";	// the databse to pick
	 
	  // connect to the mysql database
	  conn = mysql_connection_setup(mysqlD);
	  
	  
	 // use wine database
	 res = mysql_perform_query(conn, (char *)"use wine");
	 res = mysql_perform_query(conn, const_cast<char*> (command.c_str()));
	 
	 //prints header for table
	 displayHeader();
	  
	//initializing necessary variables to cout wines and display averages
	int count=0;
	double price=0;
	int totalscore=0;
	int rcount=0;
	double rprice=0;
	int rscore=0;
	int wcount=0;
	double wprice=0;
	int wscore=0;
	string w="White ";
	string r="Red ";

	//prints out the wines in price order decreasing and only the first 10 in the list
	  while (((row = mysql_fetch_row(res)) !=NULL) && count<10)
	  {
		  count++;
		  totalscore=totalscore+stoi(row[2]);
		  price=price+stod(row[3]);
	      

		  if(((string)(row[4])).compare(w)==0)
		  {
			  wcount++;
			  wscore=wscore+stoi(row[2]);
			  wprice=wprice+stod(row[3]);
		  }
		  else if(((string)(row[4])).compare(r)==0)
		  {
			  rcount++;
			  rscore=rscore+stoi(row[2]);
			  rprice=rprice+stod(row[3]);
		  }
			  
			  /* print out each row of the data extracted from
			   * MySQL database
			   * Make sure the output is line up with the header
			   * Hint: use left and setw
			   */

		 cout << left << setw(40) << row[0]  << left << setw(14) // coulumn (field) #1 - Wine Name
		  << row[1] << left << setw(12) // field #2 - Vintage
		  << row[2] << left << setw(13) // field #3 - Rating
		 << row[3] << left << setw(10) // field #4 - Price
		  << row[4]  // field #5 - Wine type
		  << endl; // field #7 - UPC
	  }
	
	 displayAverage(count, price, totalscore, rcount, rprice, rscore, wcount, wprice, wscore, w, r);

	  /* clean up the database result set */
	  mysql_free_result(res);
	  /* clean up the database link */
	  mysql_close(conn);
}
	
	
/*
 * Purpose: This methods displays wines 
 * that were just inserted or updated
 * @param command - The mysql update or insert command to edit the wines
 * @param command1 - The mysql select command to display the wines that were just inserted/updated
 * */
 void displayNewUpdate(string command, string command1)
 {	
	  MYSQL *conn;		// the connection
	  MYSQL_RES *res;	// the results
	  MYSQL_ROW row;	// the results row (line by line)
	 
	  struct connection_details mysqlD;
	  mysqlD.server = (char *)"localhost";  // where the mysql database is
	  mysqlD.user = (char *)"root";		// the root user of mysql	
	  mysqlD.password = (char *)"password"; // the password of the root user in mysql
	  mysqlD.database = (char *)"mysql";	// the databse to pick
	 
	  // connect to the mysql database
	  conn = mysql_connection_setup(mysqlD);
	  
	  
	 // use wine database
	 res = mysql_perform_query(conn, (char *)"use wine");
	 res = mysql_perform_query(conn, const_cast<char*> (command.c_str()));
	 res = mysql_perform_query(conn, const_cast<char*> (command1.c_str()));
	 
	 
	 //Table header
	 displayHeader();
	  
	//initialize variable for count of wines for average scores and price
	int count=0;
	double price=0;
	int totalscore=0;
	int rcount=0;
	double rprice=0;
	int rscore=0;
	int wcount=0;
	double wprice=0;
	int wscore=0;
	string w="White";
	string r="Red";

	//prints out wine table according to given command
	  while ((row = mysql_fetch_row(res)) !=NULL)
	  {
		  count++;
		  totalscore=totalscore+stoi(row[2]);
		  price=price+stod(row[3]);
	      
		//checks red or white wines
		  if(((string)(row[4])).compare(w)==0)
		  {
			  wcount++;
			  wscore=wscore+stoi(row[2]);
			  wprice=wprice+stod(row[3]);
		  }
		  else if(((string)(row[4])).compare(r)==0)
		  {
			  rcount++;
			  rscore=rscore+stoi(row[2]);
			  rprice=rprice+stod(row[3]);
		  }
			  
			  /* print out each row of the data extracted from
			   * MySQL database
			   * Make sure the output is line up with the header
			   * Hint: use left and setw
			   */

		 cout << left << setw(40) << row[0]  << left << setw(14) // coulumn (field) #1 - Wine Name
		  << row[1] << left << setw(12) // field #2 - Vintage
		  << row[2] << left << setw(13) // field #3 - Rating
		 << row[3] << left << setw(10) // field #4 - Price
		  << row[4]  // field #5 - Wine type
		  << endl; // field #7 - UPC
		  
	}
	  
	  //displays average of all wines, red wine, white wine
	displayAverage(count, price, totalscore, rcount, rprice, rscore, wcount, wprice, wscore, w, r);

	  
	  /* clean up the database result set */
	  mysql_free_result(res);
	  /* clean up the database link */
	  mysql_close(conn);
  }
  
  
/*
 * Purpose: This methods displays both types of wines average scores and prices
 * @param count - total amount of wines
 * @param price - total price of the wines
 * @param totalscore - total score of the wines
 * @param rcount - number of red wines
 * @param rprice - total price of red wines
 * @param rscore - total score of red wines
 * @param wcount - number of white wines
 * @param wprice - total price of white wines
 * @param wscore - total score of white wines
 * @param w - "White"
 * @param r - "Red"
 * */
  void displayAverage(int count, double price, int totalscore, int rcount, double rprice, int rscore, int wcount, double wprice, int wscore, string w, string r)
	{
		//all wines
	  cout << "\n----------------------------------\n"<< endl;
	  if(count==0)
	  {
		  cout << "Number of wines: 0" << endl;
	  }
	  else
	  {
		  cout << "Number of wines: " << count << endl;
		  cout << "Average Price: $" << fixed << setprecision(2) << price/count << endl;
		  cout << "Average Score: " << (int)(totalscore/count) << endl;
	  }
	  
	  //red wines
	  if(rcount==0)
	  {
		  cout << "Number of red wines: 0" << endl;
	  }
	  else
	  {
		  cout << "Number of red wines: " << rcount << endl;
		  cout << "Average red wine Price: $" << fixed << setprecision(2) << rprice/rcount << endl;
		  cout << "Average red wine Score: " << (int)(rscore/rcount) << endl;
	  }
	  
	  //white wines
	  if(wcount==0)
	  {
		  cout << "Number of white wines: 0" << endl;
	  }
	  else
	  {
		  cout << "Number of white wines: " << wcount << endl;
		  cout << "Average white wine Price: $" << fixed << setprecision(2) << wprice/wcount << endl;
		  cout << "Average white wine Score: " << (int)(wscore/wcount) << endl;
	  }
	  cout << "\n----------------------------------\n"<< endl;
  }



/*
 * Purpose: This methods displays header of wine table
 * */
	void displayHeader()
	{
		/*
		  * you need to print out the header.  Make sure it it 
		  * nicely formated line up.  Modify the cout statement
		  * below so the header is nicely line up.  Hint: use left and setw
		  * 
		  * WineName   Vitange  Rating  Price  Type
		  * */
		  
		  cout << " " << endl;
		 cout << left << setw(40) << "Wine Name" << left << setw(14)
						   << "Vintage" << left << setw(12)
							<< "Rating" << left << setw(13)
							<< "Price"  << left << setw(10)
							<< "Type" 
		 << endl;
		 
		 cout << left << setw(40) << "---------" << left << setw(14)
						   << "-------" << left << setw(12)
							<< "------" << left << setw(13)
							<< "-----"  << left << setw(10)
							<< "----" 
		 << endl;
		 
		 cout << " " << endl;
	 }
