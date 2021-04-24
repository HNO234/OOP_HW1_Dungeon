#include "Chest.h"
using namespace std;

NPC::NPC(): GameCharacter(),script("Not defined") {}

NPC::NPC(string aName, string aScript):
    GameCharacter(aName,"NPC",100,100,100,100,0),script(aScript) {}
