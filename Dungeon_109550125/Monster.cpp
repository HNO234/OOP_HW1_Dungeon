#include "Monster.h"
using namespace std;

Monster::Monster(): GameCharacter() {}

Monster::Monster(string aName,int amaxHP,int anAttack,int aDefense, int aMoney):
    GameCharacter(aName, "Monster", amaxHP, amaxHP, anAttack, aDefense, aMoney) {}

Monster::Monster(string aName,int aHP, int amaxHP,int anAttack,int aDefense, int aMoney):
        GameCharacter(aName, "Monster", aHP, amaxHP, anAttack, aDefense, aMoney) {}

bool Monster::triggerEvent(GameCharacter* player) {
    while (getHP() > 0 && player->getHP() > 0) {
        cout<<"Choose your action:\nA: Attack!\nB: Retreat!\n";

        char option; cin >> option;
        if (cin.fail() || !isalpha(option)) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }
        option = tolower(option);
        if (option - 'a' >= 2) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }

        if (option == 'a') {
            cout<<"Your attack does "<< takeDamage(player->getAttack()) << " damage.\n";
            if (getHP() <= 0) {
                cout<< "You beat " << getName() <<"!\n";
                cout<< "You now have " << player->getHP() <<"HP.\n";
            }
            else {
                cout<<getName()<<"'s attack does "<< player->takeDamage(getAttack()) <<" damage.\n";
                if (player->getHP() > 0) {
                    cout<< "You now have " << player->getHP() <<"HP.\n";
                }
            }
        }
        else {
            Player* pplayer = dynamic_cast<Player*>(player);
            pplayer->Retreat();
            break;
        }
    }
    return true;
}
