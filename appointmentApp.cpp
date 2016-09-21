//Author: Patrick Gagliano
//File: appointmentApp.cpp  
//Creation Date: February 10, 2015 
//Purpose:  Allows a user to keep track of appointments by using the myDate class
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include "myDate.h"
#include "myTime.h"
using namespace std;

//Name: readAppointments
//Description: opens a file and reals all appoinments until
//             the end  of the file.  Then calls sort.
//Parameters:  dates - an array of myDate objects
//             size - updated when a values are added
//Return:      none
void readAppointments(myDate dates[], int &size);

//Name: sort
//Description: does a selection sort in ascending order
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void sort(myDate dates[], int size);

//Name: menu
//Description: Will alow user to choose from options
//Parameters: None
//Return: None
int menu();
void addAppointment(myDate dates[], int &size);
void viewAppointments(myDate dates[], int size);
void viewLongNames(myDate dates[], int size);
void showMissedAppointments(myDate dates[], int size);
void moveAllAppointments(myDate dates[], int size);
void viewAllTodaysAppointments(myDate dates[], int size);

int main()
{
  myDate dates[50];
  int size;
  int choice;

  readAppointments(dates, size); 
  sort(dates, size);
  while ((choice = menu()) != 7)
    {
      switch(choice)
	{
	case 1: addAppointment(dates, size); break;
	case 2: viewAppointments(dates, size); break;
	case 3: viewLongNames(dates, size); break;
	case 4: showMissedAppointments(dates, size); break;
	case 5: moveAllAppointments(dates,size); break;
	case 6: viewAllTodaysAppointments(dates, size); break;
	}
    }
  return 0;
}

//Name: readAppointments
//Description: opens a file and reals all appoinments until
//             the end  of the file.  Then calls sort.
//Parameters:  dates - an array of myDate objects
//             size - updated when a values are added
//Return:      none
void readAppointments(myDate dates[], int &size)
{
  ifstream f;
  string fname;
  size = 0;
  myDate aDate;
  myTime aTime;

  cout << "File: ";
  cin >> fname;
  f.open(fname.c_str());
  if (f.fail())
    {
      cout << "file failed to open" << endl;
      exit (0);
    }
  
  f >> aDate;
  while (!f.eof())
    {
      f >> aTime;
      aDate.setTime(aTime);
      dates[size] = aDate;
      size ++;
      f >> aDate;
    }
  sort(dates, size);
  f.close();
}

//Name: sort
//Description: does a selection sort in ascending order
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void sort(myDate dates[], int size)
{
  int first, min;
  myDate date;

  for (int i=0; i<size-1; i++)
    {
      min = i;
      for (int j=i+1; j<size; j++)
	if (dates[j] < dates[min])
	  min = j;

      date = dates[i];
      dates[i] = dates[min];
      dates[min] = date;
    }
  return;
}

//Name: addAppointment
//Description: Will add the date to the next available spot in the array 
//increment the size, and sort 
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void addAppointment(myDate dates[], int &size)
{
  myDate newDate;
  myTime newTime;

  cout<<"Please enter the time in hours:minutes format: ";
  cin >> newTime;

  cout<<"Please enter the date in mm/dd/yyyy format: ";
  cin >> newDate;

  newDate.setTime(newTime);

  dates[size] = newDate;
  size++;

  sort(dates, size);
 
  return;
}

//Name: viewAppointment
//Description: Will display all appointments
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void viewAppointments(myDate dates[], int size)
{
  for(int i = 0; i < size; i++)
    {
      cout<<dates[i]<<endl;
    }
  return;
}

//Name: viewLongNames
//Description: Will display all appointments in array to the screen in
//long date format
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void viewLongNames(myDate dates[], int size)
{
  for(int i = 0; i < size; i++)
    {
      cout<<dates[i].toLongDate() << " at ";
      dates[i].getTime().showClock();
      cout<<""<<endl;
    }
  return;
}

//Name: showMissedAppointments
//Description: Will display all appointments in the array that are earlier
//than the current date and time
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void showMissedAppointments(myDate dates[], int size)
{
  myDate aDate;
  myTime aTime;
  
  cout<<"Enter today's date: ";
  cin>>aDate;
  cout<<""<<endl;

  cout<<"Enter the time: ";
  cin>>aTime;
  cout<<""<<endl;

  aDate.setTime(aTime);

  for(int i = 0; i < size; i++)
    {
      if(aDate > dates[i])
	{
	  cout<<dates[i];
	  cout<<""<<endl;
	}
    }
  return;
}

//Name: moveAllAppointments
//Description: Will advance appointments in array that number of days
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void moveAllAppointments(myDate dates[], int size)
{
  int advance;

  cout<<"How many days do you want to advance your appointment?: ";
  cin>>advance;
  
  for(int i = 0; i <size; i++)
    {
      dates[i] += advance;
    }
  return;
}

//Name: viewAllTodaysAppointments
//Description: Will display all appointments for today
//Parameters: myDate dates[] - array of dates
//            int size - updated when value is added
//Return: None
void viewAllTodaysAppointments(myDate dates[], int size)
{
  myDate todaysDate;
  
  cout<<"Enter a date to check all appointments: ";
  cin>>todaysDate;
  
  for(int i = 0; i < size; i++)
    {
      if(todaysDate.compareDates(dates[i]) == 0)
	{
	  dates[i].getTime().showClock();
	}
      cout<<""<<endl;
    }
  return;
}

//Name: menu
//Description: Will select a choice base on user input
//Parameters: None
//Return: None
int menu()
{
  int choice;

  cout<<endl;
  cout<< "1. Add an appointment"<<endl;
  cout<< "2. View appointments"<<endl;
  cout<< "3. View long names" <<endl;
  cout<< "4. Show missed appointments"<<endl;
  cout<< "5. Move all appointments" <<endl;
  cout<< "6. View all of todays appointments" <<endl;
  cin>>choice;

  return choice;
}
