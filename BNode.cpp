#include "BNode.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <iterator>

using namespace std;

// ************************** Public Functions *********************

/*------------------------------------------------------------------
Search method looks through entire tree for a given name. returns
true if found, false if not

Preconditions: pass in last name string.
Postconditions: returns boolean
------------------------------------------------------------------*/
BNode::BNode(){

	int count = 0;
}

/*------------------------------------------------------------------
Search method looks through entire tree for a given name. returns
true if found, false if not

Preconditions: pass in last name string and root of tree.
Postconditions: pointer to BNode of target. may return NULL
------------------------------------------------------------------*/
BNode::~BNode(){
}




//---------------------Searches--------------------
    
    /*------------------------------------------------------------------
    Search method looks through entire tree for a given name. returns
    true if found, false if not

    Preconditions: pass in last name string.
    Postconditions: returns boolean
    ------------------------------------------------------------------*/
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

    /*------------------------------------------------------------------
    Search method looks through entire tree for a given name. returns
    true if found, false if not

    Preconditions: pass in last name string and root of tree.
    Postconditions: pointer to BNode of target. may return NULL
    ------------------------------------------------------------------*/
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

//---------------------Accessors--------------------

    /*------------------------------------------------------------------
    accessor returns the last name field in BNode class

    Preconditions: nonde
    Postconditions: returns string lastname
    ------------------------------------------------------------------*/ 
    string BNode::GetLastName(){

        return(LastName);
    }

    /*------------------------------------------------------------------
    accessor returns the first name field in BNode class

    Preconditions: nonde
    Postconditions: returns set of first names
    ------------------------------------------------------------------*/
    set<string> BNode::GetFirstName(){

        return(FirstNames);
    }

//--------------------Print Methods---------------------
    
    /*------------------------------------------------------------------
    prints Last name of a given node1

    Preconditions: none
    Postconditions: none
    ------------------------------------------------------------------*/ 
    void BNode::PrintFirstNames(){
        set<string>::iterator iter;
        string name;

        cout << "   {  ";
        for(iter=FirstNames.begin(); iter!=FirstNames.end(); ++iter){
            cout << (*iter) << "  ";
        }

        cout << "}" << endl;
    }

    /*------------------------------------------------------------------
    prints all first names in set

    Preconditions: nonde
    Postconditions: none
    ------------------------------------------------------------------*/ 
    void BNode::PrintName(){

        cout << LastName << endl;
    }

//---------------------Mutators--------------------

    /*------------------------------------------------------------------
    mutator changes last name field in BNode class

    Preconditions: pass in desired name
    Postconditions: new last name
    ------------------------------------------------------------------*/
    void BNode::SetLastName(string data){

    	LastName = data;
    }

    /*------------------------------------------------------------------
    mutator replaces first name field

    Preconditions: pass in set of strings
    Postconditions: none
    ------------------------------------------------------------------*/
    void BNode::SetFirstName(set<string> names){
        
        FirstNames = names;
    }

    /*------------------------------------------------------------------
    mutator adds a name to the first name set in BNode

    Preconditions: pass in string
    Postconditions: length of first name set ++
    ------------------------------------------------------------------*/
    void BNode::AddFirstName(string name){
    	FirstNames.insert(name);
    	count++;
    }

    /*------------------------------------------------------------------
    mutator removes a name from the first name set in BNode class

    Preconditions: pass in name to be removed
    Postconditions: length of first name set --
    ------------------------------------------------------------------*/
    void BNode::RemoveFirstName(string name){
    	FirstNames.erase(name);
    	count--;
    }



