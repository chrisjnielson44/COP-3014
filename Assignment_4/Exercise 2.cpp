//Exercise 2

#include <iostream>
#include <iomanip>
//#include <cmath>

using namespace std;

int main()
{
    int daysWorked;
    double salary = 0.01;

    cout << "Please enter the number of days worked: "; 
    
    cin >> daysWorked;

    while (daysWorked < 0 || daysWorked == 0) {
        cout << "Inavlid number of days. Try again ";
        cout << "\nPlease enter the number of days worked: "; 
        cin >> daysWorked;
    }

    cout << "\nDay\t\t\tAmount Earned";
    cout << "\n-------------------------------------------";
    cout << fixed << showpoint << setprecision(2);

    for (int num2 = 1; num2 <= daysWorked; num2++) {
        if (num2 > 1) {
        salary *= 2;
        }
        cout << "\n" << num2 << "\t\t\t$ " << salary;
    }

    cout << "\n\nTotal earnings: $ " << salary;
    

    return 0;
}
