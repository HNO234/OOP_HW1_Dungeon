#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon() {
    player = Player();
    rooms = nullptr;
}

void Dungeon::createPlayer() {
    cout << "\e[0;36mEnter your name: \e[0m";
    string playerName; cin >> playerName;
    player = Player(playerName, 25, 0, 50);
    player.setCurrentRoom(&rooms[0][0]);
}

void Dungeon::linkingRooms() {
    rooms = new pointerofRoom[4];
    for (int i=0;i<4;i++) rooms[i] = new Room[3];

    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++) {
            rooms[i][j] = Room();
        }

    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++) {
            rooms[i][j].setIndex(i*3+j);
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
        Monster* boss = new Monster("Boss",1000,50,100,200000);
        rooms[3][2].setGameCharacter(boss);
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
            Monster* slime = new Monster("Slime",10,5,0,100);
            rooms[X][Y].setGameCharacter(slime);
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
            Chest* chest = new Chest("Chests","Which chest would you like to open?");
            rooms[X][Y].setGameCharacter(chest);

            chest->putItem(Item("Sword 1 (Attack +50)",0,50,0,0));
            chest->putItem(Item("Snake (Attack -10)",0,-10,0,0));
            chest->putItem(Item("Money",0,0,0,-(rng()%500 + 100) ));
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
            NPC* npc = new NPC("Shop","What would like to buy?");
            rooms[X][Y].setGameCharacter(npc);


            npc->putItem(Item("Sword 1 (Attack +50, 50 dollars)",0,50,0,50));
            npc->putItem(Item("Sword 2 (Attack +200, 150 dollars)",0,200,0,150));
            npc->putItem(Item("Shield (Defense +50, 50 dollars)",0,0,50,50));
            npc->putItem(Item("Fruit 1 (HP +10, 5 dollars)",10,0,0,5));
            npc->putItem(Item("Fruit 2 (HP becomes full, 100 dollars)",1000000,0,0,100));
        }
    }
}

bool Dungeon::checkGameLogic() {
    if (player.getHP() <= 0) {
        cout<< "\e[0;31mYou lose. :(\n\e[0m";
        return false;
    }
    if (rooms[3][2].getResident()->getHP() <= 0) {
        cout<< "\e[0;32mYou win. :D\n\e[0m";
        return false;
    }
    return true;
}

void Dungeon::initGame() {
    string script = "\e[0;36mWould you like to load previous data?\n\e[0mA: Yes.\nB: No. Start a new game.\n";

    while (true) {
        cout<<script;
        char action; cin >> action;
        cout<<'\n';
        if (cin.fail()) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }
        bool valid = true;
        switch (action) {
            case 'A':
            case 'a':
                {
                    linkingRooms();
                    Record record;
                    valid = record.load(rooms,player);
                }
                break;
            case 'B':
            case 'b':
                {
                    createMap();
                    createPlayer();
                }
                break;
            default: {
                cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                valid = false;
            } break;
        }
        if (valid) break;
    }
}

void Dungeon::handleMovement() {
    #define currentRoom player.getCurrentRoom()
    string script = "\e[0;36mWhere do you want to go?\n\e[0m";
    if (currentRoom -> getupRoom()) script += "A: Go up\n";
    if (currentRoom -> getdownRoom()) script += "B: Go down\n";
    if (currentRoom -> getleftRoom()) script += "C: Go left\n";
    if (currentRoom -> getrightRoom()) script += "D: Go right\n";

    while (true) {
        cout<<script;
        char action; cin >> action;
        cout<<'\n';
        if (cin.fail()) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }
        bool valid = true;
        switch (action) {
            case 'A':
            case 'a':
                if (!currentRoom->getupRoom()) {
                    cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getupRoom());
                }
                break;
            case 'B':
            case 'b':
                if (!currentRoom->getdownRoom()) {
                    cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getdownRoom());
                }
                break;
            case 'C':
            case 'c':
                if (!currentRoom->getleftRoom()) {
                    cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getleftRoom());
                }
                break;
            case 'D':
            case 'd':
                if (!currentRoom->getrightRoom()) {
                    cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                    valid = false;
                }
                else {
                    player.setPreviousRoom(player.getCurrentRoom());
                    player.setCurrentRoom(player.getCurrentRoom()->getrightRoom());
                }
                break;
            default: {
                cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                valid = false;
            } break;
        }
        if (valid) break;
    }
}

void Dungeon::chooseAction() {
    #define currentRoom player.getCurrentRoom()
    string script = "\e[0;36mSelect your action:\e[0m\nA: Move\nB: Check status\n";
    switch (currentRoom->getRoomType()) {
        case 0:
            script += "D: Save to File\n";
            break;
        case 1:
            if (currentRoom->getResident()->getObjectsSize())
                script += "C: Open a chest\n";
            script += "D: Save to File\n";
            break;
        case 2:
            if (currentRoom->getResident()->getHP() > 0)
                script += "C: Fight with " + currentRoom->getResident()->getName() + "\n";
            script += "D: Save to File\n";
            break;
        case 3:
            script += "C: Talk to " + currentRoom->getResident()->getName() + "\nD: Save to File\n";
            break;
    }

    while (true) {
        cout<<script;
        char action; cin >> action;
        cout<<"\n";
        if (cin.fail()) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
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
                    cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                    valid = false;
                }
                else currentRoom->getResident()->triggerEvent(&player);
                break;
            case 'D':
            case 'd':
                {
                    Record record;
                    record.record(rooms,player);
                }
                break;
            default: {
                cout<<"\e[0;31mInvalid option.\n\n\e[0m";
                valid = false;
            } break;
        }

        if (valid) break;
    }

}

void Dungeon::runDungeon() {
    initGame();
    cout<<"\e[0;32mWelcome back to the Dungeon!\n\e[0m";
    while (true) {
        chooseAction();
        if (!checkGameLogic()) break;
    }
}
