
#ifndef DISPLAY_H
#define DISPLAY_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/**
 * Purpose: This methods displays wines 
 * displayed by score range and price range.
 * @param command - The mysql select command to display the wines
 * */
void displayScorePrice(string command);


/**
 * Purpose: This methods displays the topTen wines by price
 * @param command - The mysql select command to display ONLY the ten wines
 * */
void displayTopTen(string command);


/**
 * Purpose: This methods displays wines 
 * that were just inserted or updated
 * @param command - The mysql update or insert command to edit the wines
 * @param command1 - The mysql select command to display the wines that were just inserted/updated
 * */
void displayNewUpdate(string command, string command1);


/**
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
void displayAverage(int count, double price, int totalscore, int rcount, double rprice, int rscore, int wcount, double wprice, int wscore, string w, string r);


/**
 * Purpose: This methods displays header of wine table
 * */
void displayHeader();
 

 
#endif
