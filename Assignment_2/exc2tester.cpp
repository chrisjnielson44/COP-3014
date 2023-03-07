#include <iostream> 
using namespace std; 
int main()
{
    int userMonth, userYear, numOfDays; 

    cout << "Enter a month (1-12): ";
    cin >> userMonth; 
    cout << "Enter a year: ";
    cin >> userYear; 
    
    if (userMonth < 1 || userMonth > 12)
    {
        cout << "Invalid Month entered. Aborting Program...";
        return 0;
    }

    //Months with 30 days - September, November, June, April 
    //Months with 31 days - May, July, August, October, Januaury, March, December 
    //Febuaury 28 days (29 Leap year)
    // 30 Days - 9,11,6,4
    // 31 Days - 5,7,8,10,1,3,12
    // 28*29 - 2

    //Feb
    if (userMonth == 2)
    {
       if((userYear%4 == 0 && userYear%100 != 0) || userYear%400 == 0)
       {
           numOfDays = 29;
       } else 
            numOfDays = 28;
    }

    //Months with 30 days
    if (userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11)
    {
        numOfDays = 30;
    }
    //Months with 31 days
    if (userMonth == 1 || userMonth == 3 || userMonth == 5 || userMonth == 7 || userMonth  == 8 || userMonth == 10 || userMonth == 12)
    {
        numOfDays = 31;
    }

    cout << "\nNumber of days: " << numOfDays;

    return 0;
}