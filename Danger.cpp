#include "Danger.h"

Danger::Danger()
{
    puptex.loadFromFile("img/pngegg(14).png");
    pup.setTexture(puptex);
    pup.scale(0.8,0.8);
}
bool Danger::retflagpu()
{
    return pupflag;
}
void Danger::setflagpu(bool fl) 
{
    pupflag=fl;
}
void Danger::setposition(float x, float y) 
{
    pup.setPosition(x, y);
}
Sprite Danger::retpup() 
{
    return pup;
}
