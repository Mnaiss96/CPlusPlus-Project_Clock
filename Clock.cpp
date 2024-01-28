#include "Clock.h"

// Function to print the menu options
void Clock::printMenu() {
    cout << "\n***************************\n";
    cout << "* 1 - Add One Hour\t  *\n";
    cout << "* 2 - Add One Minute\t  *\n";
    cout << "* 3 - Add One Second\t  *\n";
    cout << "* 4 - Exit Program\t  *\n";
    cout << "***************************\n";
}

// Function to display the main menu and handle user input
void Clock::mainMenu() {
    int userInput = 0;
    // Continue displaying the menu until the user chooses to exit
    while (userInput != 4) {
        cout << "***************************\t\t***************************\n";
        cout << "*\t12-Hour Clock\t  *\t\t*\t24-Hour Clock\t  *\n";
        cout << "*\t" << setw(2) << setfill('0') << get12HourFormat() << "\t  *\t\t";
        cout << "*\t  " << setw(2) << setfill('0') << get24HourFormat() << "\t  *\n";
        cout << "***************************\t\t***************************\n";
        
        printMenu(); // Display the menu options
        cin >> userInput; // Get user input
        switch (userInput) {
            case 1:
                addHour(); // Call function to add one hour
                break;
            case 2:
                addMin(); // Call function to add one minute
                break;
            case 3:
                addSec(); // Call function to add one second
                break;
            case 4:
                cout << "Exiting Program\n"; // Exit the program
                break;
            default:
                cout << "Invalid selection. Please make a selection from the menu\n"; // Invalid input
        }
    }
}

// Main function
int main() {
    Clock clock; // Create Clock object
    clock.mainMenu(); // Display main menu
    return 0;
}

// Function to set the time
void Clock::setTime(int currentHour, int currentMinute, int currentSecond) {
    // Check if the input values are valid
    if (currentHour >= 0 && currentHour <= 23 && currentMinute >= 0 && currentMinute <= 59 && currentSecond >= 0 && currentSecond <= 59) {
        hours = currentHour; // Set hours
        min = currentMinute; // Set minutes
        sec = currentSecond; // Set seconds
    } else {
        cerr << "Invalid input. Please provide valid hour, minute, and second values.\n"; // Error message for invalid input
    }
}

// Function to add hours
void Clock::addHour(int hoursToAdd) {
    hours = (hours + hoursToAdd) % 24; // Increment hours 
}

// Function to add minutes
void Clock::addMin(int minutesToAdd) {
    min = (min + minutesToAdd) % 60; // Increment minutes 
    addHour((min + minutesToAdd) / 60); // Adjust hours 
}

// Function to add seconds
void Clock::addSec(int secondsToAdd) {
    sec = (sec + secondsToAdd) % 60; // Increment seconds 
    addMin((sec + secondsToAdd) / 60); // Adjust minutes 
}

// Function to get time in 12-hour format
string Clock::get12HourFormat() {
    int formattedHours = (hours % 12 == 0) ? 12 : hours % 12; // Convert hours to 12-hour format
    suffix = (hours >= 12) ? "P M" : "A M"; // Determine AM/PM suffix
    return twoDigitString(formattedHours) + ":" + twoDigitString(min) + ":" + twoDigitString(sec) + " " + suffix; // Return formatted time
}

// Function to get time in 24-hour format
string Clock::get24HourFormat() {
    return twoDigitString(hours) + ":" + twoDigitString(min) + ":" + twoDigitString(sec); // Return formatted time
}

// Function to convert a number to a two-digit string
string Clock::twoDigitString(int num) {
    // Check if the number is between 0 and 9
    if (num >= 0 && num <= 9) {
        // If it is, add a leading "0"
        return "0" + to_string(num);
    } else if (num >= 0 && num <= 59) {
        // Convert the number to a string using to_string
        return to_string(num);
    }
    return ""; // Return empty string for invalid input
}
