#include "NPC.h"
using namespace std;

NPC::NPC(): GameCharacter(),script("Not defined") {}

NPC::NPC(string aName, string aScript):
    GameCharacter(aName,"NPC",100,100,100,100,0),script(aScript) {}

bool NPC::triggerEvent(GameCharacter* player) {
    int numObjects = getObjectsSize();

    while (true) {
        cout << "\e[0;36m" << script << "\n\e[0m";
        for (int i=0;i<numObjects;i++) {
            cout<<(char)('A'+i) << ": " << objects[i].getName() <<'\n';
        }
        cout<<(char)('A'+numObjects) << ": " << "Nothing. I'm just finding someone to talk to." <<'\n';

        char option; cin >> option;
        if (cin.fail() || !isalpha(option)) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }
        option = tolower(option);
        if (option - 'a' > numObjects + 1) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }

        if (option - 'a' == numObjects) {
            cout<<"\e[0;32mThank you.\n\n\e[0m";
            break;
        }
        if (player->getMoney() < objects[option - 'a'].getPrice()) {
            cout<<"\e[0;31mYou don't have enough money!\n\n\e[0m";
            continue;
        }

        player->putItem(objects[option - 'a']);
        cout<<"\e[0;32mYou got " << objects[option - 'a'].getName() <<"!\n\e[0m";
        break;
    }
    return true;
}
