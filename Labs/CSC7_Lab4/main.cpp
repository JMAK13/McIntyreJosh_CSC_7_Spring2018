/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on March 29, 2018, 11:37 AM
 */

//Global Constants

//System Libraries
#include <iostream>
#include <string>
#include "GeneralHashFunctions.h"
using namespace std;

//User Libraries

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    const string key = "Then out spake brave Horatius,\nThe Captain of the Gate:\nTo every man upon this earth\nDeath cometh soon or late.\nAnd how can man die better\nThan facing fearful odds,\nFor the ashes of his fathers,\nAnd the temples of his gods.";

    cout<<endl;
    cout<<"General Purpose Hash Function Algorithms Test"<<endl;
    cout<<"Key: "<<key<<endl;
    cout<<" 1) RS-Hash Function Value:   "<<RSHash(key)<<endl;
    cout<<" 2) JS-Hash Function Value:   "<<JSHash(key)<<endl;
    cout<<" 3) PJW-Hash Function Value:  "<<PJWHash(key)<<endl;
    cout<<" 4) ELF-Hash Function Value:  "<<ELFHash(key)<<endl;
    cout<<" 5) BKDR-Hash Function Value: "<<BKDRHash(key)<<endl;
    cout<<" 6) SDBM-Hash Function Value: "<<SDBMHash(key)<<endl;
    cout<<" 7) DJB-Hash Function Value:  "<<DJBHash(key)<<endl;
    cout<<" 8) DEK-Hash Function Value:  "<<DEKHash(key)<<endl;
    cout<<" 9) FNV-Hash Function Value:  "<<FNVHash(key)<<endl;
    cout<<"10) BP-Hash Function Value:   "<<BPHash(key)<<endl;
    cout<<"11) AP-Hash Function Value:   "<<APHash(key)<<endl;

    return 0;
}