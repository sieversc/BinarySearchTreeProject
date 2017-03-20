#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <iterator>

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


/******************************************
------------------Searches---------------------
*******************************************/
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

bool BNode::Search(string value, BNode *node){

	if (value == this->LastName){
		node = this;
        return true;
    }


    if(value < this->LastName){
        if(left != NULL){
            return(left->Search(value, node));
        }
        else{
            return false;
        }
    }


    if(value > this->LastName){
        if(right != NULL){
            return(right->Search(value, node));
        }
        else{
            return false;
        }
    }

    return false;
}

BNode* BNode::BSearch(string value, BNode *node){

    if(node==NULL){
        if(value == node->LastName){
            return node;
        }
        if(value < node->LastName){
            return(BSearch(value, node->left));
        }
        if(value > node->LastName){
            return(BSearch(value, node->right));
        }
    }
    else{
        return NULL;
    }
}

/******************************************
--------------------Mutators-----------------
******************************************/

void BNode::SetLastName(string data){

	LastName = data;
}

void BNode::SetFirstName(set<string> names){
    
    FirstNames = names;
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

set<string> BNode::GetFirstName(){

    return(FirstNames);
}

void BNode::PrintFirstNames(){
	set<string>::iterator iter;
	string name;

	cout << "	{  ";
	for(iter=FirstNames.begin(); iter!=FirstNames.end(); ++iter){
		cout << (*iter) << "  ";
	}

	cout << "}"	<< endl;
}

