#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "Player.h"

using namespace std;

class Action {

        public:

		Action ();
		~Action ();
        virtual void executeAction (int, Player*, int) = 0; // pure virtual function, making Action an abstract base class 


        private:
               

        };


#endif // ACTION_H
