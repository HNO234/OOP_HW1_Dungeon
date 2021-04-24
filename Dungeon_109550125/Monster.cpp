#include "Monster.h"
using namespace std;

Monster::Monster(): GameCharacter() {}

Monster::Monster(string aName,int amaxHP,int anAttack,int aDefense, int aMoney):
    GameCharacter(aName, "Monster", amaxHP, amaxHP, anAttack, aDefense, aMoney) {}
