#include "GameCharacter.h"

GameCharacter::GameCharacter():
    Object(),HP(0),maxHP(0),money(0),attack(0),defense(0) {}

GameCharacter::GameCharacter(string aName, int aHP, int amaxHP,
    int anAttack, int aDefense, int amoney):
        Object(aName,"Undefined Game Character"),HP(aHP),maxHP(amaxHP),
        attack(anAttack),defense(aDefense),money(amoney) {}
