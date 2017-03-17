#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;

// ************************** Public Functions *********************


BNode::BNode(){
	int count = 0;


}

BNode::~BNode(){

}



void BNode::PrintName(){
    cout << LastName << endl;
}

bool BNode::Search(string value){

    if (value == this->LastName){
        return true;
        }


    if(value < this->LastName){
        if(left != NULL){
            return(left->Search(value));
        }
        else{
            return false;
        }
    }


    if(value > this->LastName){
        if(right != NULL){
            return(right->Search(value));
        }
        else{
            return false;
        }
    }

    return false;
}

void BNode::SetLastName(string data){
	LastName = data;
}

void BNode::AddFirstName(string name){
	FirstNames.insert(name);
	count++;
}

void BNode::RemoveFirstName(string name){
	FirstNames.erase(name);
	count--;
}
/********************************************
------------------Accessors------------------
*********************************************/

string BNode::GetLastName(){

    return(LastName);
}

void BNode::PrintFirstNames(){
	
}