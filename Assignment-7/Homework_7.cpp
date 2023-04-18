/* Name: Christopher Nielson
Date: 03/25/22
Assignment: 7
Due Date: 03/29/22
About this project: 
Assumptions: Assume correct user input when selecting array size

All work below was performed by Christopher Nielson */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Given Global Vars
const int MAX = 40;
const int MIN = 5; 

//Function Delerations
void PrintArray(const int arr[], const int size); //Given
int checkValidArrSize(); 
void printMenu(); 
void fillSequence(int[], int);
void Insert(int[], int&, int, int);
void Shift(int [], int, int); 
void Reverse(int[], int); 
void Delete(int[], int&, int);
void fillRandom(int [], int, int, int);
void growArrSize(int[], int&);
void shrinkArrSize(int[], int&); 
void arrLeastGreatest(int[], int);
int returnArrMaxValue(int[], int);
double averageArrElements(int[], int);


//Main Function 
int main()
{
    //Creation of array named list, wtih allocated size as MAX
    int list[MAX]; 
    
    int arrSize = checkValidArrSize(); //Function to ask the user the size of the Array
    fillSequence(list, arrSize); // Fills array with incrementing numbers 
    
    char userSelection = 'v'; //This is to set the condtion for the while loop
    printMenu(); 
    
    cout << fixed << setprecision(1);
    
    while (userSelection != 'q'){  //A while loop for user selection when in menu 
        cout << "Selection > "; 
        cin >> userSelection;
        //This changes the user input to a lowercase character that way the user can input lowercase and uppercase. Common practice used by programmers
        userSelection = tolower(userSelection);  
        int lengthOfShift, arrVal, arrIndex; 
    
        switch(userSelection) {  //Switch case that assigns functions to designated letter 
            case 'f':
                cout << "Randomizing Array Data...\n\n"; 
                fillRandom(list, arrSize, 1, 101);
                break;
            case 'r':
                cout << "Reversing array order...\n\n";
                Reverse(list,arrSize);
                break; 
            case 'x':
                cout << "Shift right by: ";
                cin >> lengthOfShift;
                if(lengthOfShift < 0) {
                    cout << "Error...negative numbers are not allowed!\n";
                    break;
                }
                
                Shift(list, arrSize, lengthOfShift);
                break; 
            case 'i':
                cout << "Value to insert? > ";
                cin >> arrVal; 
                cout << "At which Index? > "; 
                cin >> arrIndex; 
                if  (arrIndex < 0 || arrIndex > (arrSize - 1)) {
                    cout << "Cannot insert value at list[" << arrIndex << "], out of bounds\n";
                    break;
                } 
                cout << "Inserting " << arrVal << " at list[" << arrIndex << "]\n";
                Insert(list,arrSize,arrVal,arrIndex);
                break;
            case 'd':
                cout << "Delete the element at which index? > ";
                cin >> arrIndex; 
                if(arrIndex < 0 || arrIndex > (arrSize - 1)) {
                    cout << "Cannot delete value at list[" << arrIndex << "], out of bounds\n";
                    break;
                }
                cout << "Deleting element at index " << arrIndex << endl; 
                Delete(list, arrSize, arrIndex); 
                break; 
            case 'a':
                cout << "Average: " << averageArrElements(list, arrSize) << "\n\n"; 
                break;
            case 'm': 
                cout << "Max Value: " << returnArrMaxValue(list, arrSize) << endl;
                break;
            case 'g': 
                growArrSize(list, arrSize); 
                break;
            case 's':  
                shrinkArrSize(list, arrSize); 
                break;
            case 'p':
                PrintArray(list, arrSize); 
                break; 
            case 'z': 
                cout << "Sorting array from LEAST to GREASTEST...\n"; 
                arrLeastGreatest(list, arrSize);
                break; 
            case 'q':
                PrintArray(list,arrSize);
                cout << "\n\nQutting program..."; 
                break; 
            default: 
                cout << "Invalid. Enter an option in the menu\n";
        }
    }
    

    return 0;
}

//Definitions of Functions with description 
//Given printArray function
void PrintArray(const int arr[], const int arrSize) {
    cout << "\nThe array:\n{ ";
	for (int i = 0; i < arrSize-1; i++) {	// for loop, prints all items except last with commas
		cout << arr[i] << ", ";
    }

	cout << arr[arrSize-1] << " }\n\n";	// prints last item , no comma
}

//Asks user for array size and checks to see if user inputed a number greater than 5 and less than 40
int checkValidArrSize() {
    int arrSize; 
    cout << "To begin, enter the starting current size for your array.\n";
    cout << "Enter a value " << MIN << " --> " << MAX << ": ";
    cin >> arrSize;

    while(arrSize % 5 != 0 || arrSize > MAX || arrSize < MIN) { 
        cout << "Invalid, Enter a value " << MIN << " --> " << MAX << ": "; 
        cin >> arrSize;
    }
    return arrSize;
}

//Prints menu 
void printMenu() {
    cout << "-------------------MENU-------------------\n";
    cout << "F - Fill Array: RANDOM values 1 - 100\n";
    cout << "R - Reverse Array Contents\n";
    cout << "X - Shift Right\n";
    cout << "C - Sort\n";
    cout << "I - Insert Array Element\n";
    cout << "D - Delete Array Element\n";
    cout << "A - Print Average\n";
    cout << "M - Print Max Value\n";
    cout << "G - Grow Array Size by 5\n";
    cout << "S - Shrink Array Size by 5\n";
    cout << "P - Print Array\n";
    cout << "Z - Sort contents of array from least to greatest\n"; 
    cout << "Q - QUIT\n";
    cout << "------------------------------------------\n";
}

//Fills user array with random numbers 0 - 100
void fillRandom(int arr[], int arrSize, int arrStart, int arrEnd) {
    srand(time(NULL)); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % (arrEnd - arrStart) + arrStart; 
    }
}

//Reverses the numbers in user array
void Reverse(int arr[], int arrSize) {
    int tempVar; 
    for (int i = 0; i < arrSize / 2; i++) {
        tempVar = arr[i];
        arr[i] = arr[arrSize - (i + 1)]; 
        arr[arrSize - (i + 1)] = tempVar;
    }
    cout << "This works";
}

//Shifts the index of array by user input 
void Shift(int arr[], int arrSize, int arrShift) {
    int shiftIterations = 1;
    if(arrSize % arrShift == 0) {
        shiftIterations = arrShift;
    }
    for (int i = 0; i < shiftIterations; i++){
        int arrIndex = i; 
        int tempVar = arr[i];
        do{
            arr[arrIndex] = arr[(arrIndex + arrSize - arrShift) % arrSize];
            arrIndex = (arrIndex + arrSize - arrShift) % arrSize;
        }
        while(arrIndex != i);

        arr[(arrShift + i) % arrSize] = tempVar;
        
    }
}

//Insterts a chosen value into a chosen index in user array
void Insert(int arr[], int& arrSize, int arrValue, int arrIndex) {
    for(int i = arrSize; i > arrIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[arrIndex] = arrValue; 
    arrSize++; 
}

//Deletes chosen index in user array
void Delete(int arr[], int& arrSize, int arrIndex) {
    arrSize--; 
    for(int i = arrIndex; i < arrSize; i++) {
        arr[i] = arr[i + 1]; 
    }
}

//Averages all numbers in user array 
double averageArrElements(int arr[], int arrSize) {
    double arrSum = 0; 
    for(int i = 0; i < arrSize; i++) { 
        arrSum += arr[i]; 
    }
    return arrSum / arrSize;
}

//Returns the max value of user array 
int returnArrMaxValue(int arr[], int arrSize) {
    int arrMaxValue = arr[0]; 
    for(int i = 1; i < arrSize; i++) {
       if(arrMaxValue < arr[i]) {
           arrMaxValue = arr[i];
       }
    }
    return arrMaxValue;
}

//Increases size of user array by 5
void growArrSize(int arr[], int& arrSize) {
    if(arrSize + 5 > MAX) {
        cout << "Cannot grow Array. Current Size: " << arrSize << " Max Size: " << MAX << "\n\n";
        return; 
    }

    for(int i = arrSize; i < arrSize + 5; i++) {
        arr[i] = 0;
    }
    arrSize += 5;

    cout << "Array size is now: " << arrSize << "\n\n";  
}

//Decreases size of user array by 5
void shrinkArrSize(int arr[], int& arrSize) {
    if(arrSize - 5 < MIN){ 
        cout << "Cannot shrink Array. Current Size: " << arrSize << " Minimum Size: " << MIN << "\n\n";
        return;
    }
    arrSize -= 5;
    
    cout << "Array size is now: " << arrSize << "\n\n";
    
}

//Fills user arrray in incrementing order
void fillSequence(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = i;
    }
}

//Sorts the user array in values least to greatest 
void arrLeastGreatest(int arr[], int arrSize) {
    for(int i = 0; i < (arrSize - 1); i++) {
        int tempVar;
        int currentMin = i;
        for(int j = i + 1; j < arrSize; j++) {
            if(arr[currentMin] > arr[j]) {
                currentMin = j;
            }
        }
        //cout << arr[currentMin] << "   " << currentMin << "\n"; Testing the loop 
        tempVar = arr[i];
        arr[i] = arr[currentMin];
        arr[currentMin] = tempVar; 
    }
}























