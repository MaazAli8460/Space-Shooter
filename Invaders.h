#ifndef INVADERS_H
#define INVADERS_H

#include "Enemy.h"

class Invaders : public Enemy
{
public:
    string type = "Invader";
    virtual void displayenemy(RenderWindow& window) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void display_bomb(RenderWindow& window) = 0;
    virtual int scoreenemy() = 0;
    virtual Sprite retenemy()=0;
};

#endif
