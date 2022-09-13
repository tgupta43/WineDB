/*

http://www.codingfriends.com/index.php/2010/02/17/mysql-connection-example/

To compile up this program you will need to link to the mysql libraries and headers that are used within the program, e.g. mysql.h at the top of the program. To gain access to these, there is a nice mysql_config (you may need to install it via your package manager system if you do not have it already).

Here are my outputs of what is required on the command line for the g++ compiler



g++ -I/usr/include/mysql winedb.cpp -o winedb -L/usr/lib/mysql -lmysqlclient


./windb "select * from wineInfo where price > 100"

*/

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "dbconnect.h"
#include "printMeFirst.h"
#include "winemethods.h"

using namespace std;
 
 
 
 
/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
	
	printMeFirst("Tanya Gupta", "Wine-SQL, Lab 8, Spring 2020");
	
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
				cin >> x;
			}
	displayByScore(x, y);
 

  // assign the results return to the MYSQL_RES pointer
  if (argc < 2)
  {
     cout << "argv[0]: " << argv[0] << endl;
     printf("\nUsage: %s  \"SQL statement here\"\n", argv[0]);
     printf("if no argument given, default is:\n %s show tables\n", argv[0]);
     res = mysql_perform_query(conn, (char *)"show tables");
     printf("MySQL Tables in mysql database:\n");
  }
  else
  {
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     cout << "argv[0]: " << argv[0] << endl;
     cout << "argv[1]: " << argv[1] << endl;
     cout << " " << endl;
     cout << " " << endl;
     res = mysql_perform_query(conn, argv[1]);
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vitange  Rating  Price  Type
      * */
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

  while ((row = mysql_fetch_row(res)) !=NULL)
  {
      if (argc < 2) {
         printf("%s\n", row[0]);  // only print out 1st column
      }
      else
      {
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
  }
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;
}
