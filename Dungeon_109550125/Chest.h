#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include <string>
#include <random>
#include <chrono>
#include <cctype>
#include "GameCharacter.h"
#include "Player.h"

using string = std::string;

class Chest: public GameCharacter {
private:
    string script;
public:
    Chest();
    Chest(string aName, string aScript);

    /* Setter & Getter */
    void setScript(string aScript) { script = aScript; }
    string getScript() { return script; }

    bool triggerEvent(GameCharacter* player);
};


#endif // CHEST_H_INCLUDED
