#ifndef ROOM_H_INCLUDED
#defile ROOM_H_INCLUDED
#include "Item.h"
#include "GameCharacter.h"
#include <string>
#include <vector>
#include <algorithm>

using string = std::string;
using vector = std::vector;

class Room {
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
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
    void setGameCharacter (GameCharacter* aResident) { resident = aResident; }
    void setupRoom (Room* aUpRoom) { upRoom = aUpRoom; }
    void setdownRoom (Room* adownRoom) { downRoom = adownRoom; }
    void setleftRoom (Room* aleftRoom) { leftRoom = aleftRoom; }
    void setrightRoom (Room* arightRoom) { rightRoom = arightRoom; }
    int getRoomType () { return roomType; }
    GameCharacter* getResident () { return resident; }
    Room* getupRoom () { return upRoom; }
    Room* getdownRoom () { return downRoom; }
    Room* getleftRoom () { return leftRoom; }
    Room* getrightRoom () { return rightRoom; }

    void putItem(Item item) { objects.push_back(item); }
    void removeItem(Item item);
}

#endif //ROOM_H_INCLUDED
