#ifndef MOVEACTION_H
#define MOVEACTION_H
#include <string>
#include "Player.h"
#include "Gameboard.h"
#include "Action.h"

using namespace std;

class Move_Action : public Action {

        public:

			Move_Action ();
			~Move_Action ();
	        void executeAction (int, Player*, int);


        private:
              
        	//Gameboard mab; // Move_Action Board
        	Player* map; // Move_Action Players


        };


#endif // MOVEACTION_H
