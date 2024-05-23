#ifndef FIRE_H
#define FIRE_H
#include <SFML/Graphics.hpp>
#include "AddOn.h"
#pragma once

class Fire:public AddOn
{
public:
    Fire();
    bool retflagpu() override;
    void setflagpu(bool fl) override;
    void setposition(float x,float y) override;
    Sprite retpup() override;
    sf::Sprite pup;
    bool pupflag;
    sf::Texture puptex;
};

#endif