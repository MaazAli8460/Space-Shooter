#ifndef GAMMA_H
#define GAMMA_H
#include "Invaders.h"
#include "ArraynotVector.h"
#include "Bomb.h"
#pragma once

class Gamma:public Invaders
{
public:
    Gamma();
    void displayenemy(sf::RenderWindow& window) override;
    void setPosition(float x, float y) override;
    void display_bomb(sf::RenderWindow& window) override;
    int scoreenemy() override;
    Sprite retenemy();

    sf::Sprite enemyal;
    sf::Texture enemytex;
    ArraynotVector alphainvaders;

    sf::Sprite bb;
    Bomb b;


};

#endif