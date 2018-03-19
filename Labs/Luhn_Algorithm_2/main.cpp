/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//American Express is 15char long and starts with 3
//Visa is 16char long and starts with 4
//Discover is 16char long and starts with 6011
//Master Card 16char long and starts with 5

/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Purpose: Luhn Algorithm 2
 * Created on March 7, 2018, 11:23 AM
 */

//System Libraries
#include <iostream>//cout
#include <ctime>//time(0)
#include <cstdlib>//srand(),rand()
#include <cstring>//strlen()
using namespace std;

//User Libraries
#include "enums.h"

//Global Constants

//Function Prototypes
void genCC(CrdCard,char []);
void flipDig(char []);
bool validCC(char []);

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variables
    const int MAXSIZE=15;
    char digits[MAXSIZE]={};
    int falses=0, trues=0;
    CrdCard card1=VISA, card2=DISCOVER, card3=AMERICAN_EXPRESS, card4=MASTER_CARD;
    
    //Loop Through Cards and Perform Calculations
    //VISA
    for(int i=0; i<10000; i++) {
        genCC(card1, digits);
        flipDig(digits);
        if(validCC(digits)) trues++;
        else falses++;
    }
    //Display Output
    cout<<"VISA"<<endl;
    cout<<"Trues: "<<trues<<endl;
    cout<<"Falses: "<<falses<<endl<<endl;
    trues=0,falses=0;
    
    //DISCOVER
    for(int i=0; i<10000; i++) {
        genCC(card2, digits);
        flipDig(digits);
        if(validCC(digits)) trues++;
        else falses++;
    }
    //Display Output
    cout<<"DISCOVER"<<endl;
    cout<<"Trues: "<<trues<<endl;
    cout<<"Falses: "<<falses<<endl<<endl;
    trues=0,falses=0;
    
    //AMERICAN_EXPRESS
    for(int i=0; i<10000; i++) {
        genCC(card3, digits);
        flipDig(digits);
        if(validCC(digits)) trues++;
        else falses++;
    }
    //Display Output
    cout<<"AMERICAN EXPRESS"<<endl;
    cout<<"Trues: "<<trues<<endl;
    cout<<"Falses: "<<falses<<endl<<endl;    
    trues=0,falses=0;
    
    //MASTER_CARD
    for(int i=0; i<10000; i++) {
        genCC(card4, digits);
        flipDig(digits);
        if(validCC(digits)) trues++;
        else falses++;
    }
    //Display Output
    cout<<"MASTER CARD"<<endl;
    cout<<"Trues: "<<trues<<endl;
    cout<<"Falses: "<<falses<<endl<<endl;
    trues=0,falses=0;
    
    //Exits Program
    return 0;
}

//Generates Card Number
void genCC(CrdCard card, char array[]) {
    if(card==AMERICAN_EXPRESS) {
        for(int i=0; i<15; i++){
            array[i]=rand()%10+48;
        }
        array[0]=51;
    }
    else if(card==VISA) {
        for(int i=0; i<16; i++){
            array[i]=rand()%10+48;
        }
        array[0]=52;
    }
    else if(card==DISCOVER) {
        for(int i=0; i<16; i++){
            array[i]=rand()%10+48;
        }
        array[0]=54;
        array[1]=48;
        array[2]=49;
        array[3]=49;
    }
    else if(card==MASTER_CARD) {
        for(int i=0; i<16; i++){
            array[i]=rand()%10+48;
        }
        array[0]=53;
    }
}

//Flips Card Number Digit
void flipDig(char array[]) {
    int rndIndx=rand()%strlen(array);
    int rndNum=rand()%10+48;
    array[rndIndx]=rndNum;
}

//Validates Card
bool validCC(char array[]) {
    if(strlen(array)==15&&array[0]==51) return true;
    else if(strlen(array)==16) {
        if(array[0]==52||array[0]==53) return true;
        else if(array[0]==54&&array[1]==48&&array[2]==49&&array[3]==49) return true;
        else return false;
    }
    else return false;
}