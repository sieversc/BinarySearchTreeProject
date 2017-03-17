/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int MAX = 5;

int main(){

	SurvivorRegistry *reg = new SurvivorRegistry();

	reg -> Add("miller","john");

	reg -> PrintSurvivors();

	reg -> Count();

	return(0);

}
