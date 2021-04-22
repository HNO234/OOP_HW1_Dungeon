#include "Object.h"

Object::Object():
    name("Not defined"),tag("Not tagged") {}

Object::Object(string aName, string aTag):
    name(aName),tag(aTag) {}

virtual void Object::triggerEvent(Object* player) = 0;

void Object::setName(string aName) {
    name = aName;
}

void Object::setTag(string aTag) {
    tag = aTag;
}

string Object::getName() {
    return name;
}

string Object::getTag() {
    return tag;
}
