#include "Bomb.h"

void Bomb::setstring(const std::string& text)
{
    type = text;
    bomb=false;
    //type.setString(t);
    if (type == "Invader")
    {
        tex.loadFromFile("img/enemy_laser.png");//image(1).png");
        bomb1.setTexture(tex);
    }
    else if (type == "Monster")
    {
        tex.loadFromFile("img/laserBlue02.png");
        bomb1.setTexture(tex);
    }
    else if (type == "Dragon")
    {
        tex.loadFromFile("img/laserGreen11.png");
        bomb1.setTexture(tex);
    }
    else
    {
        cout << "\nCannot load img";
    }
}
Texture Bomb::rett()
{
    return tex;
}

Sprite Bomb::retbomb()
{
    return bomb1;
}

void Bomb::setposition(Sprite& sp)
{
    bomb=true;
    float x = sp.getPosition().x + 33;
    float y = sp.getPosition().y;
    bomb1.setPosition(x, y);
}