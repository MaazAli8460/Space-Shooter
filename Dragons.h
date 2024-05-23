#ifndef DRAGONS_H
#define DRAGONS_H
#include "Enemy.h"
#pragma once

class Dragons: public Enemy
{
public:
    string type = "Monster";
    bool sp;
    sf::Sprite enemyal;
    sf::Texture enemytex;
    sf::Sprite bb;
    Bomb b;
    Dragons();
    void displayenemy(sf::RenderWindow& window) override;
    void setPosition(float x, float y) override;
    void display_bomb(sf::RenderWindow& window) override;
    int scoreenemy() override;
    Sprite retenemy();
    


};

#endif