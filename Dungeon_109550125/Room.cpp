#include "Room.h"
using namespace std;

Room::Room():roomType(0),index(0) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
}

Room::Room(int aRoomType,int anIndex):roomType(aRoomType),index(anIndex) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
}
