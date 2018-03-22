//
// Created on: 13/mar/2018
//  Author: bertini
//

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int strength, bool magic);
    // TODO implement constructor with two arguments: strength and magic, with a default value of false

    int use(); // FIXME
    int getStrength() const;

    void setStrength(int strength);

    bool isMagic() const;

    void setMagic(bool magic);
    // TODO implement getter/setter for attributes

protected:
    int strength;
    bool magic;
};

#endif //WEAPON_H
