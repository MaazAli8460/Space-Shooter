
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
//#include <time.h>
//#include "ArraynotVector.h"

class Bullet
{
private:
    Sprite *bullet;
    Texture tex;
    int posx,posy;
    float scalex,scaley;
    /* data */
public:
    Bullet(int positionx,int positiony, float scax, float scay,RenderWindow &w);
    Sprite &RetBullet();
    //Bullet(bool mulbullets);
    void DRAW(RenderWindow & w);
    ~Bullet();
};

Bullet::Bullet(int positionx, int positiony, float scax, float scay,RenderWindow &w)
{
    tex.loadFromFile("img/laserRed01.png");
    bullet =new Sprite;
    bullet->setTexture(tex);
    bullet->setPosition(positionx,positiony);
    bullet->setScale(scax,scay);
    DRAW(w);

}
Sprite & Bullet::RetBullet()
{
    return *bullet;
}
void Bullet::DRAW(RenderWindow & w)
{
    w.draw(*bullet);
}

Bullet::~Bullet()
{
    bullet=NULL;
}
