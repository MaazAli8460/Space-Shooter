#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include "ArraynotVector.h"
#include "Enemy.h"
using namespace std;
using namespace sf;
#pragma once

class Collision
{
public:
    bool flag;
    FloatRect box1,box2;
    Collision();
    bool is_collided(Sprite & sp1, Sprite& sp2);
    bool is_collided1(ArraynotVector& arr,Enemy ***E1,int x,int y,int &sc,int le);
    bool is_collided2(ArraynotVector& arr,Sprite& sp2);
    Enemy ***E2;
    ~Collision();

private:

};

#endif