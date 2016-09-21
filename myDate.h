//Author: Patrick Gagliano
//File: myDate.h
//Creation Date: February 10, 2015
//Due Date: March 5 Noon
//Course:  CSC 136
//Professor: Prof. Day
//Assignment Number: #2
//Purpose:  Allows a user to keep track of appointments by using the myDate class
#include <iostream>
#include "myTime.h"
using namespace std;

#ifndef MYDATE_H
#define MYDATE_H

class myDate
{
 public:
  //Default constructor
  //Sets month to 1, day to 1, year to 2015
  myDate();
 
  //Sets
  void setMonth(int mnth);
  void setDay(int dy);
  void setYear(int yr);
  void setTime(const myTime &tm);
 
  //Gets
  int getMonth() const;
  int getDay() const;
  int getYear() const;
  myTime getTime() const;
  
  //relational operators: compare full date and time
  //A later date/time is "greater" than an earlier one
  bool operator==(const myDate &date) const;
  bool operator<(const myDate &date) const;
  bool operator>(const myDate &date) const;
  bool operator<=(const myDate &date) const;
  bool operator>=(const myDate &date) const;
  bool operator!=(const myDate &date) const;
 
  //Name: compareDates
  //Description: It will compare two dates, not including the times
  //Parameters:  myDate secondDate - IN - the date to compare
  //Return: -1 if the instance is ealier than secondDate
  //         0 if the instance is the same date as secondDate
  //         1 if the instance is later than the secondDate
  int compareDates(const myDate &secondDate) const;
  
  //Name: operator+=
  //Description: Moves the date a head days days
  //Parameters:  days, the number of days to advance the date
  //Return: the instance of the object
  myDate &operator+=(int days);

  //Name: toLongDate
  //Description: creates a string for the date using the actual month name
  //             for example 1/2/2012 would return January 2, 2012
  //Return: the long version of the date
  string toLongDate();
  
 private:
  int month, day, year;
  myTime theTime;
  
  //Name: isLeapYear
  //Description: Determines if the year is a leap year
  //A year is a leap year under the following rules:
  //if not divisible by 4, it is not a leap year
  //if divisible by 4 and not 100, it is a leap year
  //if divisible by 4 and 100, it must be be divisible by
  //400 to be a leap year
  //Parameters: none
  //Return: true if leap year, false otherwise
  bool isLeapYear() const;

  //Name: daysInMonth
  //Description: uses the month and year to determine the total days
  //Paraemters: none
  //Return: the number of days in the month of the instance
  //remember that February depends on if it is a leap year
  int daysInMonth() const;
  
  //Name:convertIntToString
  //Description: Code included for your convenience: YOU DO NOT HAVE TO WRITE THIS FUNCTION
  //This function will return the string version of the integer it is passed
  //Parameters: int i - the interger to convert
  //Return: the string corresponding to the integer i
  string convertIntToString(int i);
};
  
//Name: operator<<
//Description: writes out the date in the form month/day/year hours:minutes
//Parameters:  ostream output - IN/OUT the stream written to
//             myDate date - IN - the date to write
//Return:     ostream - the stream written to
ostream &operator<<(ostream &output, const myDate &date);
  
//Name: operator>>
//Description: Expects the user to enter a date in the form month/day/year
//             reads ONLY the date part not the time
//Parameters:  istream input - IN/OUT the stream read from
//             myDate date - OUT the date to fill
//Return:     istream - the stream read from
istream &operator>>(istream &input, myDate &date);

#endif
