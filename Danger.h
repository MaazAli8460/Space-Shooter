#ifndef DANGER_H
#define DANGER_H
#include <SFML/Graphics.hpp>
#include "AddOn.h"
#pragma once

class Danger:public AddOn
{
public:
    Danger();
    bool retflagpu() override;
    void setflagpu(bool fl) override;
    void setposition(float x,float y) override;
    Sprite retpup() override;
    sf::Sprite pup;
    bool pupflag;
    sf::Texture puptex;
};

#endif