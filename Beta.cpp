#include "Beta.h"

Beta::Beta()
{
 enemytex.loadFromFile("img/enemy_2.png");
    enemyal.setTexture(enemytex);
}


void Beta::displayenemy(RenderWindow& window)
{
    enemyal.setScale(0.75, 0.75);
    window.draw(enemyal);
}

void Beta::setPosition(float x, float y)
{
    enemyal.setPosition(x, y);
}

void Beta::display_bomb(RenderWindow& window)
{
    b.setstring("Invader");
    bb = b.retbomb();
    bb.setPosition(enemyal.getPosition().x - 33, enemyal.getPosition().y + 33);
    //bb.move(0, 100);
    //window.draw(bb);
}
Sprite Beta::retenemy()
{
    return enemyal;
}



int Beta::scoreenemy()
{
    // Implement the logic to calculate the score here and return it
    return score=20;
}