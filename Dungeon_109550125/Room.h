#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include "GameCharacter.h"
#include <string>
#include <vector>
#include <algorithm>

using string = std::string;

class Room {
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    /* 0: Ordinary Room,
    1: Room of chest
    2: Room of monster
    3: Room of NPC */
    int roomType;
    int index;
    GameCharacter* resident;
public:
    Room();
    Room(int aroomType,int index);

    /* Setters & Getters */
    void setIndex (int anIndex) { index = anIndex; }
    void setRoomType (int aRoomType) { roomType = aRoomType; }
    void setGameCharacter (GameCharacter* aResident) { resident = aResident; }
    void setupRoom (Room* aUpRoom) { upRoom = aUpRoom; }
    void setdownRoom (Room* adownRoom) { downRoom = adownRoom; }
    void setleftRoom (Room* aleftRoom) { leftRoom = aleftRoom; }
    void setrightRoom (Room* arightRoom) { rightRoom = arightRoom; }
    int getRoomType () { return roomType; }
    int getIndex() { return index; }
    GameCharacter* getResident () { return resident; }
    Room* getupRoom () { return upRoom; }
    Room* getdownRoom () { return downRoom; }
    Room* getleftRoom () { return leftRoom; }
    Room* getrightRoom () { return rightRoom; }

};

#endif //ROOM_H_INCLUDED
