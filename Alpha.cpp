#include "Alpha.h"

Alpha::Alpha()
{
    enemytex.loadFromFile("img/enemy_1.png");
    enemyal.setTexture(enemytex);
}

void Alpha::displayenemy(RenderWindow& window)
{
    enemyal.setScale(0.75, 0.75);
    window.draw(enemyal);
}

void Alpha::setPosition(float x, float y)
{
    enemyal.setPosition(x, y);
}

void Alpha::display_bomb(RenderWindow& window)
{
    b.setstring("Invader");
    bb = b.retbomb();
    bb.setPosition(enemyal.getPosition().x - 33, enemyal.getPosition().y + 33);
}
Sprite Alpha::retenemy()
{
    return enemyal;
}



int Alpha::scoreenemy()
{
    // Implement the logic to calculate the score here and return it
    return score=10;
}