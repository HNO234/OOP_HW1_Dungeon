#include "Player.h"
using namespace std;

Player::Player():GameCharacter(){
    currentRoom = nullptr;
    previousRoom = nullptr;
}

Player::Player(string aName, int anAttack, int aDefense, int amoney):
    GameCharacter(aName,"Player",100,100,anAttack,aDefense,amoney) {
        currentRoom = nullptr;
        previousRoom = nullptr;
    }

Player::Player(string aName, int aHP, int amaxHP, int anAttack, int aDefense, int amoney):
    GameCharacter(aName,"Player",aHP,amaxHP,anAttack,aDefense,amoney) {
        currentRoom = nullptr;
        previousRoom = nullptr;
    }

void Player::showStatus () {
    cout << "[" << name << "]\n";
    cout << "> Health: " << HP << '/' << maxHP <<'\n';
    cout << "> Attack: " << attack << '\n';
    cout << "> Defense: " << defense << '\n';
    cout << "> Money: " << money << '\n';
    cout << '\n';
}
