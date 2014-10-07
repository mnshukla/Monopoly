#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>

#include "Space.h"
#include "Player.h"

using namespace std;

class Gameboard {

        public:

		Gameboard ();
		
		void printBoard (); 
		void learnPlayerInfo(int, Player*);
		string printPieces(int spaceNum);
		~Gameboard ();
		Space* getSpaces ();

        private:
        Player* gamePlayers;
        Space spaces[40];
        int numgamePlayers;

     };


#endif // GAMEBOARD_H