//Program to calculate your final class grade in COP3014, Spring 2022.
#include <iostream>
using namespace std;

int main()
{
    double A,B,C,D, finalgrade;
    double midtermMade,assignMade,revelMade,finalassignMade;
    double extracredit = 0;
    char yn;
    
    const int MIDTERMPOSSIBLE = 100;
    const int REVELPOSSIBLE = 499;  
    const int PROGASSIGNPOSSIBLE = 700; 
    const int FINALPROGASSIGNPOSSIBLE = 100;
    
    cout << "Midterm Score: ";
    cin >> midtermMade;
    cout << "Total Points made on Programming Assignments 1-8: ";
    cin >> assignMade;
    cout << "Total Points made on Pearson Revel Assignments: ";
    cin >> revelMade;
    cout << "Grade on Final Programming Assignment: " ;
    cin >> finalassignMade;
    
    cout << "Did you earn extra credit in the programming contest? (y/n): ";
    cin >> yn;
    if(yn == 'y' || yn == 'Y')
    {
        cout << "Extra credit points (programming contest): ";
        cin >> extracredit;
    }
    
    A = (((assignMade+extracredit)/PROGASSIGNPOSSIBLE) * .5);     
    B = ((midtermMade/MIDTERMPOSSIBLE) * .2); 
    C = ((revelMade/REVELPOSSIBLE) * .2); 
    D = ((finalassignMade/FINALPROGASSIGNPOSSIBLE) * .1); 
 
    finalgrade = (A+B+C+D) * 100.0;
    
    cout << "Final Course Grade: " << finalgrade << endl;
    return 0;
}