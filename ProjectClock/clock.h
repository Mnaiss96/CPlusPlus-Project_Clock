/* CS-210
*  Author: Michael Naiss
*  Project 1 Clock
*/ 

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std; // Using nameSpace 

class Clock {
public:
    // Function to print the selection menu
    void printMenu(); 
    // Function to display the main menu and handle user input
    void mainMenu(); 
    // Function to set the time
    void setTime(int currentHour, int currentMinute, int currentSecond);
    // Function to add hours
    void addHour(int hoursToAdd = 1);
    // Function to add minutes
    void addMin(int minutesToAdd = 1);
    // Function to add seconds
    void addSec(int secondsToAdd = 1);

private:
    // Private data members
    int hours = 0;
    int min = 0;
    int sec = 0;
    string suffix = "A M";

    // Private utility functions
    string get12HourFormat();
    string get24HourFormat();
    string twoDigitString(int num);
};

