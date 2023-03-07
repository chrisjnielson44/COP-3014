/*Name: Christopher Nielson
Date: 01/22/2022
Section: 1
Assignment: 2
Due Date: 01/25/2022
About this project: Exercise 1 divides two user-inputed fractions, Exercise 2 calculates how many days there are in a user-inputed month as well as calcualte leap years 
Assumptions: Assume user inputs correct year for exercise 2

All work below was performed by Christopher Nielson */

#include <iostream>
using namespace std;

int main() {
  //Exercise 1 (Dividing Fractions)
  //Initialize Integer Varibles for Fractions 
  int firstNumer, firstDenom, secondNumer, secondDenom;

  //User Input
  cout << "Enter the numerator of the first fraction: ";
  cin >> firstNumer;

  cout << "Enter the denominator of the first fraction: ";
  cin >> firstDenom;

  cout << "Enter the numerator of the second fraction: ";
  cin >> secondNumer;

  cout << "Enter the denominator of the second fraction: ";
  cin >> secondDenom;

  //Error Statement when user inputs 0 into one/both of the denominator(s)
  if (firstDenom == 0 || secondDenom == 0) {
    cout << "You cannot divide by 0! Aborting program...";
    return 0;
  }

  //Declare Numerator Total & Denominator Total & Multiply Fractions 
  int numerTotal = firstNumer * secondDenom;
  int denomTotal = firstDenom * secondNumer;

  //Output Multiplied Fraction 
  cout << firstNumer << "/" << firstDenom << " divided by " << secondNumer << "/" << secondDenom << " = " << numerTotal << "/" << denomTotal;


  //Exercise 2 (Number of Days in a Month Calcualtor)
  //Initialize Integer Varibles for Month, Year, and number of days 
  int userMonth, userYear, numOfDays;

  //User Input 
  cout << "\n\nEnter a month (1-12): ";
  cin >> userMonth;
  cout << "Enter a year: ";
  cin >> userYear;

  //Check condition - if User inputs invalid month number display error message 
  if (userMonth < 1 || userMonth > 12) {
    cout << "Invalid Month entered. Aborting Program...";
    return 0;
  }
  //Febuary - Checks Leap Year Condition (Nested Loop)
  if (userMonth == 2) {
    if ((userYear % 4 == 0 && userYear % 100 != 0) || userYear % 400 == 0) {
      numOfDays = 29;
    } else {
      numOfDays = 28;
    }
  }
  //Months with 30 Days - 4,6,9,11  
  if (userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11) {
    numOfDays = 30;
  }
  //Months with 31 Days - 1,3,5,7,8,10,12
  if (userMonth == 1 || userMonth == 3 || userMonth == 5 || userMonth == 7 || userMonth == 8 || userMonth == 10 || userMonth == 12) {
    numOfDays = 31;
  }

  //Ouput Number of Days
  cout << "\nNumber of days: " << numOfDays;

  return 0;
}