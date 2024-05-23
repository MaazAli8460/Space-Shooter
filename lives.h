#ifndef LIVES_H
#define LIVES_H
#include <SFML/Graphics.hpp>
#include "AddOn.h"
#pragma once

class lives:public AddOn
{
public:
    lives();
    bool retflagpu() override;
    void setflagpu(bool fl) override;
    void setposition(float x,float y) override;
    Sprite retpup() override;
    sf::Sprite pup;
    bool pupflag;
    sf::Texture puptex;
};


#endif