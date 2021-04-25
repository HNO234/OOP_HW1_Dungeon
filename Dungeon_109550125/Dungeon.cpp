#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon() {
    player = Player();
    rooms = nullptr;
}

void Dungeon::createPlayer() {
    cout << "Enter your name: ";
    string playerName; cin >> playerName;
    player = Player(playerName, 25, 0, 50);
    player.setCurrentRoom(&rooms[0][0]);
}

void Dungeon::linkingRooms() {
    rooms = new pointerofRoom[4];
    for (int i=0;i<4;i++) rooms[i] = new Room[3];

    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++) {
            if (i-1>=0) rooms[i][j].setupRoom(&rooms[i-1][j]);
            if (i+1<4) rooms[i][j].setdownRoom(&rooms[i+1][j]);
            if (j-1>=0) rooms[i][j].setleftRoom(&rooms[i][j-1]);
            if (j+1<3) rooms[i][j].setrightRoom(&rooms[i][j+1]);
        }
}

void Dungeon::createMap() {
    linkingRooms();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    //Create Boss
    {
        rooms[3][2].setRoomType(2);
        Monster boss = Monster("Boss",1000,50,100,200000);
        rooms[3][2].setGameCharacter(&boss);
    }
    //Create Slime
    {
        int slimeCnt=0;
        while (slimeCnt<2) {
            int X = rng() % 4, Y = rng() % 3;
            if ((X==0 && Y==0) || rooms[X][Y].getRoomType() != 0)
                continue;

            slimeCnt++;
            rooms[X][Y].setRoomType(2);
            Monster slime = Monster("Slime",10,5,0,100);
            rooms[X][Y].setGameCharacter(&slime);
        }
    }
    //Create Room of chest
    {
        int chestCnt=0;
        while (chestCnt<2) {
            int X = rng() % 4, Y = rng() % 3;
            if ((X==0 && Y==0) || rooms[X][Y].getRoomType() != 0)
                continue;

            chestCnt++;
            rooms[X][Y].setRoomType(1);
            Chest chest = Chest("Chests","Which chest would you like to open?");
            rooms[X][Y].setGameCharacter(&chest);

            chest.putItem(Item("Sword 1",0,50,0,0));
            chest.putItem(Item("Snake",0,-10,0,0));
            chest.putItem(Item("Money",0,0,0,-(rng()%500 + 100) ));
        }
    }
    //Create Room of NPC
    {
        int NPCCnt=0;
        while (NPCCnt<1) {
            int X = rng() % 4, Y = rng() % 3;
            if ((X==0 && Y==0) || rooms[X][Y].getRoomType() != 0)
                continue;

            NPCCnt++;
            rooms[X][Y].setRoomType(3);
            NPC npc = NPC("Shop","What would like to buy?");
            rooms[X][Y].setGameCharacter(&npc);


            npc.putItem(Item("Sword 1 (Attack +50, 50 dollars)",0,50,0,50));
            npc.putItem(Item("Sword 2 (Attack +200, 150 dollars)",0,200,0,150));
            npc.putItem(Item("Shield (Defense +50, 50 dollars)",0,0,50,50));
            npc.putItem(Item("Fruit 1 (HP +10, 5 dollars)",10,0,0,5));
            npc.putItem(Item("Fruit 2 (HP becomes full, 100 dollars)",1000000,0,0,100));
        }
    }
}

bool Dungeon::checkGameLogic() {
    if (player.getHP() <= 0) {
        cout<< "You lose. :(\n";
        return false;
    }
    if (rooms[3][2].getResident()->isDead()) {
        cout<< "You win. :D\n";
        return false;
    }
    return true;
}

void Dungeon::initGame() {
    createMap();
    createPlayer();
}

void Dungeon::handleMovement() {
    #define currentRoom player.getCurrentRoom()
    string script = "Where do you want to go?\n";
    if (currentRoom -> getupRoom()) script += "A: Go up\n";
    if (currentRoom -> getdownRoom()) script += "B: Go down\n";
    if (currentRoom -> getleftRoom()) script += "C: Go left\n";
    if (currentRoom -> getrightRoom()) script += "D: Go right\n";

    while (true) {
        cout<<script;
        char action; cin >> action;
        if (cin.fail()) {
            cout<<"Invalid option.\n\n";
            continue;
        }
        bool valid = true;
        switch (action) {
            case 'A':
            case 'a':
                if (!currentRoom->getleftRoom()) {
                    cout<<"Invalid option.\n\n";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getupRoom());
                }
                break;
            case 'B':
            case 'b':
                if (!currentRoom->getrightRoom()) {
                    cout<<"Invalid option.\n\n";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getdownRoom());
                }
                break;
            case 'C':
            case 'c':
                if (!currentRoom->getupRoom()) {
                    cout<<"Invalid option.\n\n";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getleftRoom());
                }
                break;
            case 'D':
            case 'd':
                if (!currentRoom->getdownRoom()) {
                    cout<<"Invalid option.\n\n";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getrightRoom());
                }
                break;
            default: {
                cout<<"Invalid option.\n\n";
                valid = false;
            } break;
        }
        if (valid) break;
    }
}

void Dungeon::chooseAction() {
    #define currentRoom player.getCurrentRoom()
    string script = "Select your action:\nA: Move\nB: Check status\n";
    switch (currentRoom->getRoomType()) {
        case 0:
            script += "D: Save to File";
            break;
        case 1:
            script += "C: Open a chest\nD: Save to File";
            break;
        case 2:
            script += "C: Fight with" + currentRoom->getResident()->getName() + "\nD: Save to File";
            break;
        case 3:
            script += "C: Talk to" + currentRoom->getResident()->getName() + "\nD: Save to File";
            break;
    }

    while (true) {
        cout<<script;
        char action; cin >> action;
        if (cin.fail()) {
            cout<<"Invalid option.\n\n";
            continue;
        }
        bool valid = true;
        switch (action) {
            case 'A':
            case 'a':
                handleMovement();
                break;
            case 'B':
            case 'b':
                player.showStatus();
                break;
            case 'C':
            case 'c':
                if (currentRoom->getRoomType() == 0) {
                    cout<<"Invalid option.\n\n";
                    valid = false;
                }
                else currentRoom->getResident()->triggerEvent(&player);
                break;
            default: {
                cout<<"Invalid option.\n\n";
                valid = false;
            } break;
        }
        if (valid) break;
    }
}

void Dungeon::runDungeon() {
    initGame();
    cout<<"Welcome back to the Dungeon!\n";
    while (true) {
        chooseAction();
        if (!checkGameLogic()) break;
    }
}
