#include "Gameboard.h"
#include "Space.h"
#include "Player.h"
#include "Action.h"
#include <iostream>
#include <iomanip>
#include <string>

Space::Space()
{
   

}

Space::~Space () {



}

void Space::setAction1 (Action* tempAction) {

	as1 = tempAction;

}

void Space::setAction2 (Action* tempAction) {

	as2 = tempAction;

}

void Space::setLCardAction1 (LCard* tempCard) {


	lc1 = tempCard;

}

void Space::setLCardAction2 (LCard* tempCard) {


	lc2 = tempCard;

}

void Space::setIGCardAction1 (IGCard* tempCard) {

	igc1 = tempCard;


}

void Space::setIGCardAction2 (IGCard* tempCard) {


	igc2 = tempCard;

}



void Space::setActionText1 (string text) {

	actionText1 = text;

}


void Space::setActionText2 (string text) {


	actionText2 = text;

}

void Space::setActionText3 (string text) {


	actionText3 = text;


}

string Space::getActionText1 () {

	return actionText1;

}

string Space::getActionText2 () {

	return actionText2;

}

string Space::getActionText3 () {


	return actionText3;

}


void Space::setSpaceName (string Name) {

	
	name = Name;


}

string Space::getSpaceName() {

	return name;

}


// points to executeAction in moveAction class
void Space::callExecuteAction1 (int whichPlayer, Player* playersinGame, int numberRolled) {

	as1->executeAction (whichPlayer, playersinGame, numberRolled);

}

// points to executeAction in gotoaction class
void Space::callExecuteAction2 (int whichPlayer, Player* playersinGame, int numberRolled) {


	as2->executeAction (whichPlayer, playersinGame, numberRolled);


}

// points to moveaction in lcard class
void Space::callMoveActionL1 (int whichPlayer, Player* playersinGame, int numberRolled) {

	lc1->moveAction (whichPlayer, playersinGame, numberRolled);

}

// points to moneyaction in lcard class
void Space::callMoneyActionL2 (int whichPlayer, Player* playersinGame, Bank* tempBank) {

	lc2->moneyAction (whichPlayer, playersinGame, tempBank);

}

// points to moveaction in igcard class
void Space::callMoveActionIG1 (int whichPlayer, Player* playersinGame, int numberRolled) {

	igc1->moveAction (whichPlayer, playersinGame, numberRolled);

}

// points to moneyaction in igcard class
void Space::callMoneyActionIG2 (int whichPlayer, Player* playersinGame, Bank* tempBank) {

	igc2->moneyAction (whichPlayer, playersinGame, tempBank);

}
