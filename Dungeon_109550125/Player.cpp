#include "Player.h"
using namespace std;

Player::Player():GameCharacter(){
    inventory.clear();
    currentRoom = nullptr;
    previousRoom = nullptr;
}

Player(string aName, int anAttack, int aDefense, int amoney):
    GameCharacter(aName,"Player",100,100,anAttack,aDefense,aMoney) {
        inventory.clear();
        currentRoom = nullptr;
        previousRoom = nullptr;
    }

void Player::putItem (Item obtain) {
    inventory.push_back(obtain);
}
