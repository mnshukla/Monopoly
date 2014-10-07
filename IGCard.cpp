#include "IGCard.h"
#include "Bank.h"
#include <iostream>

IGCard::IGCard()
{
    //ctor
}

IGCard::~IGCard()
{
    //dtor
}

// ith index of players array passed in to determine particular player
// players array passed in
// number rolled paassed in 
// to move player forward 35 spaces
void IGCard::moveAction (int whichPlayer, Player* tempPlayers, int numRolled) {

	igp = tempPlayers;

	cout << "\nYou participate in a protest.\n"; 
	cout << "We don't need anymore hippies." << endl;
	cout << "Go back 5 spaces." << endl;

	igp[whichPlayer].setSpaceIndex(35);

}

// ith index of players array passed in to determine particular player
// player array passed in 
// bank passed in 
// to reduce player amount and increase bank amount 
void IGCard::moneyAction (int whichPlayer, Player* tempPlayers, Bank* tempBank) {

	igp = tempPlayers;

	bankTemp = tempBank;

	cout << "\nYou ran for public office and lost. " << endl;
	cout << "Serves you right for thinking the government could do something." << endl;
	cout << "You lose $1000." << endl;

	igp[whichPlayer].loseMoney(1000);

	bankTemp->addMoney(1000);

}