#include "Chest.h"
using namespace std;

Chest::Chest(): GameCharacter(),script("Not defined") {}

Chest::Chest(string aName, string aScript):
    GameCharacter(aName,"Chest",100,100,100,100,0),script(aScript) {}

bool Chest::triggerEvent(GameCharacter* player) {
    int numObjects = getObjectsSize();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<int> v(numObjects);
    for (int i=0;i<numObjects;i++) v[i] = i;
    shuffle(v.begin(), v.end(), rng);

    while (true) {
        cout << "\e[0;36m" << script << "\n\e[0m";
        for (int i=0;i<numObjects;i++) {
            cout<<(char)('A'+i) << ": " << "Mystery Chest " << i+1 <<'\n';
        }

        char option; cin >> option;
        if (cin.fail() || !isalpha(option)) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }
        option = tolower(option);
        if (option - 'a' > numObjects + 1) {
            cout<<"\e[0;31mInvalid option.\n\n\e[0m";
            continue;
        }

        player->putItem(objects[v[option - 'a']]);
        cout<<"You got " << objects[v[option - 'a']].getName() <<"!\n";
        removeItem(objects[v[option - 'a']]);
        break;
    }
    return true;
}
