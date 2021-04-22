#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"
#include <string>

using string = std::string;

class GameCharacter : public Object {
protected:
    int HP,maxHP;
    int attack, defense;
    int money;
public:
    GameCharacter();
    GameCharacter(string aName, string aTag, int aHP, int amaxHP,
        int anAttack, int aDefense, int amoney);

    /* Setters & Getters */
    int getHP() { return HP; }
    int getmaxHP() { return maxHP; }
    int getMoney() { return money; }
    int getAttack() { return attack; }
    int getDefense() { return defense; }
    void setHP(int aHP) { HP = aHP; }
    void setmaxHP(int amaxHP) { maxHP = amaxHP; }
    void setMoney(int amoney) { money = amoney; }
    void setAttack(int anAttack) { attack = anAttack; }
    void setDefense(int aDefense) { defense = aDefense; }
};

#endif // GAMECHARACTER_H_INCLUDED
