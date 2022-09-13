#ifndef PRINTMEFIRST_H
#define PRINTMEFIRST_H
/*
 * Define the headers information for Print Me First fuction
 */
 
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/* 
 * forward declaration - tells the compiler that the function
 * void printMeFirst(std::string name, std::string courseInfo) is defined 
 * else where so just go use it, and
 * it will be resolved during the linking time.
 * 
 */
 
void printMeFirst(std::string name, std::string courseInfo);

#endif
