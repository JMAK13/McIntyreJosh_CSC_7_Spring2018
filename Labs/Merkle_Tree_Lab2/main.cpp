/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 23, 2018, 10:20 AM
 */

//Global Constants

//System Libraries
#include <vector>
#include <iostream>
using namespace std;

//User Libraries

//Function Prototypes
int hashF(int,int);
unsigned int RSHash(const string&);

//Merkle Tree Class
class Merkle {

private:
    //Array of Values
    vector<int> values;
    int (*hasher)(int, int);

public:
    
    //Merkle Constructor
    Merkle(int (*f)(int,int)){
      this->hasher = f;
    }

    //Add Member Function
    void add(int value){
      values.push_back(value);
    }

    //Merkle Root Member Function
    int root(){
    vector<int> current;

    current = getHashedParents(this->values);
    while (current.size() != 1) {
        current = getHashedParents(current);
    }
    
    return current[0];
  }

private:
  vector<int> getHashedParents(const vector<int> &leaves) {
    vector<int> result;

    for (int i=0; i<leaves.size(); ) {
      int a = leaves[i], b = leaves[i];
      if (++i<leaves.size()) {
        b=leaves[i++];
      }
      int hash = this->hasher(a,b);
      cout<<"Hash: ("<<a<<", "<<b<<")="<<hash<<"    ";
      result.push_back(hash);
    }
    printf("\n");
    return result;
  }
};

//Main Function
int main(int argc, char** argv) {
    
    //Declare Variables
    int hash[4]={};
    Merkle merkle = Merkle(hashF);
    
    //Hash Strings
    hash[0]=RSHash("Then out spake brave Horatius,\nThe Captain of the Gate:\n");
    hash[1]=RSHash("\"To every man upon this earth\nDeath cometh soon or late.\n");
    hash[2]=RSHash("And how can man die better\nThan facing fearful odds,\n");
    hash[3]=RSHash("For the ashes of his fathers,\nAnd the temples of his Gods.\"");
    unsigned int rRoot=RSHash("Then out spake brave Horatius,\nThe Captain of the Gate:\n\"To every man upon this earth\nDeath cometh soon or late.\nAnd how can man die better\nThan facing fearful odds,\nFor the ashes of his fathers,\nAnd the temples of his Gods.\"");
    

    //Insert Strings Into Merkle Tree
    for(int i=0; i<4; i++)
        merkle.add(hash[i]);
    
    //Calculate Merkle Root
    printf("Merkle Root = %d\n\n", merkle.root());
    cout<<"Predicted Root: "<<rRoot<<endl;
    //Exits Program
    return 0;
}

//Hashing function
int hashF(int a, int b) {
  return a+b;
}

unsigned int RSHash(const string& str){
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}