#include "LCard.h"
#include "Bank.h"
#include <iostream>

LCard::LCard()
{
    //ctor
}

LCard::~LCard()
{
    //dtor
}

// ith index of players array passed in to determine particular player
// player array passed in 
// number rolled passed in 
// in order to move player forward 15 spaces 
void LCard::moveAction (int whichPlayer, Player* tempPlayers, int numRolled) {

	lp = tempPlayers;

	cout << "\nYou found a missing sawmill! Move forward!" << endl;

	lp[whichPlayer].setSpaceIndex(15);

}

// ith index of players array passe din to determine particular player 
// players array passed in 
// bank passed in to reduce bank amount and increase player amount 
void LCard::moneyAction (int whichPlayer, Player* tempPlayers, Bank* tempBank) {


	lp = tempPlayers;

	bankTemp = tempBank;

	cout << "\nYou hunted an endangered species! You gain $300!" << endl;

	lp[whichPlayer].addMoney(300);

	bankTemp->loseMoney(300);

}