#include "lives.h"


lives::lives()
{
    puptex.loadFromFile("img/HP_Icon.png");
    pup.setTexture(puptex);
    pup.scale(0.8,0.8);

}
bool lives::retflagpu()
{
    return pupflag;
}
void lives::setflagpu(bool fl) 
{
    pupflag=fl;
}
void lives::setposition(float x, float y) 
{
    pup.setPosition(x, y);
}
Sprite lives::retpup() 
{
    return pup;
}
