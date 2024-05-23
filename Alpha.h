#ifndef ALPHA_H
#define ALPHA_H

#include "Invaders.h"
#include "ArraynotVector.h"
#include "Bomb.h"

class Alpha : public Invaders {
public:
    Alpha();
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