#include "Dragons.h"

Dragons::Dragons()
{
    enemytex.loadFromFile("img/dragon.png");
    enemyal.setTexture(enemytex);
    sp=false;
}
void Dragons::displayenemy(RenderWindow& window)
{
    enemyal.setScale(1, 1);
    window.draw(enemyal);
}
void Dragons::setPosition(float x, float y)
{
    enemyal.setPosition(x, y);
}
void Dragons::display_bomb(RenderWindow& window)
{
    b.setstring("Dragon");
    bb = b.retbomb();
    bb.setPosition(enemyal.getPosition().x +120, enemyal.getPosition().y + 120);
}
Sprite Dragons::retenemy()
{
    return enemyal;
}
int Dragons::scoreenemy()
{
    // Implement the logic to calculate the score here and return it
    return score=50;
}