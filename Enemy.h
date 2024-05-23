#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "ArraynotVector.h"
#include <iostream>
#include "Bomb.h"

using namespace std;
using namespace sf;

class Enemy
{
public:
    string type;
    Bomb b;
    int damage;
    int score;
    int phase;
    int level;

    //virtual ~Enemy() {}
    virtual void displayenemy(RenderWindow& window) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void display_bomb(RenderWindow& window) = 0;
    virtual int scoreenemy() = 0;
    virtual Sprite retenemy()=0;
};

#endif
