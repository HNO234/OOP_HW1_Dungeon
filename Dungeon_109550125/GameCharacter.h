#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"

using string = std::string;

class Gamecharacter : public Object {
protected:
    int
public:
    Object();
    Object(string aName,string aTag);

    virtual void triggerEvent(Object* player) = 0;

    void setName(string aName);
    void setTag(string aTag);
    string getName();
    string getTag();
};

#endif // GAMECHARACTER_H_INCLUDED
