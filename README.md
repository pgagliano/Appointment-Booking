#CONTENTS OF THIS REPOSITORY
- Project
- Project Description
- Prerequisites
- Installing
- Troubleshooting

#Project: 
Apointment Book Scheduler

#Project Description: 
This appointment scheduler will allow users to read appointments in from a .dat file (date.dat) and perform the following actions: 
  - addAppointment() - Passed the array of dates and the size as a reference parameter.
    The function will ask the user for the time and day of the appointment.  
    It will use these values to set the date.  It will add the date to the next available spot in the array and increment the size.
    It will then call sort to sort the array.
  - viewAppointments() - Passed the array and the size of the array.The function will display all the appointments in the array to the screen.
  - showMissedAppointments() - Passed the array and the size of the array. The function will ask the user for the current date and time for a date object.  
    It will use that date to display all the appointments in the array that are earlier than the current date and time.
  - moveAllAppointments() - Passed the array and the size of the array. The function will ask the user the number of days to move the appointments.  
    It will then advance all the appointments in the array that number of days.
  - viewAllTodaysAppointments() - Passed the array and the size of the array. The function will ask the user for the current date and time for a date object.  
    It will then display the times for all the appointments for today.  The times should be displayed as the 12 hour clock time.

#Prerequisites:
Download all repository contents:
  - myTime.h
  - myTime.cpp
  - myDate.h
  - appointmentApp.cpp
  - date.dat
  
Download a free C++ IDE:
  - NetBeans
  - Eclipse 
  - Code:Blocks
  - Coding Ground (Online Compiler)

#Installing:
  - Download one of the programs as listed above. 
  - Download C++ repository source codes. 
  - Import repository folder.
  - Compile and run C++ program. 
  
#Troubleshooting:
  - IDE's will include debugging tools
