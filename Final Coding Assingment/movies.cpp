/* Name: Christopher Nielson   
Date: April 16, 2022
Assignment: Final Programming Assignment 
Due Date: April 21, 2022
About this project: A program that reads a file formatted with movies and allows the user to view total runtime, view movies by rating, export movies by genre, sort movies by year, and clear the database
Assumptions: Assume that user inputs y or n if the database is already loaded

All work below was performed by Christopher Nielson */

#include <iostream>
#include <iomanip>
#include <fstream>
//#include <cctype>
//#include <cstdlib>
//#include <cstring> 
#include <string> 

using namespace std;

//A Movies Structure that stores genre, name, release year, runtime, and rating
struct Movies
{
    string genre;
    string name;
    int year;
    int runtime; 
    string rating;  
};

//Function Declerations
Movies readMovie(ifstream &);
int viewRuntime(Movies *, int);
void displayMenu();
void loadMovieFile(ifstream &, Movies *&, int &); 
void movieByRating(Movies *, int, string);
void exportGenre(ofstream &, Movies *, int);
void clearMoviesDatabase(Movies *&);
void movieSort(Movies *, int);

int main() 
{
    //Variable Declerations
    char userSelection = '/0';
    Movies *movieList = NULL; 
    ifstream in; 
    ofstream out; 
    string userMovieRating;
    string fileName;  
    int size; 

    //Display input and declare user inputs
    displayMenu();
    char input;
    int runtimeOut;

    //A while loop that goes through the menu options
    while(userSelection != 'q' && userSelection != 'Q') {
        cout << "Please enter an item from the menu: ";
        cin >> userSelection;
        
        if(movieList == NULL && userSelection == '2') {
            cout << "\nTotal runtime: 0 hours and 0 minutes\n\n";
        } else if (movieList == NULL && userSelection == '6') {
            cout << "\nMovie database is already empty. Please load new database using option [1].\n\n";
        } else if(movieList == NULL && userSelection > '1' && userSelection <= '6') {
            cout << "\nLoad movie file first! Use option 1.\n\n";
        } else {
            switch(userSelection) {
                case '1':
                    if(movieList != NULL) {
                        cout << "\nThere is a database already loaded. This will overwrite the current database.\nContinue? (y/n) > ";
                        cin >> input; 
                        while (input != 'y' && input != 'n') {
                            cout << "\nPlease choose y or n: ";
                            cin >> input;
                        }
                        if (input == 'n') {
                            break;
                        }
                    }
                    cout << "\nPlease provide the file name in your directory to import (example.txt): ";
                    cin >> fileName;
                    in.open(fileName);

                    while(!in) {
                        cout << "\nPlease provide a VALID file name (example.txt): ";
                        cin >> fileName;
                        in.open(fileName);
                    }
                    cout << "\nLoading movie file...\n";
                    loadMovieFile(in, movieList, size);
                    cout << "File " << fileName << " is loaded!\n\n";
                    in.close();
                    break;
                case '2': 
                    runtimeOut = viewRuntime(movieList, size);
                    //Display runtime by hours and minutes
                    cout << "\nTotal runtime: " << runtimeOut / 60 << " hours and " << runtimeOut % 60 << " minutes\n\n";
                    break;
                case '3': 
                    cout << "\nPlease provide Movie Rating: ";
                    cin  >> userMovieRating;
                    //Converts user input to uppercase 
                    for(int i = 0; i < userMovieRating.size(); i++) {
                        userMovieRating[i] = toupper(userMovieRating[i]);
                    }
                    while(userMovieRating != "G" && userMovieRating != "PG" && userMovieRating != "PG-13" && userMovieRating != "R") {
                        cout << "Please enter correct rating (G, PG, PG-13, R): \n";
                        cin >> userMovieRating;
                        for(int i = 0; i < userMovieRating.size(); i++) {
                        userMovieRating[i] = toupper(userMovieRating[i]);
                        } 
                    }
                    movieByRating(movieList, size, userMovieRating);
                    cout << "\n";
                    break;
                case '4': 
                    cout << "Exporting Genres...\n"; 
                    exportGenre(out, movieList, size); 
                    break;
                case '5': 
                    cout << "\nSorting movies by earliest year released to lastest year realeased: \n";
                    movieSort(movieList, size);
                    for(int i = 0; i < size; i++) {
                        cout << movieList[i].year << " : " << movieList[i].name << endl; 
                    }
                    cout << "\n";
                    break;
                case '6': 
                    cout << "Clearing Database...\n\n";
                    clearMoviesDatabase(movieList);
                    break;
                case 'q': 
                    cout << "\nQutting...\n"; 
                    cout << "Database cleared\n";
                    cout << "Have a good day!";
                    clearMoviesDatabase(movieList);
                    break;
                case 'Q': 
                    cout << "\nQutting...\n"; 
                    cout << "Database cleared\n";
                    cout << "Have a good day!";
                    clearMoviesDatabase(movieList);
                    break;
                /*default:
                    cout << "Please select an entry from the menu\n";
                    displayMenu(); */
            }
        }  
    }
    return 0; 
}

//Function that displays the menu
void displayMenu() {
    cout << "\t\t---------Menu---------\n";
    cout << "[1] Load Movie File \n";
    cout << "[2] View Total Movie Database Runtime \n"; 
    cout << "[3] View Movies by Rating \n";
    cout << "[4] Export Movies by Genre \n";
    cout << "[5] Sort Movies by Year \n";
    cout << "[6] Clear Currently Loaded Movie Database \n";
    cout << "[Q] Exit \n";  
    cout << "\t\t----------------------\n\n";
}

//Function that loads user inputed file and creates an array
void loadMovieFile(ifstream &in, Movies *&movieList, int &size) {
    in >> size; 
    in.ignore(); 

    movieList = new Movies[size];

    for(int i = 0; i < size; i++) {
        movieList[i] = readMovie(in);
    }
}

//Subfunction that reads each part of the file 
Movies readMovie(ifstream &in) {
    Movies movie; 
    getline(in, movie.genre, ':'); 
    getline(in, movie.name, ',');
    in >> movie.year; 
    in >> movie.runtime;
    in.ignore();
    getline(in, movie.rating); 
    return movie;
}

//Function that adds up all the run times 
int viewRuntime(Movies *moviesList, int size) {
    int runTimeTotal = 0;
    for(int i = 0; i < size; i++) {
        runTimeTotal += moviesList[i].runtime;
    }
    return runTimeTotal;
}

//Function that catergorizes movie by its rating 
void movieByRating(Movies *movieList, int size, string rating) {

    for(int i = 0; i < size; i++) {
        if(movieList[i].rating == rating) { 
            cout << movieList[i].name << endl;
        }
    }
}

//Function that exports movies by its genre to seperate files
void exportGenre(ofstream &out, Movies *movieList, int size) {
    out.open("action.txt");
    for(int i = 0; i < size; i++) {
        if(movieList[i].genre == "ACTION") {
            out << movieList[i].name << " (" << movieList[i].year << ")\n"; 
        }
    }
    out.close();

    out.open("drama.txt");
    for(int i = 0; i < size; i++) {
        if(movieList[i].genre == "DRAMA"){
            out << movieList[i].name << " (" << movieList[i].year << ")\n"; 
        }
    }
    out.close();

    out.open("comedy.txt");
    for(int i = 0; i < size; i++) {
        if(movieList[i].genre == "COMEDY") {
            out << movieList[i].name << " (" << movieList[i].year << ")\n"; 
        }
    }
    out.close();

    out.open("scifi.txt");
    for(int i = 0; i < size; i++) {
        if(movieList[i].genre == "SCIENCE FICTION") {
            out << movieList[i].name << " (" << movieList[i].year << ")\n"; 
        }
    }
    out.close();
}

//Function that clears movie array
void clearMoviesDatabase(Movies *&movies) {
    delete[] movies; 
    movies = NULL;
}

//Function that sorts movie by year it was released 
void movieSort(Movies *arr, int arrSize) {
    for(int i = 0; i < (arrSize - 1); i++) {
        Movies tempVar;
        int currentMin = i;
        for(int j = i + 1; j < arrSize; j++) {
            if(arr[currentMin].year > arr[j].year) {
                currentMin = j;
            }
        }
        tempVar = arr[i];
        arr[i] = arr[currentMin];
        arr[currentMin] = tempVar; 
    }
}
