#include <iostream>
#include <iomanip> 
#include "MoveAction.h"

using namespace std; 

Move_Action::Move_Action () {


}

Move_Action::~Move_Action () {
	


}

// ith index of players array passed in to determine particular player 
// players array passed in 
// number rolled passed in 
// to move player forward 10 spaces 
void Move_Action::executeAction (int whichPlayer, Player* tempPlayers, int numRolled) {

	map = tempPlayers;

	map[whichPlayer].setSpaceIndex(10);


	//mab.printBoard ();

}