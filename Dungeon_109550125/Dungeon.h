#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Chest.h"
#include "Room.h"

using namespace std;

class Dungeon {
    using pointerofRoom = Room*;
private:
    Player player;
    pointerofRoom *rooms;
public:
    Dungeon();

    /* Create a new player, and give him/her basic status */
    void createPlayer();

    void linkingRooms();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moving action */
    void handleMovement();

    /* Deal with all game initial setting
    Including create player, create map etc.  */
    void initGame();

    /* Deal with the player's action.
     including showing the action list
     that player can do at that room
    and dealing with player's input   */
    void chooseAction();

    /* Check whether the game should end or not.
    Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();
};


#endif // DUNGEON_H_INCLUDED
