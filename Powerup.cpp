#include "Powerup.h"


Powerup::Powerup()
{
    puptex.loadFromFile("img/Speed_Icon.png");
    pup.setTexture(puptex);
    pup.scale(0.8,0.8);

}
bool Powerup::retflagpu()
{
    return pupflag;
}
void Powerup::setflagpu(bool fl) 
{
    pupflag=fl;
}
void Powerup::setposition(float x, float y) 
{
    pup.setPosition(x, y);
}
Sprite Powerup::retpup() 
{
    return pup;
}
