//Author: Patrick Gagliano
//File: myDate.cpp
//Creation Date: February 10, 2015
//Due Date: March 5 Noon
//Course:  CSC 136
//Professor: Prof. Day
//Assignment Number: #2
//Purpose:  Allows a user to keep track of appointments by using the myDate class
#include "myDate.h"
#include "myTime.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

//Constructor
//Sets month to 1, day at 1 and year at 2015
myDate::myDate()
{
  month = 1;
  day = 1;
  year = 2015;
}

//Sets
void myDate::setMonth(int mnth) {month=mnth;}
void myDate::setDay(int dy) {day=dy;}
void myDate::setYear(int yr) {year=yr;}
void myDate::setTime(const myTime &tm) {theTime = tm;}

//Gets
int myDate::getMonth() const {return month;}
int myDate::getDay() const {return day;}
int myDate::getYear() const {return year;}
myTime myDate::getTime() const {return theTime;}

//Name: operator==
//Description: Will compare the full date and time
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator==(const myDate &date)const
{
  if (year == date.getYear() && month == date.getMonth() && day == date.getDay() && theTime == date.getTime())
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: operator<
//Description: Will compare dates with eachother
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator<(const myDate &date)const
{
  int result = compareDates(date);

  if(result == -1)
    {
      return true;
    }
  if(result == 1)
    {
      return false;
    }
  if(theTime < date.getTime())
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: operator>
//Description: Will compare dates with eachother
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator>(const myDate &date)const
{
  int result = compareDates(date);

  if(result == -1)
    {
      return true;
    }
  if(result == 1)
    {
      return false;
    }
  if(theTime > date.getTime())
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: operator<=
//Description: Will compare dates with eachother
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator<=(const myDate &date)const
{
  if(*this < date || *this == date)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: operator>=
//Description: Will compare dates with eachother
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator>=(const myDate &date)const
{
  if(*this > date || *this == date)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: operator!=
//Description: Will compare the full date and time
//Parameters: - const myDate &date
//Return: True / False - Boolean
bool myDate::operator!=(const myDate &date) const
{
  if (year != date.getYear() && month != date.getMonth() && day != date.getDay() && theTime != date.getTime())
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Name: compareDate
//Desscription: Will compare two dates without time
//Parameters: const myDate &secondDate
//Return: 1 if time is later than second date
//        0 if time is same as second date
//       -1 if time is earlier than second date
int myDate::compareDates(const myDate &secondDate)const
{
  if(year < secondDate.getYear())
    {
      return -1;
    }
  else if(year > secondDate.getYear())
    {
      return 1;
    }
  if(month < secondDate.getMonth())
    {
      return -1;
    }
  else if(month > secondDate.getMonth())
    {
      return 1;
    }
  if(day < secondDate.getDay())
    {
      return -1;
    }
  else if(day > secondDate.getDay())
    {
      return 1;
    }
  return 0;
}

//Name: operator+=
//Description: Will compare dates with eachother
//Parameters: int - days - number of days to advance
//Return: *this
myDate &myDate::operator+=(int days)
{
  day += days;
  
  if(day > daysInMonth())
    {
      day -= daysInMonth();
    }
  if(month < 12)
    {
      month++;
    }
  else
    {
      month =1;
      year++;
    }
  return *this;
}

//Name: toLongDate                   
//Description: converts int date format to string date format
//Return: longDate
//Parameters: None
string myDate::toLongDate()
{
  string longDate;
  string dy;
  string yr;

  switch (month)
    {
    case 1:
      longDate = "January "; break;
    case 2:
      longDate = "February "; break;
    case 3:
      longDate = "March "; break;
    case 4:
      longDate = "April "; break;
    case 5:
      longDate = "May "; break;
    case 6:
      longDate = "June "; break;
    case 7:
      longDate = "July "; break;
    case 8:
      longDate = "August "; break;
    case 9:
      longDate = "September "; break;
    case 10:
      longDate = "October "; break;
    case 11:
      longDate = "November "; break;
    case 12:
      longDate = "December "; break;
    }
   
  dy = convertIntToString(day);
  yr = convertIntToString(year);
  
  longDate += " ";
  longDate += dy;
  longDate += ", ";
  longDate += yr;

  return longDate;
}

//Name: isLeapYear                 
//Description: Determines if the year is a leap year
//if year not / 4 then false
//if year / 4 and not 100 then true
//if year / 4 and 100 and / 400 then true
//Parameters: none                                
//Return: true or false boolean                                     
bool myDate::isLeapYear()const
{  
  if (year % 4 == 0)
    {
      return true;
    }
  else if (year % 4 == 0 && year % 100 != 0) 
    {
      return true;
    }
  else if (year % 4 == 0 && year % 100 == 0) 
    {
      return false;
    }
  else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) 
    {
      return true;
    }
  else 
    {
      return false;
    }
}

//Name: daysInMonth
//Description: Determines total days in month
//Parameters: none
//Return: Number of days in month including leap year
int myDate::daysInMonth()const
{
  switch(month)
    {
    case 1:
    case 2: 
      if(isLeapYear())
	{
	  return 29;
	}
      else 
	{
	  return 28;
	}
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: return 31;
    default: return 30;
    }
}

//Name: convertInToString
//Description: will convert the integer to a string
//Parameters: int i
//Return: s
string myDate::convertIntToString(int i)
{
  string s;
  stringstream out;
  out << i;
  s = out.str();
  return s;

} 
 
//Name: <<operator
//Description: Writes out date in form mm/dd/yyyy and hours:minutes
//Parameters: ostream - output
//            myDate date - intput
//Return: ostream - stream outputted to
ostream &operator<<(ostream &output, const myDate &date)
{
  output<< date.getMonth() <<"/"<< date.getDay() <<"/" << date.getYear()<< " " << date.getTime(); 

  return output;
}

//Name: >>operator
//Description: Expects the user to enter the date in the form mm/dd/yyyy
//             Reads only the date
//Parameters: istream - input
//            myDate date - output
//Return: istream - stream read from dat file
istream &operator>>(istream &input, myDate &date)
{
  int mnth, dy, yr;
  char colon;

  input>>mnth>>colon>>dy>>colon>>yr;
  date.setMonth(mnth);
  date.setDay(dy);
  date.setYear(yr);
  
  return input;
}
