#include "GameCharacter.h"
using namespace std;

GameCharacter::GameCharacter():
    Object(),HP(0),maxHP(0),money(0),attack(0),defense(0) {}

GameCharacter::GameCharacter(string aName, string aTag, int aHP, int amaxHP,
    int anAttack, int aDefense, int amoney):
        Object(aName,aTag),HP(aHP),maxHP(amaxHP),
        attack(anAttack),defense(aDefense),money(amoney) {}

void GameCharacter::putItem(Item item) {
    HP = min(maxHP, HP + item.getHP());
    attack = attack + item.getAttack();
    defense = defense + item.getDefense();
    money = money - item.getPrice();
    objects.push_back(item);
}

void GameCharacter::removeItem(Item item) {
    if (count(objects.begin(),objects.end(),item)) {
        remove(objects.begin(),objects.end(),item);
        objects.pop_back();
    }
}
