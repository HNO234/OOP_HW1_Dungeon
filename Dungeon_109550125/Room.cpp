#include "Room.h"
using namespace std;

Room::Room():roomType(0) {
    resident = nullptr;
    objects.clear();
}

Room::Room(int aRoomType):roomType(aRoomType) {
    resident = nullptr;
    objects.clear();
}
