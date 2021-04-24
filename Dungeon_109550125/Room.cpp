#include "Room.h"
using namespace std;

Room::Room():roomType(0) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
    objects.clear();
}

Room::Room(int aRoomType):roomType(aRoomType) {
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    resident = nullptr;
    objects.clear();
}

void Room::removeItem(Item item) {
    if (count(objects.begin(),objects.end(),item)) {
        remove(objects.begin(),objects.end(),item);
        objects.pop_back();
    }
}
