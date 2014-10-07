#ifndef CARD_H
#define CARD_H
#include "Player.h"
#include "Bank.h"

class Card {
	

	public: 

	Card ();
	~Card ();
	virtual void moveAction (int, Player*, int) = 0; // pure virtual function 
	virtual void moneyAction (int, Player*, Bank*) = 0; // pure virtual function 



	private:

};


#endif