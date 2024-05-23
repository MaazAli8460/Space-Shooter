#ifndef ADDON_H
#define ADDON_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include "ArraynotVector.h"
using namespace std;
#pragma once

class AddOn
{
public:
    virtual bool retflagpu()=0;
    virtual void setflagpu(bool fl)=0;
    virtual void setposition(float x,float y)=0;
    virtual Sprite retpup()=0;

private:

};

#endif