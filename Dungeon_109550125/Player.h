#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameCharacter.h"
#include "Room.h"
#include <string>
#include <vector>

using string = std::string;
using vector = std::vector;

class Player : public GameCharacter {
protected:
    vector<Item> inventory;
    Room *currentRoom, *previousRoom;
public:
    Player();
    Player(string aName, int anAttack, int aDefense, int aMoney);

    /* Setters & Getters */
    void setCurrentRoom(Room* aCurrentRoom) { currentRoom = aCurrentRoom; }
    void setPreviousRoom(Room* aPreviousRoom) { previousRoom = aPreviousRoom; }

    void putItem (Item obtain);
    bool triggerEvent(Object* player) { return true; }
};

#endif // PLAYER_H_INCLUDED
