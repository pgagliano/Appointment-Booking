//Author: Patrick Gagliano
//Creation Date: February 10, 2015
//Description:  Defintions for the time methods

#include "myTime.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
//Starts time at 0:01
myTime::myTime()
{
  hours = 0;
  minutes = 1;
}

//This constructor takes initial minutes and hours
myTime::myTime(int hrs, int min)
{
  hours = hrs;
  minutes = min;
}

//gets and sets
//Sets provided for name, position and number only
void myTime::setMinutes(int mins) {minutes = mins;}
void myTime::setHours(int hrs) {hours = hrs;}
	
//gets provided for all data attributes
int myTime::getMinutes() const {return minutes;}
int myTime::getHours() const {return hours;}

//advances the time hrs hours
void myTime::addHours(int hrs)
{
  hours += hrs;
  simplifyTime();
}

//moves back the time hrs hours
void myTime::subtractHours(int hrs)
{
  hours -= hrs;
  simplifyTime();
}

//Displays the time in 12 hours form with am or pm
//The time of 3:45 would display as 3:45 am
//The time of 14:32 would display as 2:32 pm
void myTime::showClock() const
{
   if (hours == 0)
   {
	cout << 12 << ":" << setw(2) << setfill('0') << minutes << " am";
        return;
   }

  if (hours < 13)
    {
      if (hours < 12)
        cout << hours << ":" << setw(2) << setfill('0') << minutes << " am";
      else
	cout << hours << ":" << setw(2) << setfill('0') << minutes << " pm";
    }
  else
    {
      if (hours < 24)
	{
	  int hrs = hours -12;
	  cout << hrs << ":" << setw(2) << setfill('0') << minutes << " pm";
	}
    }
}

//finds the minutes between the instance time and the nextTime
//If nextTime after instance, returns -1
int myTime::timeDiff(const myTime &nextTime) const
{
  int mins;

  if (*this > nextTime)
    {
      if (minutes > nextTime.getMinutes())
	{
	  mins = minutes - nextTime.getMinutes();
	  mins += (hours - nextTime.getHours()) * 60;
	}
      else
	{
	  mins = (minutes + 60) - nextTime.getMinutes();
	  mins += (hours -1 - nextTime.getHours()) * 60;
	}
      return mins;
      
    }
  else
    return -1;
}

//All objects are compared by time of day
//First  by the hours then by the minutes
bool myTime::operator==(const myTime &tm) const
{
  return (hours == tm.getHours() && minutes == tm.getMinutes());
}

bool myTime::operator!=(const myTime &tm) const
{
  return (hours != tm.getHours() || minutes != tm.getMinutes());
}

bool myTime::operator<(const myTime &tm) const
{
  if (hours < tm.getHours())
      return true;
  else if (hours > tm.getHours())
      return false;
  else if (minutes < tm.getMinutes())
       return true;
  else
       return false;
}

bool myTime::operator>(const myTime &tm) const
{
  if (hours > tm.getHours())
      return true;
  else if (hours < tm.getHours())
      return false;
  else if (minutes > tm.getMinutes())
       return true;
  else
       return false;

}

bool myTime::operator>=(const myTime &tm) const
{
  if (*this > tm || *this == tm)
    return true;
  else
    return false;
}

bool myTime::operator<=(const myTime &tm) const
{
  if (*this < tm || *this == tm)
    return true;
  else
    return false;
}


//simplifies the time to make sure the hours and minutes
//are within the 24 hour clock
void myTime::simplifyTime()
{
  if (minutes >= 60)
    {
      minutes -= 60;
      hours += 1;
    }
  if (hours > 23)
    hours -= 24;

  if (minutes <0)
    {
      minutes += 60;
      hours -= 1;
    }
  if (hours < 0)
    hours += 24;
}

//moves the time forward min minutes
myTime &myTime::operator+=(int min)
{
  minutes += min;
  simplifyTime();
  return *this;
}

//moves the time back min minutes
myTime &myTime::operator-=(int min)
{
  minutes -= min;
  simplifyTime();
  return *this;
}



//overload of the stream output operator
//Displays time for the 24 hour clock in the form hours:minutes
ostream &operator<<(ostream &fileOut, const myTime &tm)
{
  fileOut << tm.getHours() << ":" << setw(2) << setfill('0') << tm.getMinutes();
  return fileOut;
}

//overload of the stream input operator
//Reads time from the input form hours:minutes
istream &operator>>(istream &fileIn, myTime &tm)
{
  int min, hr;
  char colon;

  fileIn >> hr >> colon >> min;
  tm.setHours(hr);
  tm.setMinutes(min);
  return fileIn;
}


