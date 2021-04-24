#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameCharacter.h"
#include "Room.h"
#include <string>
#include <vector>
#include <iostream>

using string = std::string;
using vector = std::vector;

class Player : public GameCharacter {
protected:
    vector<Item> inventory;
    Room *previousRoom;
public:
    Player();
    Player(string aName, int anAttack, int aDefense, int aMoney);

    /* Setters & Getters */
    void setPreviousRoom(Room* aPreviousRoom) { previousRoom = aPreviousRoom; }
    Room* getPreviousRoom() { return previousRoom; }

    void putItem (Item obtain);
    void showStatus ();
    bool triggerEvent(Object* player) { return true; }
};

#endif // PLAYER_H_INCLUDED
