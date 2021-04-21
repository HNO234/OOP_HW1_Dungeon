#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using string = std::string;

class Object {
    private:
        string name;
        string tag;
    public:
        Object();
        Object(string,string);

        virtual bool triggerEvent(Object*) = 0;

        void setName(string);
        void setTag(string);
        string getName();
        string getTag();
};

#endif // OBJECT_H_INCLUDED
