/* Name: Christopher Nielson   
Date: 03/06/22
Assignment: 6
Due Date: 03/09/22
About this project: This project 
Assumptions: Assume user inputs integers for menu, Assume user inputs characters for Highlow game

All work below was performed by Christopher Nielson */

#include <iostream> 
#include <iomanip>
//#include <cmath>
#include <ctime>
#include <cstdlib> 

using namespace std;

//Function Declerations 
void menu();
bool guessNumber(); 
bool highLow(); 
bool collectPairs();
void viewStats(int,int);
void printRules();


int main()
{
    //Seed random number generator 
    srand((unsigned int)time(0));

    //int counter = 0;
    int userResponse; 
    int numWins = 0; 
    int totalGames = 0;

    //Call Menu and ask for User Input
    menu();
    cin >> userResponse;

    //While loop that selects games
    while (userResponse < 0 || userResponse > 6) {
        cout << "Enter an item on the menu: ";
        cin >> userResponse;
    }

    while (userResponse != 0) {
        if (userResponse == 1) {
            numWins += guessNumber();
            totalGames++;
            menu();
            cin >> userResponse;
        } else
        if (userResponse == 2) {   
            numWins += highLow();
            totalGames++;
            menu();
            cin >> userResponse;
        } else
        if (userResponse == 3) {
            numWins += collectPairs();
            totalGames++;
            menu();
            cin >> userResponse; 
        } else
        if (userResponse == 4) {
            viewStats(numWins, totalGames);
            menu();
            cin >> userResponse; 
        } else
        if (userResponse == 5) {
            numWins = 0;
            totalGames = 0;
            cout << "Statistics Reset!\n\n";
            menu();
            cin >> userResponse;
        } else
        if (userResponse == 6) {
            printRules();
            menu();
            cin >> userResponse;
        }
    }
    cout << "\n";
    viewStats(numWins, totalGames);
    cout << "Thanks for Playing";

    return 0;
}

//Collect Pair Funciton - I wish I knew we could use arrays for this cause it would have saved a lot of time lol.
bool collectPairs()
{
    int dice1, dice2;
    int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    
    for(int i = 0; i < 100; i++) {
        dice1 = (rand() % 7 + 1);
        dice2 = (rand() % 7 + 1);
    
        if (dice1 == 1 && dice2 == 1) {
            ones++;
        }
        if (dice1 == 2 && dice2 == 2) {
            twos++;
        }
        if (dice1 == 3 && dice2 == 3) {
            threes++;
        }
        if (dice1 == 4 && dice2 == 4) {
            fours++;
        }
        if (dice1 == 5 && dice2 == 5) {
            fives++;
        }
        if (dice1 == 6 && dice2 == 6) {
            sixes++;
        }
    }

    cout << "\nRolling a pair of  dice 100 times for pairs!\n";
    if (ones > 0) {
        cout << "PAIR OF ONES found\n";
    }
    if (twos > 0) {
        cout << "PAIR OF TWOS found\n";
            }
    if (threes > 0) {
        cout << "PAIR OF THREES found\n";
    }
    if (fours > 0) {
        cout << "PARIR OF FOURS found\n";
    }
    if (fives > 0) {
        cout << "PAIR OF FIVES found\n";
    }
    if (sixes > 0) {
        cout << "PAIR OF SIXES found\n";
    }

    if (ones > 0 && twos > 0 && threes > 0 && fours > 0 && fives > 0 && sixes > 0) {
        cout << "You win!\n\n";
        return true;
    } else {
        cout << "\nSorry, you lose.\n\n";
        return false;
    }

}

//Guess Number Function 
bool guessNumber()
{
    int randomNum = (rand() % 100 + 1);
    int userGuess;
    cout << "\n\nGuess the number, 1 --> 100\n";
    for(int guessAttempts = 1; guessAttempts <= 6; guessAttempts++) {
        cout << "Attempt " << guessAttempts << "/6 : ";
        cin >> userGuess;
        if (userGuess < randomNum)
        {
            cout << "TOO SMALL\n";
        } else 
        if (userGuess > randomNum) {
            cout << "TOO BIG\n";
        } else 
        if (userGuess == randomNum) {
            cout << "YOU WIN!\n";
            return true;
        }
    }
    cout << "Sorry, you lose. The number was " << randomNum << "\n\n";
    return false;
}

//HighLow function
bool highLow() 
{
    int randomNumA = (rand() % 1000 + 1);
    char highLowInput;
    cout << "\n\nHigh or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)\n";
    for (int rounds = 1; rounds <= 5; rounds++) {
        cout << "Round " << rounds << " of 5. The number is " << randomNumA;

        int randomNumB = (rand() % 1000 + 1);

        cout << "\n\t...is the next number [H]igher or [L]ower?: ";
        cin >> highLowInput;

        while (highLowInput != 'H' && highLowInput != 'L'){
            cout << "Enter H or L: ";
            cin >> highLowInput;
        }
        if (highLowInput == 'H') {
            if(randomNumB > randomNumA) {
                cout << "The next number is " << randomNumB << "\nCorrect!\n";
            } else {
                cout << "The next number is " << randomNumB << "\nSorry, you lose.\n";
                return false;
            }
        } else
        if (highLowInput == 'L') {
            if (randomNumB < randomNumA) {
                cout << "The next number is " << randomNumB << "\nCorrect!\n";
            } else {
                cout << "The next number is " << randomNumB << "\nSorry, you lose.\n";
                return false; 
            }
        }
        randomNumA = randomNumB;
    }
    cout << "YOU WIN!";
    return true;
}

//View Stats Function 
void viewStats(int gamesWon,int totalGamesPlayed) 
{
    int gamesLoss = (totalGamesPlayed - gamesWon);
    
    double winPercentage = (static_cast<double>(gamesWon) / static_cast<double>(totalGamesPlayed)) * 100;

    if(gamesWon == 0 && gamesLoss == 0) {
        winPercentage = 0;
    }
    
    cout << fixed << showpoint << setprecision(1);
    cout << "Wins: " << gamesWon << "\t\tLosses: " << gamesLoss; 
    cout << "\nTotal Win Percent:\t" << winPercentage << "%\n\n";
}

//Menu Fuction
void menu() 
{
    cout << "GAME MENU:\n";
    cout << "--------------------------\n";
    cout << "1: PLAY Guess the Number\n";
    cout << "2: PLAY High Low\n";
    cout << "3: PLAY Collect Pairs\n";
    cout << "4: VIEW Statistics\n";
    cout << "5: RESET Statistics\n";
    cout << "6: RULES\n";
    cout << "0: QUIT\n";
    cout << "--------------------------\n";
}

//Print Rules Function 
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!";
    cout << "\nGuess Wisely!\n\nHigh/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
}