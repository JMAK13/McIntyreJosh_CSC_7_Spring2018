/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on February 21, 2018, 11:29 AM
 * Purpose: Displays Truth Tables, CSC7 Lab.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    //Declare Variables
    bool x,y;
    
    //Display Table Header
    cout<<" x | y | !x | !y | x&&y | x||y | x^y | (x^y)^x | (x^y)^y | !(x&&y) | !x||!y | !(x||y) | !x&&!y"<<endl;
    
    //Loop through table values
    for(int i=0; i<4; i++) {
        if(i==0) {x=1,y=1;}
        if(i==1) {x=1,y=0;}
        if(i==2) {x=0,y=1;}
        if(i==3) {x=0,y=0;}
            cout<<x<<"    "<<y<<"    "<<!x<<"    "<<!y<<"     "<<(x&&y)<<"     "<<(x||y)<<"      "<<(x^y)<<"       "<<((x^y)^x)<<"         "<<((x^y)^y)<<"          "
            <<(!(x&&y))<<"        "<<(!x||!y)<<"       "<<(!(x||y))<<"        "<<((!x)&&(!y))<<"       "<<endl;
    }
    
    //Display DeMorgans Law Hint
    cout<<"\nINFO: Last 4 on the right are DeMorgan's Law.\n";
    
    //Exits Program
    return 0;
}

