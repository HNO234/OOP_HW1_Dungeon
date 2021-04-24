#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using string = std::string;
using vector = std::vector;

class NPC: public GameCharacter {
private:
    string script;
public:
    NPC();
    NPC(string aScript);

    /* Setter & Getter */
    void setScript(string aScript) { script = aScript; }
    string getScript() { return script; }

    bool triggerEvent(Object*);
};


#endif // NPC_H_INCLUDED
