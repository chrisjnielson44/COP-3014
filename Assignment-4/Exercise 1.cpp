//Exercise 1

#include <iostream>
using namespace std;

int main()
{
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

    return 0;
}