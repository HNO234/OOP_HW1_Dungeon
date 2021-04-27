#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameCharacter.h"
#include "Room.h"
#include <string>
#include <vector>
#include <iostream>

using string = std::string;
#define vector std::vector

class Player : public GameCharacter {
protected:
    Room *currentRoom;
    Room *previousRoom;
public:
    Player();
    Player(string aName, int anAttack, int aDefense, int aMoney);
    Player(string aName, int aHP,int amaxHP, int anAttack, int aDefense, int aMoney);

    /* Setters & Getters */
    void setCurrentRoom(Room* aCurrentRoom) { currentRoom = aCurrentRoom; }
    void setPreviousRoom(Room* aPreviousRoom) { previousRoom = aPreviousRoom; }
    Room* getCurrentRoom() { return currentRoom; }
    Room* getPreviousRoom() { return previousRoom; }

    void showStatus ();
    void Retreat() { std::swap(currentRoom,previousRoom); }
    bool triggerEvent(GameCharacter* player) { return true; }
};

#endif // PLAYER_H_INCLUDED
