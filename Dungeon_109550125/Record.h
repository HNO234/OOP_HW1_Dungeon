#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include "Room.h"
#include "Item.h"
#include "Chest.h"
#include "NPC.h"
#include "Monster.h"
#include "Player.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

using std::string;

class Record {
private:
    void loadRoom(Room** rooms,std::ifstream& inStream);
    void loadPlayer(Player &player,Room** rooms, std::ifstream& inStream);
    void recordRoom(Room** rooms,std::ofstream& outStream);
    void recordPlayer(Player &player,std::ofstream& outStream);
public:
    void record(Room** rooms, Player &player);
    bool load(Room** rooms, Player &player);
};

#endif //RECORD_H_INCLUDED
