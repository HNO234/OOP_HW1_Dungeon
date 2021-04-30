#include "Record.h"
using namespace std;

void Record::loadRoom(Room** rooms,ifstream& inStream) {
    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++) {
            int roomType;
            inStream >> roomType; rooms[i][j].setRoomType(roomType);


            if (!roomType) continue;

            string name,script;
            int HP,maxHP,attack,defense,money;
            inStream >> name >> HP >> maxHP >> attack >> defense >> money;

            inStream.ignore();
            getline(inStream,script);

            if (roomType == 1) {
                Chest* chest = new Chest(name,script);
                rooms[i][j].setGameCharacter(chest);
            }
            else if (roomType == 2) {
                Monster* monster = new Monster(name,HP,maxHP,attack,defense,money);
                rooms[i][j].setGameCharacter(monster);
            }
            else if (roomType == 3) {
                NPC* npc = new NPC(name,script);
                rooms[i][j].setGameCharacter(npc);
            }

            int size; inStream >> size;
            while (size--) {
                inStream.ignore(); getline(inStream,name);
                inStream >> HP >> attack >> defense >> money;

                rooms[i][j].getResident()->obtainItem(Item(name,HP,attack,defense,money));
            }
        }
}

void Record::loadPlayer(Player &player,Room** rooms,ifstream& inStream){
    string name;
    int HP,maxHP,attack,defense,money;
    inStream>>name>>HP>>maxHP>>attack>>defense>>money;

    player = Player(name,HP,maxHP,attack,defense,money);

    int size; inStream >> size;
    while (size--) {
        inStream.ignore(); getline(inStream,name);
        inStream >> HP >> attack >> defense >> money;

        player.obtainItem(Item(name,HP,attack,defense,money));
    }

    int roomNum;
    inStream >> roomNum;
    player.setCurrentRoom(&rooms[roomNum/3][roomNum%3]);
    inStream >> roomNum;
    if (roomNum != -1) player.setPreviousRoom(&rooms[roomNum/3][roomNum%3]);
}

void Record::recordRoom(Room** rooms,ofstream& outStream) {
    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++) {
            GameCharacter* resident = rooms[i][j].getResident();

            outStream<< rooms[i][j].getRoomType() << '\n';

            if (resident == nullptr) continue;
            outStream<< resident -> getName() <<'\n';
            outStream<< resident -> getHP() << ' ' << resident-> getmaxHP() << ' ' <<resident->getAttack()
                << ' ' << resident->getDefense() << ' '<<resident->getMoney() <<'\n';
            if (rooms[i][j].getRoomType() == 1) {
                Chest* chest = dynamic_cast<Chest*>(resident);
                outStream << chest->getScript() <<'\n';
            }
            else if (rooms[i][j].getRoomType() == 3) {
                NPC* npc = dynamic_cast<NPC*>(resident);
                outStream << npc->getScript() <<'\n';
            }
            else {
                outStream<<'\n';
            }

            outStream<< resident->getObjectsSize() <<'\n';
            for (Item i:resident->getItem()) {
                outStream<< i.getName() <<'\n';
                outStream<< i.getHP() << ' ' << i.getAttack() << ' ' << i.getDefense()
                    << ' ' << i.getPrice() << '\n';
            }
        }
}

void Record::recordPlayer(Player &player,ofstream& outStream) {
    outStream<< player.getName() <<'\n';
    outStream<< player.getHP() << ' ' << player.getmaxHP() << ' ' <<player.getAttack()
        << ' ' << player.getDefense() << ' '<<player.getMoney() <<'\n';

    outStream<< player.getObjectsSize() <<'\n';
    for (Item i:player.getItem()) {
        outStream<< i.getName() <<'\n';
        outStream<< i.getHP() << ' ' << i.getAttack() << ' ' << i.getDefense()
            << ' ' << i.getPrice() << '\n';
    }
    outStream<< player.getCurrentRoom()->getIndex() <<'\n';
    outStream<< (player.getPreviousRoom() ? player.getPreviousRoom()->getIndex() : -1 ) << '\n';
}

void Record::record(Room** rooms, Player &player) {
    ofstream outStream("data");
    if (outStream.fail()) {
        "\e[0;31mRecord fails.\n\n\e[0m";
        return;
    }
    recordRoom(rooms,outStream);
    recordPlayer(player,outStream);
    cout<<"\e[0;32mSaved!\n\e[0m";

    outStream.close();
}

bool Record::load(Room** rooms, Player &player) {

    ifstream inStream("data");
    struct stat info;
    if (stat("data", &info) != 0) {
        cout<<"\e[0;31mLoad data fails.\n\n\e[0m";
        return false;
    }
    loadRoom(rooms,inStream);
    loadPlayer(player,rooms,inStream);

    inStream.close();
    return true;
}
