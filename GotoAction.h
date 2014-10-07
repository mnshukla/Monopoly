#ifndef GOTOACTION_H
#define GOACTION_H
#include <string>
#include "Player.h"
#include "Action.h"

using namespace std;

class GotoAction : public Action {

        public:

		GotoAction ();
		~GotoAction ();
        void executeAction (int, Player*, int);


        private:

        	Player* map;
               

        };


#endif // GOTOACTION_H
