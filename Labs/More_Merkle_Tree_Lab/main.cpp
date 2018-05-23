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
    
    //Insert Strings Into Merkle Tree
    for(int i=0; i<12; i++)
        merkle.add(i);
    
    //Calculate Merkle Root
    printf("Merkle Root = %d\n\n", merkle.root());
    
    //Exits Program
    return 0;
}

//Hashing function
int hashF(int a, int b) {
  return a+b;
}