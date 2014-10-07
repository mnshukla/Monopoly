#ifndef IGCARD_H
#define IGCARD_H
#include <string>
#include "Player.h"
#include "Bank.h"
#include "Card.h"

using namespace std;

class IGCard : public Card {

        public:

		IGCard ();
		~IGCard ();
		void moveAction (int, Player*, int);
		void moneyAction (int, Player*, Bank*);


        private:

        Player* igp;
        Bank* bankTemp; 


        };


#endif // IGCARD_H