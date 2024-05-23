#ifndef ARRAYNOTVECTOR_H
#define ARRAYNOTVECTOR_H

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class ArraynotVector
{
private:
    Sprite *temp;
    FloatRect box;
    Texture text;
    float xscale, yscale, xpos,ypos;

    int size;

public:
    ArraynotVector();
    ArraynotVector(int si);
    ArraynotVector(Sprite &sp);

    void add(Sprite &sp);
    void remove(int ind);
    void moveto(float x,float y);
    void moveBullet();
    void moveBullet1();
    void moveBullet2();
    void moveBullet3();
    void moveBullet4();
    void removebullet();
    void removesprite(Sprite &sp);
    void moveBomb();
    void removeBomb();
    void removeEnemy(int ind);
    void loadtext(Texture &tx);
    void settext();
    void setsca(float x,float y);
    void setpos(float x,float y, int idx);
    Sprite &retsprite(int idx);
    int retsize();
    float getx(Sprite &sp);
    float gety(Sprite &sp);
    float getheight(Sprite &sp);
    float getwidth(Sprite &sp);

    void display(RenderWindow &window);
    ~ArraynotVector();
};
#endif