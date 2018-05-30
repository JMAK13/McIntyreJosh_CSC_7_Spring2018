/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 22, 2018, 5:19 PM
 */

//Global Constants

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

//User Libraries

//Function Prototypes
string AI(vector<string>, vector<int>, vector<int>, vector<int> &);
bool contains(vector<string>,string);

//Main Function
int main(int argc, char** argv) {
    
    //Declare Variables
    string key;
    vector<string> guesses;
    vector<int> clues1;
    vector<int> clues2;
    vector<int> pNums;
    int turns=0;
    bool solved=false;

    //Prompt User for Input
    cout<<"Welcome to MasterMind Solver by Josh McIntyre!\n\n";
    cout<<"Please enter a 4 digit key with digits ranging from 0 to 9: ";
    cin>>key;
    
    //Validate Input
    for(int i=0; i<4; i++){
        bool done=false;
        do{
            if(key[i]-46<0||key[i]-46>9){
                cout<<"Please enter a new digit: ";
                cin>>key[i];
            } else done=true;
        }while(!done);
    }
    
    //Game Loop
    do{
        
        //Declare Game Variables
        int slots=0,colors=0;
        string guess,rGuess;
        string check="    ";
        
        //Displays Key and Guess
        cout<<"Key: "<<key[0]<<key[1]<<key[2]<<key[3]<<endl;
        guess=AI(guesses,clues1,clues2,pNums);
        rGuess=guess;
        cout<<"Guess: "<<guess<<endl;
        
        //Check how many are right place
        for(int i=0;i<key.length();i++){
            if(key[i]==guess[i]){
                slots++;
                check[i]='x';
                guess[i]='x';
            }
        }
        
        //Check how many are wrong place
        for(int j=0;j<key.length();j++){
            for(int i=0;i<key.length();i++){
                if((i!=j)&&(key[i]==guess[j])&&(check[i]==' ')){
                    colors++;
                    check[i]='x';
                    break;
                }
            }
        }
        
        //Displays Clues
        cout<<"Correct Slots: "<<slots<<endl;
        cout<<"Correct Colors: "<<colors<<endl;
        
        //Checks End Game Condition
        if(slots==4) {
            solved=true;
            cout<<"Congratulations, you solved the key!\n";
        }
        
        //Puts Information Into Arrays for AI
        guesses.push_back(rGuess);
        clues1.push_back(slots);
        clues2.push_back(colors);
        
        //Blanks Screen
        cout<<"\n\n\n\n\n";
        
        //Increments Turns
        turns++;
    }while(turns<20 && !solved);
    
    //Exits Program
    return 0;
}

//AI Function
string AI(vector<string> guesses, vector<int> clues1, vector<int> clues2, vector<int> &pNums){
    
    //Declare AI Variables
    string guess;
    
    //Initial Guess
    if(guesses.size()==0) return "0011";
    
    for(int i=0; i<guesses.size(); i++){
        if(clues1[i]+clues2[i]==4) {
            int j=0,t=0;
            do{
                guess=guesses[i];
                int tmp=guess[j];
                guess[j]=guess[j+1];
                guess[j+1]=tmp;
                j++;
            }while(contains(guesses, guess));
        }else{
            guess=guesses[guesses.size()-1];
            if(pNums.size()==4) {guess[0]=pNums[i]; guess[1]=pNums[1]; guess[2]=pNums[2]; guess[3]=pNums[3];return guess;}
            if(clues2[i]==2) {pNums.push_back(guess[0]); pNums.push_back(guess[2]);}
            if(clues1[i]==1&&clues2[i-1]==1) pNums.push_back(guess[2]);
            guess[0]++;
            guess[1]++;
            guess[2]++;
            guess[3]++;
        }
    }
    
    return guess;
}

//Utility Function
bool contains(vector<string> guesses, string str){
    for(int i=0; i<guesses.size(); i++){
        if(str.compare(guesses[i])==0) return true;
    }
    return false;
}

