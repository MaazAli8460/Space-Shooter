#include "Monsters.h"

Monsters::Monsters()
{
    enemytex.loadFromFile("img/monster1.png");
    enemyal.setTexture(enemytex);
    sp=false;
}
void Monsters::displayenemy(RenderWindow& window)
{
    enemyal.setScale(0.75, 0.75);
    window.draw(enemyal);
}
void Monsters::setPosition(float x, float y)
{
    enemyal.setPosition(x, y);
}
void Monsters::display_bomb(RenderWindow& window)
{
    b.setstring("Monster");
    bb = b.retbomb();
    bb.setPosition(enemyal.getPosition().x - 33, enemyal.getPosition().y + 33);
}
Sprite Monsters::retenemy()
{
    return enemyal;
}



int Monsters::scoreenemy()
{
    // Implement the logic to calculate the score here and return it
    return score=40;
}