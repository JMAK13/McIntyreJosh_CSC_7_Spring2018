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
            if(key[i]-'0'<0||key[i]-'0'>9){
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
        cout<<"Number of Guesses: "<<guesses.size()<<endl;
        
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
    }while(turns<35 && !solved);
    
    //Exits Program
    return 0;
}

//AI Function
string AI(vector<string> guesses, vector<int> clues1, vector<int> clues2, vector<int> &pNums){
    
    //Declare AI Variables
    string guess;
    bool sum4=false;
    
    //Initial Guess
    if(guesses.size()==0) return "0000";
    
    //If Numbers Are Correct Guess New Order
    for(int i=0; i<guesses.size(); i++){
        if((clues1[i]+clues2[i])==4) {
            sum4=true;
            int j=0;
            guess=guesses[i];
            do{
                int swap1=rand()%4,swap2=rand()%4;
                int temp=guess[swap1];
                guess[swap1]=guess[swap2];
                guess[swap2]=temp;
            }while(contains(guesses,guess));
            return guess;
        }else sum4=false;
    }
    
    //Try To Find New Numbers
    if(!sum4){
        int last=guesses.size()-1;
        guess=guesses[last];
        string tGuess=guess;
           
        if(pNums.size()==4){
            tGuess[0]=pNums[0];
            tGuess[1]=pNums[1];
            tGuess[2]=pNums[2];
            tGuess[3]=pNums[3];
            if(!contains(guesses, tGuess)) return tGuess;
        }
            
        else if(clues1[last]>0){
            for(int y=0; y<clues1[last]; y++){
                pNums.push_back(guess[0]);
            }
        }
            
        guess[0]++;
        guess[1]++;
        guess[2]++;
        guess[3]++;
        
        return guess;
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

