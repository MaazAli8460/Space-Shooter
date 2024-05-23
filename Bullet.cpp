#include "Bullet.h"

Bullet::Bullet(float positionx, float positiony, float scax, float scay)
{
    tex.loadFromFile("img/laserRed01.png");
    bullet = new Sprite;
    bullet->setTexture(tex);
    bullet->setPosition(positionx, positiony);
    bullet->setScale(scax, scay);
}
Bullet::Bullet()
{
    bullet=new Sprite;
}
void Bullet::setText(Texture &t)
{
    tex = t;
    bullet->setTexture(tex);
}
void Bullet::setPosition(float x, float y)
{
    bullet->setPosition(x, y);
}
void Bullet::setScale(float x, float y)
{
    bullet->setScale(x, y);
}
Sprite &Bullet::RetBullet()
{
    return *bullet;
}
void Bullet::DRAW(RenderWindow &w)
{
    w.draw(*bullet);
}

Bullet::~Bullet()
{
    delete bullet;
    bullet = NULL;
}