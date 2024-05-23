#ifndef LEVELS_H
#define LEVELS_H
#include "ArraynotVector.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include "Enemy.h"
#include "Invaders.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "Bomb.h"
#pragma once

class Levels
{
public:
    Enemy ***E1;
    int E1_x,E1_y;
    int level;
    string shape;
    Levels();
    void setString(string str);
    inline void levelBomb(Enemy ***arr,int level,int phase,Clock &clkaplha, Clock &clkbeta, Clock &clkgama);
    void setshape(Enemy ***arr,int level, int phase);
    inline bool phaseclear(Enemy*** arr);
    ~Levels();

private:
};

#endif