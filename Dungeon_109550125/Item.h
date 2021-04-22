#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item : public Object {
protected:
    int HP;
    int attack,defense;
    int price;
public:
    Item();
    Item(string aName, int aHP,
        int anAttack, int aDefense, int aPrice);

    /* Setters & Getters */
    int getHP() { return HP; }
    int getAttack() { return attack; }
    int getDefense() { return defense; }
    int getPrice() { return price; }
    void setHP(int aHP) { HP = aHP; }
    void setPrice(int aPrice) { price = aPrice; }
    void setAttack(int anAttack) { attack = anAttack; }
    void setDefense(int aDefense) { defense = aDefense; }

    bool triggerEvent(Object* player);
};

#endif // ITEM_H_INCLUDED
