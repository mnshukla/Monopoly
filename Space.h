#ifndef SPACE_H
#define SPACE_H
#include <string>
#include "Action.h"
#include "Player.h"
#include "Bank.h"
#include "Card.h"
#include "LCard.h"
#include "IGCard.h"

using namespace std;


class Space {

            public:

                Space ();
                Space(string, string, string);
                ~Space ();
                
                void setActionText1 (string);
                void setActionText2 (string);
                void setActionText3 (string);

                string getActionText1 ();
                string getActionText2 ();
                string getActionText3 ();
                
                void setSpaceName (string Name);
                
                void setAction1 (Action*);
                void setAction2 (Action*);

                void setLCardAction1 (LCard*);
                void setLCardAction2 (LCard*);
                void setIGCardAction1 (IGCard*);
                void setIGCardAction2 (IGCard*);
                
                string getSpaceName ();
                
                void callExecuteAction1 (int, Player*, int);
                void callExecuteAction2 (int, Player*, int); 

                void callMoveActionL1 (int, Player*, int);
                void callMoneyActionL2 (int, Player*, Bank*);

                void callMoveActionIG1 (int, Player*, int);
                void callMoneyActionIG2 (int, Player*, Bank*);

            private:

                // this data is considered the property of the class

                string name;
                
                int location;
                
                string actionText1;
                string actionText2;
                string actionText3;
                
                Action* as1; //  Move_Action Spaces;
                Action* as2; // GotoAction Spaces;

                LCard* lc1; // Life Card Move_Action Spaces;
                LCard* lc2; // Life Card Money_Action Spaces;

                IGCard* igc1; // IG Card Move_Action Spaces;
                IGCard* igc2; // IG Card Money_Action Spaces; 

        };


#endif // SPACE_H
