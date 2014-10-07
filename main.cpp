#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Player.h"
#include "Action.h"
#include "Space.h"
#include "Gameboard.h"
#include "MoveAction.h"
#include "Bank.h"

using namespace std;

// Global Variables 
// const int NUMSPACES = 40;
// Space spaces[NUMSPACES];
Gameboard gameBoard;
Player players[4];
Bank bank;
int igcounter = 0;
int lcounter = 0;
int numPlayers;
int numRolled;
char playerOptions[10] = { 'R', 'L', 'T', 'A', 'D', 'J', 'P', 'C', 'M', 'B'}; // pieces for players
bool optionsChosen[10] = { false, false, false, false, false, false, false, false, false, false }; // determines if piece has been chosen or not

// pointers to players who own spaces to add money to their amounts if player lands on space
Player* t1;
Player* t2;
Player* t3;
Player* t4;
Player* t5;
Player* t6;
Player* t7;
Player* t8;
Player* t9;
Player* t10;
Player* t11;
Player* t12;
Player* t13;
Player* t14;
Player* t15;
Player* t16;
Player* t17;
Player* t18;
Player* t19;
Player* t20;
Player* t21;
Player* t22;
Player* t23;
Player* t24;
Player* t25;

// determines if space is owned by someone 
bool propertyChosen[25] = { false, false, false, false, false, false, false, false, false, false, 
                false, false, false, false, false, false, false, false, false, false,
                false, false, false, false, false };

// Function Prototypes 
void choosePlayer ();
void diceAndSpaces (); 


int main () {

    srand(time(NULL));
    
    choosePlayer();

    gameBoard.learnPlayerInfo(numPlayers, players);

    // subtracts money from bank in order to give to players for starting amount
    bank.loseMoney(1500*numPlayers);

    // addds money to players' amount for starting amount 
    for (int i = 0; i < numPlayers; i++) {

        players[i].addMoney(1500);

    }

   // m_a.executeAction(numPlayers, players, numRolled);

  //  gameBoard.printActionText ();

	gameBoard.printBoard ();

    diceAndSpaces ();

}


void diceAndSpaces () {


		int entry;



		// Allows each user to roll the dice

        while(true)
        {


    		for (int i = 0; i < numPlayers; i++) {	
    		
    			cout << "\nPlayer " << i +1 << "'s turn to roll the dice!" << endl;
                cout << "Press 1 to roll the dice." << endl;
    			cout << "Press 2 to exit the game." << endl;
    		
    			bool loop = true;
    		
    			while (loop) {	
    		
    				cin >> entry;
    			
    				if (cin.fail()) {
    			
    					cout << "Error! Please try again!" << endl;
    					cin.clear ();
    					cin.ignore(1000, '\n');
    			
    				}
    			
    				if (entry != 1 && entry != 2) {
    			
    					cout << "\nWrong key. Press 1 to roll the dice." << endl;
    			
    				}
    			
    				if (entry == 1) {
    			
    					loop = false;
    			
    				}

                    if (entry == 2) {

                        cout << "\nGood. You were getting on my nerves. Go away.\n" << endl;

                        exit (0);

                    }
    			}
    				numRolled = (rand () % 12) + 1;
    				
    				cout << "\nPlayer " << i + 1 << " rolled a(n) " << numRolled << "." << endl;
                    cout << "Player " << i + 1 << " has $" << players[i].getMoney () << "." << endl; 

    				players[i].setSpaceIndex(numRolled);

                    // pointer to spaces array 
                    Space* spacesptr1 = gameBoard.getSpaces();

                    // holds space Index number 
                    int spaceIndex = players[i].getSpaceIndex ();

                    if (spaceIndex < 6 && spaceIndex >= 0) {

                        cout << "\nPlay the game as well as you can! Collect $200!" << endl;

                        players[i].addMoney(200);

                        cout << "\nPlayer " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 

                        bank.loseMoney(200);

//                        cout << "Bank amount: $" << bank.getMoney () << endl;

                    }


                    if (spaceIndex == 8) {


                            cout << "\nReal men don't cry. You lose $200.\n" << endl;

                            players[i].loseMoney(200);

                            bank.addMoney(200);

                            cout << "\nPlayer " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 14) {


                            cout << "\nAvoid skim milk. You lose $300.\n" << endl;

                            players[i].loseMoney(300);

                            bank.addMoney(300);

                            cout << "Player " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 24) {


                            cout << "\nChicken is the food of gods. You gain $400.\n" << endl;

                            players[i].addMoney(400);

                            bank.loseMoney(400);

                            cout << "Player " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 28) {


                            cout << "\nGood. Always be suspicious of others. You gain $400.\n" << endl;

                            players[i].addMoney(400);

                            bank.loseMoney(400);

                            cout << "Player " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 29) {


                            cout << "\nYou idiot. Trust no one. You lose $400.\n" << endl;

                            players[i].loseMoney(400);

                            bank.addMoney(400);

                            cout << "Player " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 34) {


                            cout << "\nI said it before. Greed is good. You gain $500.\n" << endl;

                            players[i].addMoney(500);

                            bank.loseMoney(500);

                            cout << "Player " << i + 1 << " has $" << players[i].getMoney () << ".\n" << endl; 


                    }

                    if (spaceIndex == 6) {

                        cout << "Greed is good! Go to GO!" << endl;

                        // spaces pointer[spaceIndex] points to/calls gotoaction executeaction 
                        (spacesptr1 + spaceIndex)->callExecuteAction2(i, players, numRolled);
  
                    }

                    // spaces array pointer for other action 
                    Space* spacesptr2 = gameBoard.getSpaces();


                    if (spaceIndex == 10 || spaceIndex == 20 || spaceIndex == 30) {

                        cout << "\nYou're making progress! Go forward 10!" << endl;

                        // spaces pointer[spaceIndex] points to/calls moveaction executeaction 
                        (spacesptr2 + spaceIndex)->callExecuteAction1(i, players, numRolled);
  
                    }

                    // spaces array pointer for igcard actions 
                    Space* igcardptr = gameBoard.getSpaces ();

                    if (spaceIndex == 3 || spaceIndex == 22) {

                        cout << "\nYou draw an Intervening Government Card." << endl;
                        cout << "Dealing with these bastards is a fact of life,";
                        cout << "but there are some battles we can't win." << endl;

                            if (igcounter == 0) {

                                // spaces pointer[spaceINdex] points to/calls moveaction
                                (igcardptr + spaceIndex)->callMoveActionIG1(i, players, numRolled);
                                igcounter++;

                            }

                            else if (igcounter == 1) {

                                // spaces pointer[spaceindex] points to/calls moneyaction
                                (igcardptr + spaceIndex)->callMoneyActionIG2(i, players, &bank);
                                igcounter = 0;

                            }



                    }

                    // spaces array pointer to lcard actions 
                    Space* lcardptr = gameBoard.getSpaces ();

                    if (spaceIndex == 17 || spaceIndex == 36) {

                        cout << "\nYou draw a Life Card." << endl;
                        cout << "Some things are out of our control and we just have to deal with life." << endl;

                        if (lcounter == 0) {

                            //spaces pointer[spaceindex] points to/calls moveaction
                            (lcardptr + spaceIndex)->callMoveActionL1(i, players, numRolled);
                            lcounter++;

                        }

                        else if (lcounter == 1) {

                            //spaces pointerp[spaceindex] points to/calls moneyaction 
                            (lcardptr + spaceIndex)->callMoneyActionL2(i, players, &bank);
                            lcounter = 0;

                        }


                    }

            // determine player's position on space index and determines if space is unowned 
            if ( spaceIndex == 1 && propertyChosen[0] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                // loops if input is invalid 
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    // allows player to own space if have enough money 
                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 210) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[0] = true;
                    players[i].loseMoney(210);
                    bank.addMoney(210);
                    t1 = &players[i];
                    loop = false;

                    }

                    // breaks loop if player does not have enough money for space purchase 
                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 210) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }

            
                }


            }

            // if space is owned by someone else, then the player on that space must pay the owner 
            else if ( spaceIndex == 1 && propertyChosen[0] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(210);
                        t1->addMoney(210);

            }


            if ( spaceIndex == 2 && propertyChosen[1] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 220) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[1] = true;
                    players[i].loseMoney(220);
                    bank.addMoney(220);
                    t2 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 220) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }


            
                }


            }

            else if ( spaceIndex == 2 && propertyChosen[1] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(220);
                        t2->addMoney(220);

            }

            if ( spaceIndex == 4 && propertyChosen[2] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 240) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[2] = true;
                    players[i].loseMoney(240);
                    bank.addMoney(240);
                    t3 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 240) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 4 && propertyChosen[2] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(240);
                        t3->addMoney(240);

            }

            if ( spaceIndex == 5 && propertyChosen[3] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 250) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[3] = true;
                    players[i].loseMoney(250);
                    bank.addMoney(250);
                    t4 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 250) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }

                
            
                }


            }

            else if ( spaceIndex == 5 && propertyChosen[3] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(250);
                        t4->addMoney(250);

            }


            if ( spaceIndex == 7 && propertyChosen[4] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 270) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[4] = true;
                    players[i].loseMoney(270);
                    bank.addMoney(270);
                    t5 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 270) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 7 && propertyChosen[4] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(270);
                        t5->addMoney(270);

            }

            if ( spaceIndex == 9 && propertyChosen[5] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 290) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[5] = true;
                    players[i].loseMoney(290);
                    bank.addMoney(290);
                    t6 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 290) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 9 && propertyChosen[5] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(290);
                        t6->addMoney(290);

            }

            if ( spaceIndex == 11 && propertyChosen[6] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 310) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[6] = true;
                    players[i].loseMoney(310);
                    bank.addMoney(310);
                    t7 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 310) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 11 && propertyChosen[6] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(310);
                        t7->addMoney(310);

            }

            if ( spaceIndex == 12 && propertyChosen[7] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 320) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[7] = true;
                    players[i].loseMoney(320);
                    bank.addMoney(320);
                    t8 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 320) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 12 && propertyChosen[7] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(320);
                        t8->addMoney(320);

            }

            if ( spaceIndex == 13 && propertyChosen[8] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 330) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[8] = true;
                    players[i].loseMoney(330);
                    bank.addMoney(330);
                    t9 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 330) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 13 && propertyChosen[8] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(330);
                        t9->addMoney(330);

            }

            if ( spaceIndex == 15 && propertyChosen[9] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 350) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[9] = true;
                    players[i].loseMoney(350);
                    bank.addMoney(350);
                    t10 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 350) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 15 && propertyChosen[9] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(350);
                        t10->addMoney(350);

            }

            if ( spaceIndex == 16 && propertyChosen[10] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 360) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[10] = true;
                    players[i].loseMoney(360);
                    bank.addMoney(360);
                    t11 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 360) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 16 && propertyChosen[10] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(360);
                        t11->addMoney(360);

            }

            if ( spaceIndex == 18 && propertyChosen[11] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 380) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[11] = true;
                    players[i].loseMoney(380);
                    bank.addMoney(380);
                    t12 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 380) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 18 && propertyChosen[11] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(380);
                        t12->addMoney(380);

            }

            if ( spaceIndex == 19 && propertyChosen[12] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 390) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[12] = true;
                    players[i].loseMoney(390);
                    bank.addMoney(390);
                    t13 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 390) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 19 && propertyChosen[12] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(390);
                        t13->addMoney(390);

            }

            if ( spaceIndex == 21 && propertyChosen[13] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 410) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[13] = true;
                    players[i].loseMoney(410);
                    bank.addMoney(410);
                    t14 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 410) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 21 && propertyChosen[13] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(410);
                        t14->addMoney(410);

            }

            if ( spaceIndex == 23 && propertyChosen[14] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 430) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[14] = true;
                    players[i].loseMoney(430);
                    bank.addMoney(430);
                    t15 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 430) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 23 && propertyChosen[14] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(430);
                        t15->addMoney(430);

            }

            if ( spaceIndex == 25 && propertyChosen[15] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 450) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[15] = true;
                    players[i].loseMoney(450);
                    bank.addMoney(450);
                    t16 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 450) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 25 && propertyChosen[15] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(450);
                        t16->addMoney(450);

            }

            if ( spaceIndex == 26 && propertyChosen[16] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 460) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[16] = true;
                    players[i].loseMoney(460);
                    bank.addMoney(460);
                    t17 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 460) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 26 && propertyChosen[16] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(460);
                        t17->addMoney(460);

            }

            if ( spaceIndex == 27 && propertyChosen[17] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 470) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[17] = true;
                    players[i].loseMoney(470);
                    bank.addMoney(470);
                    t18 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 470) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 27 && propertyChosen[17] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(470);
                        t18->addMoney(470);

            }

            if ( spaceIndex == 31 && propertyChosen[18] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 510) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[18] = true;
                    players[i].loseMoney(510);
                    bank.addMoney(510);
                    t19 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 510) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 31 && propertyChosen[18] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(510);
                        t19->addMoney(510);

            }

            if ( spaceIndex == 32 && propertyChosen[19] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 520) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[19] = true;
                    players[i].loseMoney(520);
                    bank.addMoney(520);
                    t20 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 520) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 32 && propertyChosen[19] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(520);
                        t20->addMoney(520);

            }

            if ( spaceIndex == 33 && propertyChosen[20] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 530) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[20] = true;
                    players[i].loseMoney(530);
                    bank.addMoney(530);
                    t21 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 530) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 33 && propertyChosen[20] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(530);
                        t21->addMoney(530);

            }

            if ( spaceIndex == 35 && propertyChosen[21] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 550) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[21] = true;
                    players[i].loseMoney(550);
                    bank.addMoney(550);
                    t22 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 550) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 35 && propertyChosen[21] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(550);
                        t22->addMoney(550);

            }

            if ( spaceIndex == 37 && propertyChosen[22] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 570) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[22] = true;
                    players[i].loseMoney(570);
                    bank.addMoney(570);
                    t23 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 570) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 37 && propertyChosen[22] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(570);
                        t23->addMoney(570);

            }

            if ( spaceIndex == 38 && propertyChosen[23] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 580) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[23] = true;
                    players[i].loseMoney(580);
                    bank.addMoney(580);
                    t24 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 580) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 38 && propertyChosen[23] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(580);
                        t24->addMoney(580);

            }

            if ( spaceIndex == 39 && propertyChosen[24] == false) {
                
                cout << "Would you like to buy into this concept?" << endl; 
                cout << "Y or y for yes" << endl;
                cout << "N or n for no" << endl; 

                bool loop = true;
                char entry;
            
                while (loop) {  

                    cin >> entry;
                            
                    if (cin.fail()) {
                
                        cout << "Error! Please try again!" << endl;
                        cin.clear ();
                        cin.ignore(1000, '\n');
                
                    }
                
                    if ((entry != 'y' && entry != 'Y') && (entry != 'n' && entry != 'N')) {
                
                        cout << "\nWrong key. Try again" << endl;
                
                    }
                
                    if (entry == 'N' || entry == 'n') {
                
                        loop = false;
                    }

                    if ((entry == 'y' || entry == 'Y') && players[i].getMoney () > 590) {

                    cout << "Congratulations! This is now part of your ideology!" << endl;
                    propertyChosen[24] = true;
                    players[i].loseMoney(590);
                    bank.addMoney(590);
                    t25 = &players[i];
                    loop = false;

                    }

                    else if ((entry == 'y' || entry == 'Y') && players[i].getMoney () < 590) {

                    cout << "Sorry, you don't have enough money to buy into this concept." << endl;
                    loop = false;
                    
                    }
            
                }


            }

            else if ( spaceIndex == 39 && propertyChosen[24] == true) {
            
                        cout << "This is already part of somebody else's ideology. Be original." << endl;
                        cout << "Pay up for being unoriginal." << endl; 

                        players[i].loseMoney(590);
                        t25->addMoney(590);

            }


                    // ends game if player has <= 0 money
                    if (players[i].getMoney () <= 0) {

                        cout << "\nWell, it looks like one of you lost." << endl;
                        cout << "There's no point in continuing this game because now one of you is left out." << endl;
                        cout << "Greed is good, but leave no man behind. This game is over.\n" << endl; 

                        exit (0);


                    }

                    // ends game if player has all the money in the bank
                    if (players[i].getMoney () == 1000000000) {

                        cout << "\nCongratulations Player " << i + 1 << " . You win." << endl;
                        cout << "You only looked out for yourself and allowed others to drown in our glorious capitalistic free market system." << endl;
                        cout << "There is now no reason for us to converse. Good bye." << endl;

                        exit(0);

                    }
            

                    gameBoard.printBoard();

    				//players[i].
    			}	

            }
        

	//board.refreshSpaces ();

}

void choosePlayer() {

    char answer;

    cout << "\nWelcome to Ron Swanson's Free Market Capitalism Game: Ideology Edition." << endl;
    cout << "The purpose of the game is to invest in everything you can." << endl;
    cout << "Only one player may invest in one concept as a lifetime investment." << endl;
    cout << "The concepts may not be tangible, but this is really more of an idealistic game." << endl;
    cout << "You need to stick by your ideals. Otherwise, you lack integrity." << endl;
    cout << "And lacking integrity makes you a communist." << endl;
    cout << "\nPlease enter the number of players: ";

    bool loop = true;

    //prompt user over and over again until appropriate input given
    
    while (loop) {   

        cin >> numPlayers;
        
        if (cin.fail()) {

        cout << "Error. Try again." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        }
        
        if (numPlayers > 4 || numPlayers < 2) {
        
            cout << "Invalid number! Please try again!" << endl;
            
        }
        
        if (numPlayers <= 4 && numPlayers >= 2) {
        
            loop = false;
        
        }
    }
    
    // All users to choose unique pieces that cannot be used twice
    for (int i = 0; i < numPlayers; i++) {
    

        cout << "Please choose which character you would like to play as: " << endl;
        cout << "For Ron Swanson press r" << endl;
        cout << "For Leslie Knope press l" << endl;
        cout << "For Tom Haverford press t" << endl;
        cout << "For April Ludgate press a" << endl;
        cout << "For Andy Dwyer press d" << endl;
        cout << "For Jerry Gergich press j" << endl;
        cout << "For Anne Perkins press p" << endl;
        cout << "For Chris Traeger press c" << endl;
        cout << "For Donna Meagle press m" << endl;
        cout << "For Ben Wyatt press b" << endl;

        bool cycle = true;

    // after entering answer, if input is appropriate
    // then the user's piece will be set and 
    // disallow other users from selecting that piece
        while (cycle) {

            cin >> answer;

            if (cin.fail()) {

                cout << "Error. Please try again." << endl;
                cin.clear ();
                cin.ignore(1000, '\n');
            }

            if ((answer == 'r' || answer == 'R') && optionsChosen[0] == false) {

                players[i].setPiece(playerOptions[0]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[0] = true;
                
    
            }
            
            else if ((answer == 'r' || answer == 'R') && optionsChosen[0] == true){
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'l' || answer == 'L') && optionsChosen[1] == false) {

                players[i].setPiece(playerOptions[1]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[1] = true;
            }
            
            else if ((answer == 'l' || answer == 'L') && optionsChosen[1] == true ){
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 't' || answer == 'T') && optionsChosen[2] == false) {
                players[i].setPiece(playerOptions[2]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[2] = true;

            }
            
            else if ((answer == 't' || answer == 'T' ) && optionsChosen[2] == true ) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'a' || answer == 'A' ) && optionsChosen[3] == false) {
                players[i].setPiece(playerOptions[3]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[3] = true;

            }
            
            else if ((answer == 'a' || answer == 'A' ) && optionsChosen[3] == true ) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'd' || answer == 'D') && optionsChosen[4] == false) {
                players[i].setPiece(playerOptions[4]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[4] = true;

            }
            
            else if ((answer == 'd' || answer == 'D' )&& optionsChosen[4] == true) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'j' || answer == 'J') && optionsChosen[5] == false) {
                players[i].setPiece(playerOptions[5]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[5] = true;

            }
            
            else if ((answer == 'j' || answer == 'J') && optionsChosen[5] == true ) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'p' || answer == 'P') && optionsChosen[6] == false) {
                players[i].setPiece(playerOptions[6]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[6] = true;

            }
            
            else if ((answer == 'p' || answer == 'P') && optionsChosen[6] == true ) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'c' || answer == 'C') && optionsChosen[7] == false) {
                players[i].setPiece(playerOptions[7]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[7] = true;

            }
            
            else if ((answer == 'c' || answer == 'C') && optionsChosen[7] == true) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if ((answer == 'm' || answer == 'M') && optionsChosen[8] == false) {
                players[i].setPiece(playerOptions[8]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[8] = true;
            }
        
            else if ((answer == 'm' || answer == 'M') && optionsChosen[8] == true) {
        
            cout << "this option has already been chosen. Try again." << endl;
        
            }

            if ((answer == 'b' || answer == 'B') && optionsChosen[9] == false) {
                players[i].setPiece(playerOptions[9]);
               // players[i].setPiece(playerOptions[0]);
                cycle = false;
                optionsChosen[9] = true;


            }
            
            else if ((answer == 'b' || answer == 'B') && optionsChosen[9] == true ) {
            
                cout << "This option has already been chosen. Try again." << endl;
            
            }

            if (answer != 'r' && answer != 'R' && answer != 'l' && answer != 'L'
                    && answer != 't' && answer != 'T' && answer != 'a' && answer != 'A'
                    && answer != 'd' && answer != 'D' && answer != 'j' && answer != 'J'
                    && answer != 'p' && answer != 'P' && answer != 'c' && answer != 'C'
                    && answer != 'm' && answer != 'M' && answer != 'b' && answer != 'B') {

                cout << "That is not an option! Please try again!" << endl;

            }


        }

        cout << endl;
        cout << "Player " << i + 1 << "'s piece is " << players[i].getPiece() << "." << endl;
        cout << endl;
      //  Player currentPlayer(currentPiece);
       // players[i] = currentPlayer;
    }
    
    
   // return numPlayers;
}
