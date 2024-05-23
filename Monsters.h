#ifndef MONSTERS_H
#define MONSTERS_H
#include "Enemy.h"
#pragma once

class Monsters: public Enemy
{
public:
    string type = "Monster";
    Monsters();
    void displayenemy(sf::RenderWindow& window) override;
    void setPosition(float x, float y) override;
    void display_bomb(sf::RenderWindow& window) override;
    int scoreenemy() override;
    Sprite retenemy();
    bool sp;
    sf::Sprite enemyal;
    sf::Texture enemytex;
    sf::Sprite bb;
    Bomb b;


};

#endif