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

    bool triggerEvent(Object*);
};


#endif // ENEMY_H_INCLUDED
