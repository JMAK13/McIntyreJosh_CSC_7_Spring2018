/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on April 15, 2018, 4:06 PM
 */

//Global Constants

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Function Prototypes
bool used(int[],int,int);

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function with Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool valid=false;
    int input;
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Player Menu
    cout<<"Welcome to MasterMind by Josh McIntyre\nPress 0 to Exit\nPress 1 to Play\nPress 2 for Rules\n\n";
    do{
        cin>>input;
        if(input>=0&&input<=2) valid=true;
        else cout<<"Invalid input, press 0, 1, or 2";
    }while(!valid);
    
    switch(input) {
        //Exits Game
        case 0:{
            
            cout<<"Hope to see you again soon!"<<endl;
            return 0;
            
            //Exits Switch Statement
            break;
        }
        
        //Plays Game
        case 1:{
    
            //Declare Variables
            int key[4]={};
            int turns=0;
            bool won=false;

            //Initialize the Key
            for(int i=0; i<4; i++){
                bool val=false;
                do{
                    int n=rand()%8 + 1;
                    if(!used(key,i,n)) {key[i]=n;val=true;}
                }while(!val);
                cout<<key[i]<<" ";
            }

            //Game Loop
            do{
                int slots=0,colors=0;
                int color[4]={0,0,0,0};
                for(int i=0; i<4; i++) {
                    int num;
                    cout<<"Please guess a number[1-8] to put into column "<<i+1<<": ";
                    cin>>num;
                    if(key[i]==num)slots++;
                    if(used(key,4,num)&&!used(color,4,num))colors++;
                    color[i]=num;
                }

                //Displays Hints
                cout<<"Correct Slots:  "<<slots<<endl;
                cout<<"Correct Colors: "<<colors<<endl;

                //Checks if Player Won
                if(slots==4&&colors==4) {
                    won=true;
                    cout<<"Congrats you won the game in "<<turns+1<<" turns!!!"<<endl;
                }

                //Increments Turns
                turns++;
            }while(turns<10&&!won);
            
            if(!won) cout<<"Sorry you lost!!!"<<endl;
            
            //Exits Switch Statement
            break;
        }
        
        //Displays Rules
        case 2:{
            
            cout<<"The player will be given 10 turns to try and decrypt the secret key given only 2 hints per turn:\n";
            cout<<"1) the number of correct slots they guessed\n";
            cout<<"2) the number of correct colors they guessed\n";
            cout<<"The key is 4 characters long and each character is one of the numbers 1 through 8,\ntherefore, the player must make guesses of only the numbers 1 through 8";
            
            //Exits Switch Statement
            break;
        }
    }

    //Exits Program
    return 0;
}

//Checks to see if the value is already being used
bool used(int array[], int n, int num){
    for(int i=0; i<n; i++) {
        if(array[i]==num) return true;
    }
    return false;
}

