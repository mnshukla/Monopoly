#include "Bank.h"

Bank::Bank()
{

   money = 1000000000; // sets amount in bank

}

Bank::~Bank()
{
    //dtor
}

// adds money to bank amount 
void Bank::addMoney (int amount) {

	money += amount;

}

// reduces bank amount 
void Bank::loseMoney (int amount) {

	money -= amount;
	

}

//returns bank amount 
int Bank::getMoney () {

	return money;

}

