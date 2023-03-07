/* Name: Christopher Nielson 
Date: 02/22/22
Assignment: 5
Due Date: 02/22/22
About this project: Program that calculates NFL Passer rate using two functions
Assumptions: Assume correct user input for passer rate data 

All work below was performed by Christopher Nielson */

#include <iostream>
#include <iomanip>
using namespace std;
double getPasserRating (double att, double comp, double yds, double td, double intercep);

int main()
{
    char option = 'Y';
    int compare = 0;

    while (option == 'Y' || option == 'y') {
        double attempts, completions, passingYards, touchdowns, interceptions;
        double playerA, playerB;

        //Player A
        cout << "Welcome to the NFL Quarterback Passer Rating Calcualtor!\n\n";
        cout << "Enter single game information for Player A: ";
        cout << "\nAttempts: ";
        cin >> attempts;
        cout << "Completions: ";
        cin >> completions;
        cout << "Passing Yards: ";
        cin >> passingYards;
        cout << "Touchdowns: ";
        cin >> touchdowns;
        cout << "Interceptions: ";
        cin >> interceptions;
        playerA = getPasserRating(attempts, completions, passingYards, touchdowns, interceptions);
    
        //Player B
        cout << "\n\nEnter single game information for Player B: ";
        cout << "\nAttempts: ";
        cin >> attempts;
        cout << "Completions: ";
        cin >> completions;
        cout << "Passing Yards: ";
        cin >> passingYards;
        cout << "Touchdowns: ";
        cin >> touchdowns;
        cout << "Interceptions: ";
        cin >> interceptions;
        playerB = getPasserRating(attempts, completions, passingYards, touchdowns, interceptions);
        
        //Output
        cout << fixed << showpoint << setprecision(1);
        cout << "\nPlayer A's single game passer rating: " << playerA;
        cout << "\nPlayer B's single game passer rating: " << playerB;
    
        if(playerA > playerB) {
            cout << "\nPlayer A was better than Player B by a difference of " << (playerA - playerB);
        } else if(playerB > playerA){
            cout << "\nPlayer B was better than Player A by a difference of " << (playerB - playerA);
        } else if (playerA == playerB) {
            cout << "\nPlayer A and B have the same rating!";
        }

        if(playerA >= 158.333) {
            cout << "\n\nPlayer A had a PERFECT passer rating!";
        }
        
        if(playerB >= 158.333) {
            cout << "\n\nPlayer B had a PERFECT passer rating!";
        }
        //Compare counter 
        compare++;
        //Loop breaker 
        cout << "\n\nWould you like to compare another pair of players? (Y or N): ";
        cin >> option;
    }

    if (option == 'N' || option == 'n') {
        cout << "You compared " << compare << " pairs of players.";
    } else {
        cout << "Invalid entry. Exiting program...";
    }

    return 0;
}

//Function for Passrate 
double getPasserRating (double att, double comp, double yds, double td, double intercep)
{
    double a, b, c, d, passerRating;
   
    a = ((comp / att) - 0.3) * 5;
    b = ((yds / att) - 3) * 0.25;
    c = (td / att) * 20;
    d = 2.375 - ((intercep / att) * 25); 

    if(a > 2.375) {a = 2.375;} else if(a <= 0) {a = 0;}
    if(b > 2.375) {b = 2.375;} else if(b < 0) {b = 0;}
    if(c > 2.375) {c = 2.375;} else if(c < 0) {c = 0;}
    if(d > 2.375) {d = 2.375;} else if(d < 0) {d = 0;}

    passerRating = ((a + b + c + d) / 6) * 100;
    
    return passerRating;
}