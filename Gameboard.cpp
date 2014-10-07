#include <iomanip>
#include <iostream>
#include "Player.h"
#include "Action.h"
#include "Space.h"
#include "Gameboard.h"
#include "MoveAction.h"
#include "GotoAction.h"
#include "Card.h"
#include "LCard.h"
#include "IGCard.h"
#include "Bank.h"

using namespace std;

Gameboard::Gameboard () {

	// sets name of spaces
	spaces[0].setSpaceName ("|    GO     |");
	spaces[1].setSpaceName ("| Handshakes");
	spaces[2].setSpaceName ("|   Poise   ");
	spaces[3].setSpaceName ("|           ");
	spaces[4].setSpaceName ("|   Rage    ");
	spaces[5].setSpaceName ("|   Beards  ");
	spaces[6].setSpaceName ("| Capitalism");
	spaces[7].setSpaceName ("| Frankness ");
	spaces[8].setSpaceName ("|   Crying  ");
	spaces[9].setSpaceName ("|    You    ");
	spaces[10].setSpaceName ("|           ");
	spaces[11].setSpaceName ("|   Cabins  |");
	spaces[12].setSpaceName ("|  Masonry  |");
	spaces[13].setSpaceName ("|           |");
	spaces[14].setSpaceName ("|  Friends  |");
	spaces[15].setSpaceName ("|  Cursing  |");
	spaces[16].setSpaceName ("| Skim Milk |");
	spaces[17].setSpaceName ("| Intensity |");
	spaces[18].setSpaceName ("|   B.O.    |");
	spaces[19].setSpaceName ("|   Torso   |");
	spaces[20].setSpaceName ("|           ");
	spaces[21].setSpaceName ("|FishProtein");
	spaces[22].setSpaceName ("|           ");
	spaces[23].setSpaceName ("|    Love   ");
	spaces[24].setSpaceName ("|  Chicken  ");
	spaces[25].setSpaceName ("|Pig Protein");
	spaces[26].setSpaceName ("|Cow Protein");
	spaces[27].setSpaceName ("|WoodenShips");
	spaces[28].setSpaceName ("| Suspicion ");
	spaces[29].setSpaceName ("|   Trust   ");
	spaces[30].setSpaceName ("|           |");
	spaces[31].setSpaceName (" Discipline");
	spaces[32].setSpaceName (" Greatness ");
	spaces[33].setSpaceName ("  Haircuts ");
	spaces[34].setSpaceName ("   Greed   ");
	spaces[35].setSpaceName ("  Teamwork ");
	spaces[36].setSpaceName ("           ");
	spaces[37].setSpaceName ("  Buffets  ");
	spaces[38].setSpaceName ("  America  ");
	spaces[39].setSpaceName ("   Honor   "); 

	//first line of action text
	spaces[0].setActionText1 ("  Welcome  ");
	spaces[1].setActionText1 ("           |");
	spaces[2].setActionText1 ("          |");	
	spaces[3].setActionText1 ("Intervening| ");
	spaces[4].setActionText1 ("           |");
	spaces[5].setActionText1 ("           |");
	spaces[6].setActionText1 ("    Go     |");
	spaces[7].setActionText1 ("           |");
	spaces[8].setActionText1 ("    You    |");
	spaces[9].setActionText1 ("           |");
	spaces[10].setActionText1 ("|    Go     |");
	spaces[11].setActionText1 ("|           |");
	spaces[12].setActionText1 ("|           |");
	spaces[13].setActionText1 ("|           |");
	spaces[14].setActionText1 ("|    You    |");
	spaces[15].setActionText1 ("|           |");
	spaces[16].setActionText1 ("|           |");
	spaces[17].setActionText1 ("|           |");
	spaces[18].setActionText1 ("|           |");
	spaces[19].setActionText1 ("|           |");
	spaces[20].setActionText1 ("|    Go     |");
	spaces[21].setActionText1 ("           |");
	spaces[22].setActionText1 ("Intervening|");
	spaces[23].setActionText1 ("           |");
	spaces[24].setActionText1 ("    You    |");
	spaces[25].setActionText1 ("           |");
	spaces[26].setActionText1 ("           |");
	spaces[27].setActionText1 ("           |");
	spaces[28].setActionText1 ("    You    |");
	spaces[29].setActionText1 ("    You    |");
	spaces[30].setActionText1 ("    Go     ");
	spaces[31].setActionText1 ("           |");
	spaces[32].setActionText1 ("           |");
	spaces[33].setActionText1 ("           |");
	spaces[34].setActionText1 ("    You    |");
	spaces[35].setActionText1 ("           |");
	spaces[36].setActionText1 ("           |");
	spaces[37].setActionText1 ("           |");
	spaces[38].setActionText1 ("           |");
	spaces[39].setActionText1 ("           |");

	//second line of action text
	spaces[0].setActionText2 ("  Collect  ");
	spaces[1].setActionText2 ("   $210    |");
	spaces[2].setActionText2 ("   $220    |");	
	spaces[3].setActionText2 ("           |");
	spaces[4].setActionText2 ("   $240    |");
	spaces[5].setActionText2 ("   $250    |");
	spaces[6].setActionText2 ("    to     |");
	spaces[7].setActionText2 ("   $270    |");
	spaces[8].setActionText2 ("    Lose   |");
	spaces[9].setActionText2 ("   $290    |");
	spaces[10].setActionText2 ("|  Forward  |");
	spaces[11].setActionText2 ("|   $310    |");
	spaces[12].setActionText2 ("|   $320    |");
	spaces[13].setActionText2 ("|   $330    |");
	spaces[14].setActionText2 ("|    Lose   |");
	spaces[15].setActionText2 ("|   $350    |");
	spaces[16].setActionText2 ("|   $360    |");
	spaces[17].setActionText2 ("|   Life    |");
	spaces[18].setActionText2 ("|   $380    |");
	spaces[19].setActionText2 ("|   $390    |");
	spaces[20].setActionText2 ("|  Forward  |");
	spaces[21].setActionText2 ("   $410    |");
	spaces[22].setActionText2 ("           |");
	spaces[23].setActionText2 ("   $430    |");
	spaces[24].setActionText2 ("    Win    |");
	spaces[25].setActionText2 ("   $450    |");
	spaces[26].setActionText2 ("   $460    |");
	spaces[27].setActionText2 ("   $470    |");
	spaces[28].setActionText2 ("    Win    |");
	spaces[29].setActionText2 ("   Lose    |");
	spaces[30].setActionText2 ("  Forward  ");
	spaces[31].setActionText2 ("   $510    |");
	spaces[32].setActionText2 ("   $520    |");
	spaces[33].setActionText2 ("   $530    |");
	spaces[34].setActionText2 ("    Win    |");
	spaces[35].setActionText2 ("   $550    |");
	spaces[36].setActionText2 ("   Life    |");
	spaces[37].setActionText2 ("   $570    |");
	spaces[38].setActionText2 ("   $580    |");
	spaces[39].setActionText2 ("   $590    |");

	// third line of action text
	spaces[0].setActionText3 ("    $200   ");
	spaces[1].setActionText3 ("           |");
	spaces[2].setActionText3 ("           |");	
	spaces[3].setActionText3 ("Government |");
	spaces[4].setActionText3 ("           |");
	spaces[5].setActionText3 ("           |");
	spaces[6].setActionText3 ("    GO     |");
	spaces[7].setActionText3 ("           |");
	spaces[8].setActionText3 ("    $200   |");
	spaces[9].setActionText3 ("           |");
	spaces[10].setActionText3 ("|     10    |");
	spaces[11].setActionText3 ("|           |");
	spaces[12].setActionText3 ("|           |");
	spaces[13].setActionText3 ("|           |");
	spaces[14].setActionText3 ("|    $300   |");
	spaces[15].setActionText3 ("|           |");
	spaces[16].setActionText3 ("|           |");
	spaces[17].setActionText3 ("|           |");
	spaces[18].setActionText3 ("|           |");
	spaces[19].setActionText3 ("|           |");
	spaces[20].setActionText3 ("|    10     |");
	spaces[21].setActionText3 ("           |");
	spaces[22].setActionText3 ("Government |");
	spaces[23].setActionText3 ("           |");
	spaces[24].setActionText3 ("    $400   |");
	spaces[25].setActionText3 ("           |");
	spaces[26].setActionText3 ("           |");
	spaces[27].setActionText3 ("           |");
	spaces[28].setActionText3 ("    $400   |");
	spaces[29].setActionText3 ("    $400   |");
	spaces[30].setActionText3 ("    10     ");
	spaces[31].setActionText3 ("           |");
	spaces[32].setActionText3 ("           |");
	spaces[33].setActionText3 ("           |");
	spaces[34].setActionText3 ("    $500   |");
	spaces[35].setActionText3 ("           |");
	spaces[36].setActionText3("           |");
	spaces[37].setActionText3 ("           |");
	spaces[38].setActionText3 ("           |");
	spaces[39].setActionText3 ("           |");


	// creates new move_action 
	// sets action to spaces
	for (int i = 0; i < 40; i++) {		
		Move_Action* maSpaces;
		maSpaces = new Move_Action();
		spaces[i].setAction1 (maSpaces);
	}

	// creates new go_to action 
	// sets action to spaces
	for (int i = 0; i < 40; i++) {		
		GotoAction* gtSpaces;
		gtSpaces = new GotoAction();
		spaces[i].setAction2 (gtSpaces);
	}

	// creates deck of life cards
	LCard** LCards = new LCard*[2];

	// sets card actions to particular spaces 
		LCard* l1 = new LCard;
		LCards[0] = l1;
		spaces[17].setLCardAction1(l1);

		LCard* l2 = new LCard;
		LCards[1] = l2;
		spaces[17].setLCardAction2(l2);

		LCard* l3 = new LCard;
		LCards[0] = l3;
		spaces[36].setLCardAction1(l3);

		LCard* l4 = new LCard;
		LCards[1] = l4;
		spaces[36].setLCardAction2(l4);

	// creates deck of Intervening Government cards
	IGCard** IGCards = new IGCard*[2];

	for (int i = 0; i < 1; i++) {

	// sets card actions to particular spaces 
		IGCard* ig1 = new IGCard;
		IGCards[0] = ig1;
		spaces[3].setIGCardAction1(ig1);
		
		IGCard* ig2 = new IGCard;
		IGCards[1] = ig2;
		spaces[3].setIGCardAction2(ig2);

		IGCard* ig3 = new IGCard;
		IGCards[0] = ig3;
		spaces[22].setIGCardAction1(ig3);
		
		IGCard* ig4 = new IGCard;
		IGCards[1] = ig4;
		spaces[22].setIGCardAction2(ig4);

	}

	




}



void Gameboard::printBoard () {
	
	// creates top dashed line of gameboard 
	for (int i = 0; i < 133; i++) {

		cout << "-";

	}

	cout << endl;

	// prints space name
	for (int i = 20; i < 31; i++) {

		cout << spaces[i].getSpaceName ();

	}

	cout << endl;

	// 1 space is 6 lines, prints 6 lines
	for (int i = 0; i < 6; i++) {

		// row is 11 spaces, prints 11 spaces 
		for (int j = 0; j < 11; j++ ) {

			/*if (i == 2) {

				printPieces (10-i);

			} */

			if ( i == 1) {				

			cout << left << /*setw(12)*/ "|" << printPieces (20+j);

			}

			else if (i == 2 ) {

				cout << spaces[20+j].getActionText1 ();

			}

			else if (i == 3 ) {

				cout << spaces[20+j].getActionText2 ();

			}

			else if (i == 4 ) {

				cout << spaces[20+j].getActionText3 ();

			}

			else {

			cout << left << setw(12) << "|";

			}
		}

		// prints missing bar on the right
		for (int j = 0; j < 1; j++) {

			cout << right << "|";

		}

		cout << endl;

	}

	// prints dashed line on bottom of top horizontal  row 
	for (int i = 0; i < 133; i++) {

		cout << "-";

	}

	cout << endl;

	// creates 9 spaces on the vertical sides 
	for (int i = 0; i < 9; i++) {

		/* for (int j = 0; j < 13; j++ ) {

			cout << "-";

		} */
 
		//cout << right << setw(108) << "-------------";
		//cout << endl;

		// creates 6 lines for each space 
		for (int j = 0; j < 6; j++) {

			if (j==0) {

			cout << left << spaces[i+11].getSpaceName ();
			
			}

			//else {

			//	cout << left << /*setw(12)*/ "|" << printPieces (i+11) << "|";
			//}

			else if ( j == 1) {				

			cout << left << /*setw(12)*/ "|" << printPieces (19-i) << "|";

			}

			else if (j == 2 ) {

				cout << spaces[19-i].getActionText1 ();

			}

			else if (j == 3 ) {

				cout << spaces[19-i].getActionText2 ();

			}

			else if (j == 4 ) {

				cout << spaces[19-i].getActionText3 ();

			}

			else {

			cout << left << setw(12) << "|" << "|";

			}

/*
			if (i == 2) {

				printPieces (i+11);

			}
*/
			cout << right << setw(108) << "|";


			if (j==0) {
			
			cout << right << spaces[i+31].getSpaceName () << "|";
			
			}

			else if ( j == 1) {				

			cout << left << /*setw(12)*/ printPieces (39-i) << "|";

			}

			else if (j == 2 ) {

				cout << spaces[31+i].getActionText1 ();

			}

			else if (j == 3 ) {

				cout << spaces[31+i].getActionText2 ();

			}

			else if (j == 4 ) {

				cout << spaces[31+i].getActionText3 ();

			}

			else {

				cout << right << setw(12) << "|";

			}
/*
			if (i == 2) {

				printPieces (31+i);

			}
*/
			cout << endl;

		}

		// prints missing dashes for the spacces on the left vertical row
		 for (int j = 0; j < 13; j++) {

			cout << left << "-";

		} 

		if (i != 8) {
			cout << right << setw(120) << "-------------";
			cout << endl;
		}

	}

	// prints dashes for top of bottom horizontal row 
	for (int i = 0; i < 120; i++) {

		cout << "-";

	}


	cout << endl;


	// prints 11 spaces' names 
	for (int i = 0; i < 11; i++) {

			cout << spaces[10-i].getSpaceName ();

	} 

	cout << endl;

	// prints 6 lines for each space 
	for (int i = 0; i < 6; i++) {

		// prints 11 spaces 
		for (int j = 0; j < 11; j++ ) {

			
			if ( i == 1) {				

			cout << left << /*setw(12)*/ "|" << printPieces (10-j);

			}

			else if (i == 2 ) {

				cout << spaces[10-j].getActionText1 ();

			}

			else if (i == 3 ) {

				cout << spaces[10-j].getActionText2 ();

			}

			else if (i == 4 ) {

				cout << spaces[10-j].getActionText3 ();

			}

			else {

			cout << left << setw(12) << "|";

			}


		}

		for (int j = 0; j < 1; j++) {

			cout << right << "|";

		}

		cout << endl;

	}

	// prints dashes on bottom of bottom horizontal row 
	for (int i = 0; i < 133; i++) {

		cout << "-";

	}

	cout << endl;
}


void Gameboard::learnPlayerInfo(int tempNum, Player* tempP)
{
	numgamePlayers = tempNum;
	gamePlayers = tempP;
}

string Gameboard::printPieces(int spaceNum)
{
	string s = "";
	int counter = 0;
	
	// receives information for number of players in the game
	// in order to later print pieces 
	for(int i=0; i < numgamePlayers; i++)
	{
		if(gamePlayers[i].getSpaceIndex() == spaceNum)
		{
			s+=gamePlayers[i].getPiece();
			counter++;
		}
	}

	// same as above, but if there are not any players
	// it fills the rest of the line with 12-(number of players) on that space
	for (int j = 0; j < 12-(counter+1); j++) 
	{
		s += ' ';
	}

	counter = 0; 
	return s;
}




/*
for(int i=0; i < NumPlayers; i++)
{
	if(player[i].getspaceindex == 10)
	{
		cout << player[i].getPiece();
	}
} 
*/


/*
 << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << "-------------" << "|" << endl;
*/

/*
void Gameboard::reprintSpaces () {

	for (int i = 0; i < numPlayers; i++) {

		spaces[players[i].getSpaceIndex ()];

		found the space where there is a player. now you want to add that player's game piece to that space.
		at that space, it may have "ABD" you want to create a function that adds the specified player's game piece to that already existing string

		player[0].getspaceindex = 9

		spaces[9].addplayer0's game piece to that space

		create getPiece function in player class 

		after getting the piece, add it on to that space's string that already exists 

	}


} */

Gameboard::~Gameboard () {

}

Space* Gameboard::getSpaces () {

	return spaces;

}
