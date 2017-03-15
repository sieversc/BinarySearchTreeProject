#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;

// ************************** Public Functions *********************


BNode::BNode(){

    string LastName = NULL;
    set<string> FirstName;
    BNode *left = NULL;
    BNode *right = NULL;

}

BNode::~BNode(){
	/*
    string LastName = NULL;
    string FirstName = NULL;
    BNode *left = NULL;
    BNode *right = NULL;
*/
}

string BNode::GetLastName(){

	return(LastName);

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