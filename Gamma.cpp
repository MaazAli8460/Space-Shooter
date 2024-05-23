#include "Gamma.h"

Gamma::Gamma()
{
enemytex.loadFromFile("img/enemy_3.png");
    enemyal.setTexture(enemytex);
}

void Gamma::displayenemy(RenderWindow& window)
{
    enemyal.setScale(0.55, 0.55);
    window.draw(enemyal);
}

void Gamma::setPosition(float x, float y)
{
    enemyal.setPosition(x, y);
}

void Gamma::display_bomb(RenderWindow& window)
{
    b.setstring("Invader");
    bb = b.retbomb();
    bb.setPosition(enemyal.getPosition().x - 33, enemyal.getPosition().y + 33);
    //bb.move(0, 100);
    //window.draw(bb);
}
Sprite Gamma::retenemy()
{
    return enemyal;
}

int Gamma::scoreenemy()
{
    // Implement the logic to calculate the score here and return it
    return score=30;
}