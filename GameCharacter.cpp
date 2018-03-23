/*
 * Character.cpp
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#include "GameCharacter.h"

#include <ctime>
#include <iostream>

using namespace std;

GameCharacter::GameCharacter(int hp, int a) {
    this->HP = hp;
    this->armor = a;
    setPosX(0);
    setPosY(0);
    setWeapon(nullptr);
    // position and weapon must be set to 0 or null pointer
}

int GameCharacter::getHP() {
    return HP;
}

void GameCharacter::setHP(int hp) {
    this->HP = hp;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
}

void GameCharacter::move(int distance) {
    posX += distance;
    posY += distance;
}

int GameCharacter::getArmor() {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter &enemy) {
    int hit = 1;
    if(weapon)
        hit = weapon->use();
    // if a weapon is available use it and store result in hit

    int damage = 0;
    if(hit > enemy.getArmor()){
        damage = enemy.receiveDamage(hit);
    }
    // TODO if hit > enemy armor value then apply damage and store it in damage variable

    bool success = false;
    if (damage) {
        std::cout << "You hit the enemy for: " << damage << std::endl;
        // TODO print "You hit the enemy !" followed by enemy hit points
        success = true;
    }
    else
        cout << "You miss the hit..." << endl;
    alive(enemy);

    return success;
}

int GameCharacter::receiveDamage(int points) {
    if (armor > 4)
        points /= 3;
    else if (armor > 2)
        points /= 2;
    else if (armor >= 1)
        points -= 2;
    // if armor > 4 then points are divided by 3
    // if armor > 2 then points are divided by 2
    // if armor >= 1 then points are reduced by 2

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}

bool GameCharacter::alive(GameCharacter &enemy) {
    if (enemy.getHP() <= 0){
        cout << "You defeated the monster!" << std::endl;
    }
}