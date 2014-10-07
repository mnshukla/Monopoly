#include <iostream>
#include <iomanip> 
#include "GotoAction.h"

using namespace std; 

GotoAction::GotoAction () {


}

GotoAction::~GotoAction () {
	


}

// moves player 34 spaces forward 
void GotoAction::executeAction (int whichPlayer, Player* tempPlayers, int numRolled) {

	map = tempPlayers;

	map[whichPlayer].setSpaceIndex(34);


}