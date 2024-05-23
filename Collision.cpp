#include "Collision.h"

Collision::Collision()
{
    flag = false;
}
bool Collision::is_collided(Sprite &sp1, Sprite &sp2)
{
    box1 = sp1.getGlobalBounds();
    box2 = sp2.getGlobalBounds();
    float x1 = box1.left;
    float x2 = box2.left;
    float y1 = box1.top;
    float y2 = box2.top;
    float w1 = box1.width;
    float w2 = box2.width;
    float h1 = box1.height;
    float h2 = box2.height;
    if ((x1 + w1 > x2 && x1 < x2 + w2) && (y1 + h1 > y2 && y1 < y2 + h2))
    {
        flag = true;
        // return true;
    }
    else
    {
        flag = false;
        // return false;
    }
    // float xtemp,ytemp;

    return flag;
}
bool Collision::is_collided1(ArraynotVector &arr, Enemy ***E1, int x, int y,int &sc,int le)
{
    Sprite sp2;
    for (int j = 0; j < arr.retsize(); j++)
    {
        for (int k = 0; k < x; k++)
        {
            for (int i = 0; i < y; i++)
            {
                if (E1[k][i] != NULL)
                {
                    sp2 = E1[k][i]->retenemy();
                    Sprite sp1 = arr.retsprite(j);
                    if (is_collided(sp1, sp2))
                    {
                        sc+=E1[k][i]->scoreenemy()*le;
                        //delete E1[k][i];
                        E1[k][i] = NULL;
                        arr.remove(j);
                    }
                }
            }
        }
    }
    // E2=E1;
    return true;
}
bool Collision::is_collided2(ArraynotVector &arr, Sprite &sp2)
{
    flag=false;
    for (int j = 0; j < arr.retsize(); j++)
    {
        Sprite sp1 = arr.retsprite(j);
        if (is_collided(sp1, sp2))
        {
            arr.remove(j);
            flag=true;
            break;
        }
        else
        {
            flag=false;
        }
    }
    return flag;
}

Collision::~Collision()
{
}