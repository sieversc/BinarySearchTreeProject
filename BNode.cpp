#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>


// ************************** Public Functions *********************


BNode::BNode(){
/*
    sType LastName = NULL;
    sType FirstName = NULL;
    BNode *left = NULL;
    BNode *right = NULL;
*/
}

BNode::~BNode(){
	/*
    sType LastName = NULL;
    sType FirstName = NULL;
    BNode *left = NULL;
    BNode *right = NULL;
*/
}

sType BNode::GetLastName(){

	return(LastName);

}

void BNode::PrintName(){
    cout << LastName << endl;
}

bool BNode::Search(sType value){

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