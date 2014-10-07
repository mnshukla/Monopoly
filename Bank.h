#ifndef BANK_H
#define BANK_H
#include <string>

using namespace std;

class Bank {

        public:

		Bank ();
		~Bank ();
		void addMoney (int); // adds money to bank
		void loseMoney (int); // reduces amount in bank
		int getMoney (); // gets amount in bank

        private:

        	int money; 

        };


#endif // BANK_H
