#include "Room.h"
using namespace std;

Room::Room():roomType(0) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
}

Room::Room(int aRoomType):roomType(aRoomType) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
}
