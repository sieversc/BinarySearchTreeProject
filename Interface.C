/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int main(){

	sType response;

	BSTree *list = new BSTree();

	cin >> response;

	list -> Insert(response);

	return(0);
}