#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;


class Bullet
{
private:
    Sprite *bullet;
    Texture tex;
    int posx,posy;
    float scalex,scaley;
    /* data */
public:
    Bullet(float positionx,float positiony, float scax, float scay);
    Bullet();
    void setText(Texture& t);
    void setPosition(float x, float y);
    void setScale(float x, float y);
    Sprite &RetBullet();
    //Bullet(bool mulbullets);
    void DRAW(RenderWindow & w);
    ~Bullet();
};

#endif