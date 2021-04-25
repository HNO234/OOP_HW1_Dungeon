#include "Chest.h"
using namespace std;

Chest::Chest(): GameCharacter(),script("Not defined") {}

Chest::Chest(string aName, string aScript):
    GameCharacter(aName,"NPC",100,100,100,100,0),script(aScript) {}

bool Chest::triggerEvent(Object* player) {
        return true;
}
