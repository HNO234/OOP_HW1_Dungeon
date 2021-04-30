#include "Monster.h"
using namespace std;

Monster::Monster(): GameCharacter() {}

Monster::Monster(string aName,int amaxHP,int anAttack,int aDefense, int aMoney):
    GameCharacter(aName, "Monster", amaxHP, amaxHP, anAttack, aDefense, aMoney) {}

Monster::Monster(string aName,int aHP, int amaxHP,int anAttack,int aDefense, int aMoney):
        GameCharacter(aName, "Monster", aHP, amaxHP, anAttack, aDefense, aMoney) {}

bool Monster::triggerEvent(GameCharacter* player) {
    while (getHP() > 0 && player->getHP() > 0) {
        cout<<"\e[0;36mChoose your action:\e[0m\nA: Attack!\nB: Retreat!\n";

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
            cout<<"\e[0;36mYour attack does "<< takeDamage(player->getAttack()) << " damage.\n\e[0m";
            if (getHP() <= 0) {
                cout<< "\e[0;32mYou beat " << getName() <<"!\n\e[0m";
                cout<< "\e[0;36mYou now have " << player->getHP() <<"HP.\n\e[0m";
            }
            else {
                cout<<"\e[0;36m"<<getName()<<"'s attack does "<< player->takeDamage(getAttack()) <<" damage.\n\e[0m";
                if (player->getHP() > 0) {
                    cout<< "\e[0;36mYou now have " << player->getHP() <<"HP.\n\e[0m";
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
