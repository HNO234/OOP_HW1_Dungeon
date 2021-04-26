#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include <vector>
#include <cctype>
#include "GameCharacter.h"
#include "Player.h"

using string = std::string;
#define vector std::vector

class NPC: public GameCharacter {
private:
    string script;
public:
    NPC();
    NPC(string aName, string aScript);

    /* Setter & Getter */
    void setScript(string aScript) { script = aScript; }
    string getScript() { return script; }

    bool triggerEvent(GameCharacter* player);
};


#endif // NPC_H_INCLUDED
