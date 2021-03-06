#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"
#include "Item.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using string = std::string;

class GameCharacter : public Object {
protected:
    int HP,maxHP;
    int attack, defense;
    int money;
    std::vector<Item> objects;
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
    int getObjectsSize() { return (int)objects.size(); }
    std::vector<Item> getItem() { return objects; }
    void setHP(int aHP) { HP = aHP; }
    void setmaxHP(int amaxHP) { maxHP = amaxHP; }
    void setMoney(int amoney) { money = amoney; }
    void setAttack(int anAttack) { attack = anAttack; }
    void setDefense(int aDefense) { defense = aDefense; }

    bool isDead() { return HP <= 0; }
    int takeDamage(int AnAttack);
    void putItem (Item obtain);
    void obtainItem (Item obtain) { objects.push_back(obtain);} 
    void removeItem (Item discard);

    virtual bool triggerEvent(GameCharacter* player) = 0;
};
#endif // GAMECHARACTER_H_INCLUDED
