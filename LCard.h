#ifndef LCARD_H
#define LCARD_H
#include <string>
#include "Bank.h"
#include "Player.h"
#include "Card.h"

using namespace std;

class LCard : public Card {

        public:

		LCard ();
		~LCard ();
		void moveAction (int, Player*, int);
		void moneyAction (int, Player*, Bank*);


        private:

        Player* lp;
        Bank* bankTemp; 


};


#endif // LCARD_H
