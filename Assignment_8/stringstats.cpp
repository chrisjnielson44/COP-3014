/* Name: Christopher Nielson 
Date: 04/05/2022
Assignment: 8
Due Date: 04/07/2022
About this project: A user will input a sentece and a word and will given an analyzation of the sentence (number of vowels, number of words, lengths of words etc) and will chceck to see if user's word is in the user's sentence 
Assumptions:
All work below was performed by Christopher Nielson */

#include <iostream>
#include <string>
#include <cstring>
//#include <cctype>

using namespace std;

//Function Declerations
void findWordLengths(string);
bool searchWord(string , string); 
int findVowels(string);
int findPunc(string);
int findNumSpaces(string);

int main()
{
    //Declare a char array for exit condition, string input for the user sentence and user word
    char userExit[50];
    string userSentece; 
    string userWord;


    //A do while loop that will call multiple functions that will analyze the user sentence and word as well as check the conditon of the users exit statement 
    do{
        //User sentece and word input 
        cout << "Enter a sentence: ";
        getline(cin,userSentece); 
        cout << "Enter a word: ";
        getline(cin,userWord); 

        //Output by the data returned from the functions
        cout << "\nSentence Analysis: \n\n";
        cout << "Puncuation Characters: " << findPunc(userSentece) << endl;
        cout << "Vowels: " << findVowels(userSentece) << endl;
        cout << "Words: " << findNumSpaces(userSentece) << endl; 
        cout << "\n\nWord Lengths: \n";
        findWordLengths(userSentece);
       

        if(searchWord(userSentece, userWord) == true) {  //Conditional returns true if the user word appears in user sentence
            cout << "The word: \"" << userWord << "\" IS a part of the sentence you entered.";
        } else {
            cout << "The word: \"" << userWord << "\" IS NOT a part of the sentece you entered.";
        }

        //Ask the user if they want to input another sentence and word
        cout << "\n\nEnter another sentence/word for analysis (yes/no): ";
        cin >> userExit;

        for(int i = 0; i < strlen(userExit); i++) {  //Converts all char characters into lowercase
            userExit[i] = tolower(userExit[i]);
        }

        if(userExit[0] == 'n' && userExit[1] == 'o' && userExit[2] == '\0') {
            return 0;
        }

        while(!((userExit[0] == 'y' && userExit[1] == 'e' && userExit[2] == 's' && userExit[3] == '\0') || (userExit[0] == 'n' && userExit[1] == 'o' && userExit[2] == '\0'))) {
            
            cout << "\nEnter yes or no: ";
            cin >> userExit;
            for(int i = 0; i < strlen(userExit); i++) {
                userExit[i] = tolower(userExit[i]);
            }
    
        } 


    } while(userExit[0] == 'y' && userExit[1] == 'e' && userExit[2] == 's');


    return 0;
}

int findVowels(string vowels) {
    int numOfVowels = 0;
    for(int i = 0; i < vowels.length(); i++) {
        if(vowels[i] == 'a' || vowels[i] == 'e' || vowels[i] == 'i' || vowels[i] == 'o' || vowels[i] == 'u' || vowels[i] == 'A' || vowels[i] == 'E' || vowels[i] == 'I' || vowels[i] == 'O' || vowels[i] == 'U') {
            numOfVowels++;
        }

    }
    return numOfVowels;
}

//A int function that finds puncuation using c++'s punc function. 
int findPunc(string punc) {
    int numOfPunc = 0;
    for(int i = 0; i < punc.length(); i++) {
        if(ispunct(punc[i])) {
            numOfPunc++;
        }
    }
    return numOfPunc;
}

//A int function that finds the number of spaces between words which will indicate the number of words in user sentence. It will ignore multiple spaces 
int findNumSpaces(string spaces) {
    int numSpaces = 0;
    for(int i = 0; i < spaces.length(); i++) {
        if(spaces[i] == ' ') {  //This will ignore multiple space entries 
            numSpaces++;
            while(spaces[i + 1] == ' ') {
                i++;
            }
        }

    }
    return numSpaces + 1;
}

//A void function that finds the lengths of each word in usersentece 
void findWordLengths(string lengths) { 
    int size = findNumSpaces(lengths);
    int lengthsArr[size];
    int stringIndex = 0;
    int wordSize = 0;
    

    for(int i = 0; i < size; i++) {
        while(lengths[stringIndex] != ' ' && stringIndex < lengths.length()) {
            stringIndex++;
            wordSize++;
            
        }
        while(lengths[stringIndex + 1] == ' ') {
                stringIndex++;
            }
            stringIndex++;

        lengthsArr[i] = wordSize;
        wordSize = 0;
    }
    for(int i = 0; i < size; i++){
    cout << lengthsArr[i] << " ";
    }

   int wordsFound = 0;
   int currSize = 0;
   int count = 0;

   while(wordsFound < size) {
       for(int i = 0; i < size; i++) {
           if(lengthsArr[i] == currSize) {
               count++;
           }
       }
       if(count > 0) {
           cout << currSize << " characters long: " << count << ((count == 1)?" word \n": " words\n");  //Short hand if statement pretty cool
           wordsFound+=count;
       }
       currSize++;
       count = 0;
   }
}

//A bool function that will return true if user word matches user sentece or return false if it does not
bool searchWord(string wordSearchIn , string wordSearchFor) {
    int subLength = wordSearchFor.size();
    for(int i = 0; i < wordSearchIn.size(); i++) {
        bool isEqual = true;
        for(int j = 0; j < subLength; j++) {
            if(wordSearchFor[j] != wordSearchIn[i+j]) {
                isEqual = false;
            }
        }
        if(isEqual == true) {
            return true;
        }
    }
    return false;

  



}

