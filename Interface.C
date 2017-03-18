/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int main(){

	SurvivorRegistry *reg = new SurvivorRegistry();

	 reg -> Add("Jackson","stonewall");
	 reg -> Add("miller","john");
	 reg -> Add("miller","jim");
	reg -> Add("miller","hakeem");


	reg -> PrintSurvivors();

	reg -> Count();

	reg -> Search("miller");

	reg->Add("smith", "John");
	reg -> Search("smith");

	// BSTree* list = new BSTree();

	// list -> Insert(list->root, "c");
	// list -> Insert(list->root, "a");

	// list -> Insert(list->root, "b");

	// cout << list -> Search("b");

	//  list -> PrintInOrder(list->root);


	return(0);

}
