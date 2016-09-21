//Author: Patrick Gagliano
//File: myTime.h
//Creation Date: February 10, 2015
//Due Date: March 5 Noon
//Course:  CSC 136
//Professor: Prof. Day
//Assignment Number: #2
//Description:  Declares a class to store hours and minutes for a 24 hour clock

#include <iostream>
using namespace std;

#ifndef MYTIME_H
#define MYTIME_H

class myTime
{
public:
  //constructor 
  //myTime
  //Initializes hours to 24 and minutes to 1
	myTime();

	//Initializes hours to hrs and minutes to mins
	myTime(int hrs, int min);

	//gets and sets
	//Sets provided for hours and minutes
	void setMinutes(int mins);
	void setHours(int hrs);
	void setTime(const myTime &tm);

	//gets provided for hours and minutes
	int getMinutes() const;
	int getHours() const;
	myTime getTime() const;

	//Name: addHours
	//Description: advances the time hrs hours
	//Parameters: int hrs - IN number of hours to advance
	//Return: none
	void addHours(int hrs);
	
	//Name: subtractHours
	//Description: moves back the time hrs hours
	//Parameters: int hrs - IN hours to subtrace
	//Return: none
	void subtractHours(int hrs);

	//Name: showClock
	//Description: Displays the time in 12 hours form with am or pm
	//13:10 would be 1:10 pm
	//Paramters: none
	//Return: none
	void showClock() const;

	//Name: timeDiff
	//Description: finds the number of minutes from the instance time to the time passed in nextTime
	//expects nextTime to be later
	//if nextTime is after the time of the instance it returns -1
	//Parameters:  myTime nextTime - IN the time to figure difference from
	//Return: number of minutes between or -1 if order wrong
	int timeDiff(const myTime &nextTime) const;

	//All objects are compared by the time of day
	//earlier in the day means "less than"
	bool operator==(const myTime &tm) const;
	bool operator!=(const myTime &tm) const;
	bool operator<(const myTime &tm) const;
	bool operator>(const myTime &tm) const;
	bool operator>=(const myTime &tm) const;
	bool operator<=(const myTime &tm) const;

	//Name: operator+=
	//Description: advances the time min minutes
	//Parameters: int min - IN minutes to advance
	//Return: the object itself
	myTime &operator+=(int min);
	
	//Name: operator -=
	//Description: moves the time back min minutes
	//Parameters: int min - IN the number minutes to subtract
	//Return: the object itself
	myTime &operator-=(int min);


private:
	int hours, minutes;

	//Name: simplifyTime
	//Description: simplifies the time making sure the hours and minutes fit the 24 hour clock
	//Parameters: none
	//Return: none
	void simplifyTime();
};

//overload of the stream output operator
//Displays all data in nice, neat form. 
//hours:minutes
ostream &operator<<(ostream &fileOut, const myTime &tm);

//overload of the stream input operator
//Reads time in the input form hours:minutes
istream &operator>>(istream &fileIn, myTime &tm);

#endif
