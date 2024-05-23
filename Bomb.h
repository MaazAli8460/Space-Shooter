#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

using namespace std;
using namespace sf;

class Bomb
{
public:
    string type;
    Sprite bomb1;
    Texture tex;
    bool bomb;

    void setstring(const std::string& text);
    void setposition(Sprite& sp);
    Texture rett();
    Sprite retbomb();
};

#endif
