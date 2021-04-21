#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED
#include <vector>
#include <Room.h>
#include <Player.h>

class Dungeon {
  private:
    Player player;
    vector<Room> rooms;
  public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which includes several different rooms */
    void createMap();

    /* Deal with player's moving action */
    void handleMovement();

    /* Deal with player's interaction with objects in that room */
    void handleEvent(Object*);

    /* Deal with all game initial setting,
    including create player and create map. */
    void startGame();

    /* Deal with the player's action,
    including showing the action list that player can do in that room
     and dealing with player's input.   */
    void chooseAction();

    /* Check whether the game should end or not.
    Return false if game has benn terminated.*/
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();
}

#endif
