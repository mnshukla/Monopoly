#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Bank.h"

using namespace std;

   class Player {

        public:

            Player ();
            ~Player ();
            // void moveSpaces (int numRolled);
            int getSpaceIndex (); 
	        void setSpaceIndex (int numRolled);
            void setPiece (char);
            char getPiece();
            int getMoney ();
            void addMoney (int);
            void loseMoney (int);

        private:

            int currentSpace; // equals the dice roll
            // when at  the last index 39, use %
            int money;
            int playerid;
            char piece;
           // int numPlayers;

    };


#endif // PLAYER _H
