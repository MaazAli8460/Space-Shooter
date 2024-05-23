#include "Fire.h"


Fire::Fire()
{
    puptex.loadFromFile("img/pngegg(17).png");
    pup.setTexture(puptex);
    pup.scale(0.8,0.8);

}
bool Fire::retflagpu()
{
    return pupflag;
}
void Fire::setflagpu(bool fl) 
{
    pupflag=fl;
}
void Fire::setposition(float x, float y) 
{
    pup.setPosition(x, y);
}
Sprite Fire::retpup() 
{
    return pup;
}
