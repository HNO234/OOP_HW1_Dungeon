#incldue "Item.h"

Item():
    Object(),HP(0),attack(0),defense(0),price(0) {}

Item::Item(string aName, int aHP, int anAttack,
    int aDefense, int aPrice):
        Object(aName,"Item"), HP(aHP), attack(anAttack),
        defense(aDefense), price(aPrice) {}

bool Item::triggerEvent(Object* player) {
    //...
    return true;
}
