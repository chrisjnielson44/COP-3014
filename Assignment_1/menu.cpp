/* Name: Christopher Nielson
Date: 01/12/2022
Section: 1
Assignment: 1 
Due Date: 01/19/2022
About this project: This project calculates the total price before tax, the Wizard tax, and the total price after Wizard tax after the user inputs their desired quantity per food item.
Assumptions: Assumes correct user input 

All work below was preformed by Christopher Nielson */

#include <iostream>
#include <iomanip>
using namespace std; 

int main()
{
    //Declare variables (Hogwarts food items)
    //Food Quantities 
    int bottBeans;
    int chocFrogs;
    int explodeBons;
    int cauldCakes; 
    //Food Prices
    const double bottBeansPrice = 4.00;
    const double chocFrogsPrice = 1.50;
    const double explodeBonsPrice = 2.50;
    const double cauldCakesPrice = 6.25;
    //Total Price * Quantity 
    double bottBeansTotal;
    double chocFrogsTotal; 
    double explodeBonsTotal; 
    double cauldCakesTotal; 
    //Final Total, Tax, Total after Tax Vars
    double totalbforTax; 
    const double taxPercent = 0.065; 
    double taxAmt;
    double totalaftrTax; 

    //Input and output
    //Menu Items 
    cout << "Anything off the trolley, dears?\n\n";
    cout << "\t\tTROLLEY MENU\n";
    cout << "\t\t----------------------\n";
    cout << fixed << showpoint << setprecision(2);   //This causes doubles to round/display two decimal places for the rest of the program 
    cout << "\t\tBertie Bott's Every Flavour Beans: $" << bottBeansPrice << endl;
    cout << "\t\tChocolate Frogs: $" << chocFrogsPrice << endl;
    cout << "\t\tExploding Bonbons: $" << explodeBonsPrice << endl; // 
    cout << "\t\tCauldron Cakes: $" << cauldCakesPrice << endl;
    cout << "\t\t----------------------\n\n";
    
    //User quantitiy input 
    cout << "How many Bertie's Bott's Every Flavour Beans? --> ";
    cin >> bottBeans;
    cout << "How many Chocolate Frogs? --> ";
    cin >> chocFrogs; 
    cout << "How many Exploding Bonbons? --> ";
    cin >> explodeBons; 
    cout << "How many Cauldron Cakes? --> ";
    cin >> cauldCakes; 

    //Multiply price by quantity 
    bottBeansTotal = bottBeans * bottBeansPrice;
    chocFrogsTotal = chocFrogs * chocFrogsPrice;
    explodeBonsTotal = explodeBons * explodeBonsPrice;
    cauldCakesTotal = cauldCakes * cauldCakesPrice;

    //Calculate Total before tax, tax amount, and total after tax
    totalbforTax = bottBeansTotal + chocFrogsTotal + explodeBonsTotal + cauldCakesTotal;
    taxAmt = totalbforTax * taxPercent; 
    totalaftrTax = totalbforTax + taxAmt; 

    //Output Total before tax, tax amount, and total after tax two decimal places
    //cout << fixed << showpoint << setprecision(2);
    cout << "\nTotal (Before Wizard Tax): $" << totalbforTax << endl;
    cout << "Tax (" << taxPercent * 100 << "%): $" << taxAmt << endl;
    cout << "Total (After Wizard Tax): $" << totalaftrTax << endl;
    cout << "\nEnjoy your candies!";

    return 0;
}
