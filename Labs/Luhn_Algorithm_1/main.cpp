/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on February 24, 2018, 1:24 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes

int main(int argc, char** argv) {
    
    //Declare Variables
    const int MAX=10;
    int sum,check;
    int cc[MAX]={};
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill Array & Prompt User
    cout<<"Credit Card Number: ";
    for(int i=0; i<MAX; i++) {
        cc[i]=1+(rand()%9);
        cout<<cc[i]<<"   ";
    }
    
    //Perform Calculations
    cout<<"\nDoubled Numbers: ";
    for(int i=0; i<MAX; i++) {
        //Check if the index number is odd, keep it the same if it is even
        if(i%2!=0) {
            cc[i]=cc[i]*2;
            //Check if the doubled number will be greater than 9
            if((cc[i]*2)>9) {
                //Replace the number at the index with the sum of each of the number's digits
                int rem=cc[i]%10, temp=cc[i]-rem;
                cc[i]=rem+temp;
            }
        }
        //Sum up the total of all numbers in the array
        cout<<cc[i]<<"  ";
        sum+=cc[i];
    }
    //Multiply the sum by 9
    sum*=9;
    //Strip the final number down so only it's final digit remains
    while(sum>=10) {
        sum%=10;
    }
    
    //Display Output
    cout<<"\nCheck Number Is: "<<sum<<endl;
    //Checks if the Luhn formula is valid or not for the check digit calculated
    if (sum==0)
        cout<<"The number is valid according to the Luhn formula."<<endl;
    else
        cout<<"The number is not valid according to the Luhn formula."<<endl;
    
    //Exits Program
    return 0;
}




