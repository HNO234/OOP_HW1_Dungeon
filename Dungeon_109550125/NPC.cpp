#include "NPC.h"
using namespace std;

NPC::NPC(): GameCharacter(),script("Not defined") {}

NPC::NPC(string aName, string aScript):
    GameCharacter(aName,"NPC",100,100,100,100,0),script(aScript) {}

bool NPC::triggerEvent(Object* player) {
    return true;
    /*vector<Item> objects = currentRoom -> getObjects();
    int numObjects = (int)objects.size();

    while (true) {
        cout << script << "\n";
        for (int i=0;i<numObjects;i++) {
            cout<<(char)('A'+i) << ": " << objects[i].getName() <<'\n';
        }

        char option; cin >> option;
        if (cin.fail() || !isalpha(option)) {
            cout<<"Invalid option.\n";
            continue;
        }
        option = tolower(option);
        if (option - 'a' > numObjects) {
            cout<<"Invalid option.\n";
            continue;
        }
        objects[option - 'a'].triggerEvent(player);
        break;
    }
    return true;*/
}
