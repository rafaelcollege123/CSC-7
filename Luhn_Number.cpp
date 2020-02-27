/*
 * File:   main.cpp
 * Author:  Rafael Figueroa
 * Created on February 26 2020
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(int[],int);
void Luhn(int[],int);

int main(int argc, char** argv) {

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
   
    const int SIZE=12; //Array Sizes
    int crdCard[SIZE]; //Credit Card Array
    int mult_card[SIZE]; //Clone Array to Manipulate
    int total=0; //Total of Array after manipulation
    int luhn_num = 0; //Luhn Number Generated from algorithim
   
    prpLuhn(crdCard,SIZE-2);

    // Copy Card To second array for Manipulation while
    //Preserving original Card number
    for(int i = 0; i < SIZE ; i++)
    {
    mult_card[i] = crdCard[i];
    }
    //Prepare for Luhn encoding
    for(int i=1;i<SIZE-2; i=i+2)
    {
    //Multiply Everyother digit of array by 2
        mult_card[i] = crdCard[i]*2;
   
   
//If number is greater than 9 the sum of the two numbers creating
//2 digit number = the original number -9
        if(mult_card[i] >  9)
        {
            mult_card[i] = mult_card[i] - 9;
        }
    }
   
    //Add up the array elements of disposable array together
     for(int i=0; i<SIZE-2 ;i++)
    {
     total = total + mult_card[i];      
    }

//Finish calculating luhn number by multiplying by 9, and mod by 10
    luhn_num = (total*9)% 10;
   
    //Add luhn number to original Credit Card array
    crdCard[SIZE-2] = luhn_num;
   
//Output results using the orginal credit card array
    cout << endl << "A random number created in Prep for Luhn Digit: ";
    for(int i=0; i<SIZE-2; i++)
    {
        cout << crdCard[i];
    }
        cout << endl << "The random number with Luhn Encoding, Output Here!: ";
    for(int i=0; i<SIZE-1; i++)
    {
        cout << crdCard[i];
    }
   
   

    //Exit Stage Right
    return 0;
}

void prpLuhn(int cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10;
}
