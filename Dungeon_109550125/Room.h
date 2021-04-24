#ifndef ROOM_H_INCLUDED
#defile ROOM_H_INCLUDED
#include "Item.h"
#include "GameCharacter.h"
#include <string>
#include <vector>

using string = std::string;
using vector = std::vector;

class Room {
private:
    vector<Item> objects;
    /* 0: Ordinary Room,
    1: Room of chest
    2: Room of monster
    3: Room of NPC */
    int roomType;
    GameCharacter* resident;
public:
    Room();
    Room(int aroomType);

    /* Setters & Getters */
    void setRoomType (int aRoomType) { roomType = aRoomType; }
    void setGameCharacter(GameCharacter* aResident) { resident = aResident; }
    int getRoomType () { return roomType; }
    GameCharacter* getResident () { return resident; }


}

#endif //ROOM_H_INCLUDED
