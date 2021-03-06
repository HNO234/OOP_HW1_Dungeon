#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <string>
#include "GameCharacter.h"
#include "Player.h"

using string = std::string;

class Monster: public GameCharacter
{
private:
public:
    Monster();
    Monster(string aName,int amaxHP,int anAttack,int aDefense,int aMoney);
    Monster(string aName, int aHP, int amaxHP,int anAttack,int aDefense,int aMoney);

    bool triggerEvent(GameCharacter* player);
};


#endif // ENEMY_H_INCLUDED
