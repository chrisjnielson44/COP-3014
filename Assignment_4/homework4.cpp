/* Name: Christopher Nielson    
Date: 02/08/2022
Assignment: 4
Due Date: 02/10/22
About this project: This program utilizes for-loops for two different exercises. 
Exercise 1 requires the user to input two numbers and add the numbers between (inclusive). 
Exercise 2 requires the user to input a number of days worked where your salary doubles each day. 
Assumptions: 

All work below was performed by Christopher Nielson */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Exercise 1 
    int userFirstNum, userSecNum;

    cout << "Input two integers: ";
    cin >> userFirstNum; cin >> userSecNum;

    //If statment because no global vars are accepted
    if ((userFirstNum <= 0 || userFirstNum >= 0) && (userSecNum <= 0 || userSecNum >= 0)) { 
        int userFirstNum, userSecNum, total =  0;

    cout << "Input two integers: ";
    cin >> userFirstNum; cin >> userSecNum;

    //If statement if first number is is greater than second number
    if (userFirstNum > userSecNum) {
        int temp = userFirstNum;
        userFirstNum = userSecNum;
        userSecNum = temp;
    } 
    
    cout << "Sum of values from " << userFirstNum << " through " << userSecNum << " is: \n";

    for (int num = userFirstNum; num <= userSecNum; num++) {
        total += num;
        cout << num;
        if (num != userSecNum){
            cout << " + ";
        }
    }

    cout << "\n= " << total; 
    
    }

    //Exercise 2
    int daysWorked;

    cout << "\n\nPlease enter the number of days worked: "; 
    cin >> daysWorked;

    while (daysWorked < 0 || daysWorked == 0) {
        cout << "Inavlid number of days. Try again ";
        cout << "\nPlease enter the number of days worked: "; 
        cin >> daysWorked;
    }

    cout << "\nDay\t\t\tAmount Earned";
    cout << "\n-------------------------------------------";
    cout << fixed << showpoint << setprecision(2);

    if (daysWorked > 0) {           //If statement because no global vars are accepted 
        double salary = 0.01;
        for (int num2 = 1; num2 <= daysWorked; num2++) {
            if (num2 > 1) {
            salary *= 2;
         }
        cout << "\n" << num2 << "\t\t\t$ " << salary;
        }
        cout << "\n\nTotal earnings: $ " << salary;
    }

    return 0;
}
