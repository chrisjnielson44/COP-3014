#include <iostream>
using namespace std; 

int main()
{

    char name[40] = "Melina";
    cout << name;


    char yourname[100];

    cout << "\nEnter your name: ";
    cin >> yourname;
    cout << "Your name is: " << yourname << endl;


    cin.getline(yourname,100); //if you omit the third parameter (delimeter), it defaults to '\n'

    return 0;
}