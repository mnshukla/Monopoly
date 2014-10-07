#include "Gameboard.h"
#include "Space.h"
#include "Player.h"
#include "Action.h"
#include <string>

Player::Player ()
{
    money = 0;
}


Player::~Player ()
{
    //dtor
}

/*
// allow player to move forward number of spaces based on dice roll
void Player::moveSpaces(int numRolled) {

	int temp = currentSpace;
	
	currentSpace = temp % 40;

}
*/

// allow currentSpace to be used as public
int Player::getSpaceIndex() {

	return currentSpace;

}
/*
void Player::setSpaceIndex (int tempIndex) {

	currentSpace = tempIndex;

}
*/



void Player::setSpaceIndex (int numRolled) {

	currentSpace = currentSpace + numRolled;

	currentSpace = currentSpace % 40;

}


void Player::setPiece (char p) {

	piece = p;

	
}

char Player::getPiece () {

	return piece;

}

int Player::getMoney () {

	return money;

}

// adds money to players amount based on amount passed in by action 
void Player::addMoney (int amount) {

	int temp = money + amount;
	money = temp;

}

// reduces money from players amount based on ammount passed in by action 
void Player::loseMoney (int amount) {

	int temp = money - amount;
	money = temp;

}

