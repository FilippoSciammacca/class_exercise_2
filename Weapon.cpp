//
// Created on: 13/mar/2018
// Author: bertini
//

#include "Weapon.h"


int Weapon::use() {
    if(magic)
        return strength * 2;
    return strength;
    // TODO return strenght, but if the weapon is magic return a doubled value of strength
}

Weapon::Weapon(int strength = 10, bool magic = false) : strength(strength), magic(magic) {}

int Weapon::getStrength() const {
    return strength;
}

void Weapon::setStrength(int strength) {
    Weapon::strength = strength;
}

bool Weapon::isMagic() const {
    return magic;
}

void Weapon::setMagic(bool magic) {
    Weapon::magic = magic;
}
