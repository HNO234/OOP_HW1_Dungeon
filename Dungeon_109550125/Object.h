#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <string>

using string = std::string;

class Object {
protected:
    string name;
    string tag;
public:
    Object();
    Object(string aName,string aTag);

    virtual void triggerEvent(Object* player) = 0;

    void setName(string aName);
    void setTag(string aTag);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
