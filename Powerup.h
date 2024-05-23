#ifndef POWERUP_H
#define POWERUP_H
#include "AddOn.h"
#include <SFML/Graphics.hpp>
#pragma once

class Powerup:public AddOn
{
public:
    Powerup();
    bool retflagpu() override;
    void setflagpu(bool fl) override;
    void setposition(float x,float y) override;
    Sprite retpup() override;
    sf::Sprite pup;
    bool pupflag;
    sf::Texture puptex;
};


#endif