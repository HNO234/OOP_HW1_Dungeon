#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon() {
    player = player();
    rooms.clear();
}



void startGame() {
    createPlayer();
    createMap();
}

void Dungeon::runDungeon() {
    startGame();
}
