/* Name: Christopher Nielson 
Date: 01/31/22
Assignment: 3
Due Date: 02/02/21
About this project: User gives an amount in change and has to match that amount by inputing the correct amount of coins
Assumptions: 

All work below was performed by Christopher Nielson */

#include <iostream> 
#include <iomanip>
using namespace std; 

int main()
{
    //Declare varibles for user's decision and user amount
    char userDecision; 
    
    //Output 
    cout << "Welcome to the coin game!\n";
    cout << "Would you like to play (y or n) --> ";
    cin >> userDecision; 

    //A series of if and else statements that advances the game depending on the user's decision 
    if (userDecision == 'y') {  //if statement for when user inputs 'y'
        //Declare vars for amount of coins and set the value of each coin
        double userAmount; 
        int amtHalfDollars, amtQuarters, amtDimes, amtNickels, amtPennies; 
        double halfDollar = 0.50, quarter = 0.25, dimes = 0.10, nickles = 0.05, pennies = 0.01, totalChange;
       

        //Output and input statements that assign to coin amounts 
        cout << "What amount of $ would you like to match? --> ";
        cin >> userAmount; 
        cout << fixed << showpoint << setprecision(2) << "\nOkay you need to match the value of $" << userAmount; 
        cout << "\nEnter the number of: ";
        cout << "\n\tHalf Dollars: ";
        cin >> amtHalfDollars;
        cout << "\tQuarters: ";
        cin >> amtQuarters;
        cout << "\tDimes: ";
        cin >> amtDimes;   
        cout << "\tNickels: ";
        cin >> amtNickels;
        cout << "\tPennies: ";
        cin >> amtPennies;

        //Calculate total change based off user input 
        //Split to keep within 80 characters 
        totalChange = (amtHalfDollars * halfDollar) + (amtQuarters * quarter) +   
        (amtDimes * dimes) + (amtNickels * nickles) + (amtPennies * pennies);

        double userTotal = totalChange - userAmount;  

        //If user inputs negative coins abort game else determine if user won or lossed 
        if (amtHalfDollars < 0 || amtQuarters < 0 || amtDimes < 0 || amtNickels < 0 || amtPennies < 0) {
            cout << "You can't enter a negative amount of coins. Aborting game.";
            } else if (userTotal == 0) {
                cout << "You WIN!" << "\nThanks for playing!"; 
            } else if (userTotal < 0) {
                //Is user goes over desired amount change negative number into positive 
                cout << "You LOST by: $" << (userTotal * -1) << "\nThanks for playing!"; 
            } else {
                cout << "You LOST by: $" << (userTotal) << "\nThanks for playing!";
            }
    } else if(userDecision == 'n') {  //if statement for when user inputs 'n'
        cout << "Guess you're scared! Come back when you're ready to play!";
    } else {                          //else statement if user inputs an invalid character
        cout << "Invalid entry, aborting program.";
    }

    return 0;
}








