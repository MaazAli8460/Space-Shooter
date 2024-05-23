#include "ArraynotVector.h"

ArraynotVector::ArraynotVector()
{
    size = 0;
    temp = NULL;
}
ArraynotVector::ArraynotVector(int si)
{
    temp = new Sprite[si];
    size = si;
}
void ArraynotVector::moveBullet()
{
    for (int i = 0; i < size; i++)
    {
    	if(temp!=NULL)
    	{
        //cout << "\nBefore Move BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
        temp[i].move(0, -0.5);
        //cout << "\nAfter Move  BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
	}
        /* code */
    }
}
void ArraynotVector::moveBullet1()
{
    for (int i = 0; i < size; i++)
    {
    if(temp!=NULL)
    	{
        //cout << "\nBefore Move BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
        temp[i].move(-0.2, -0.5);
        //cout << "\nAfter Move  BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
	}
        /* code */
    }
}
void ArraynotVector::moveBullet2()
{
    for (int i = 0; i < size; i++)
    {
    if(temp!=NULL)
    	{
        //cout << "\nBefore Move BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
        temp[i].move(0.2, -0.5);
        //cout << "\nAfter Move  BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
	}
        /* code */
    }
}
void ArraynotVector::moveBullet3()
{
    for (int i = 0; i < size; i++)
    {
    if(temp!=NULL)
    	{
        //cout << "\nBefore Move BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
        temp[i].move(-0.3, -0.5);
        //cout << "\nAfter Move  BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
	}
        /* code */
    }
}
void ArraynotVector::moveBullet4()
{
    for (int i = 0; i < size; i++)
    {
    if(temp!=NULL)
    	{
        //cout << "\nBefore Move BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
        temp[i].move(+0.3, -0.5);
        //cout << "\nAfter Move  BULLET:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
	}
        /* code */
    }
}
ArraynotVector::ArraynotVector(Sprite &sp)
{
    if (temp == NULL)
    {
        size = 1;
        temp = new Sprite[1];
        temp[0] = sp;
    }
}
void ArraynotVector::loadtext(Texture &tx)
{
    text = tx;
}
void ArraynotVector::settext()
{
    for (int i = 0; i < size; i++)
    {
        temp[i].setTexture(text);
        /* code */
    }
}

void ArraynotVector::setsca(float x, float y)
{
    for (int i = 0; i < size; i++)
    {
        temp[i].setScale(x, y);
        /* code */
    }
}
void ArraynotVector::setpos(float x, float y, int idx)
{
    temp[idx].setPosition(x, y);
}
void ArraynotVector::add(Sprite &sp)
{
    cout << "\nIn Add\n";
    if (temp == NULL)
    {
        cout << "\nIn Add if\n";
        size = 1;
        temp = new Sprite[2];
        temp[0] = sp;
    }
    else
    {
        cout << "\nIn Add else\n";
        cout << "\nError1";
        Sprite *temp2 = new Sprite[size + 1]; // gives segmentation error
        cout << "\nError2";
        for (int i = 0; i < size; i++)
        {
            cout << "\nIn loop add " << i << endl;
            temp2[i] = temp[i];
            cout << "\nIn loop add operation complete. " << i << endl;

            /* code */
        }
        temp2[size] = sp;

        if (size == 1)
        {
            delete[] temp;
            temp = NULL;
        }
        else if (temp != NULL && size > 1)
        {
            delete[] temp;
            temp = NULL;
        }
        size++;
        temp = temp2;
        temp2 = NULL;
    }
}
void ArraynotVector::remove(int ind)
{
    if (temp == NULL)
    {
        cout << "\nArray empty.";
        return;
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            Sprite *temp2 = new Sprite[size - 1];
            int x = 0;
            for (int i = 0; i < size; i++)
            {
                if (i == ind)
                {
                    continue;
                }
                else
                {
                    cout << "\nIn Remove------------------------------.";

                    temp2[x] = temp[i];
                    x++;
                }
            }
            if (size == 0)
            {
                delete temp;
            }
            else
            {
                delete[] temp;
            }
            temp = NULL;
            temp = temp2;
            temp2 = NULL;
            size--;
        }
    }
}
void ArraynotVector::moveBomb()
{
    if (temp == NULL || size == 0)
    {
        cout << "\nNo sprites.";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\nBefore Move Bomb:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
            temp[i].move(0, +0.3);
            cout << "\nAfter Move  Bomb:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;

            /* code */
        }
    }
}
void ArraynotVector::moveto(float x, float y)
{
    if (temp == NULL || size == 0)
    {
        cout << "\nNo sprites.";
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "\nBefore Move to:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
                if (x <= 240)
                {
                    temp[i].move(-0.2, 0.5);
                }
                else if (x > 240 && x <= 480)
                {
                    temp[i].move(0, 0.5);
                }
                else if (x > 240 && x <= 720)
                {
                    temp[i].move(0.2, 0.5);
                }
                cout << "\nAfter Move to:" << i << "  x:" << temp[i].getPosition().x << "  y:" << temp[i].getPosition().y;
                /* code */
            }
        }
    }
}

void ArraynotVector::removesprite(Sprite &sp)
{
    if (temp == NULL)
    {
        cout << "\nNo sprites";
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            int ind = 0;
            for (int i = 0; i < size; i++)
            {
                if (temp[i].getPosition().x == 0 && temp[i].getPosition().y == 0)
                {
                    ind = i;
                    remove(ind);
                    break;
                }
            }
        }
    }
}

void ArraynotVector::removeBomb()
{
    if (temp == NULL || size == 0)
    {
        cout << "\nNo bomb to remove" << endl;
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            bool flag = false;
            int index;
            for (int i = 0; i < size; i++)
            {
                cout << "\nLoop for remove. bomb";

                if (temp[i].getPosition().y >= 1050)
                {
                    cout << "\nIN if condition.";
                    index = i;
                    flag = true;
                    remove(index);
                    cout << "\nBomb 3333333333333333333333333333333333333333333333 Deleted";
                    break;
                }
            }
        }
    }
}
Sprite &ArraynotVector::retsprite(int idx)
{
    return temp[idx];
}
int ArraynotVector::retsize()
{
    return size;
}

void ArraynotVector::removebullet()
{
    if (temp == NULL)
    {
        cout << "\nNo bullets to remove" << endl;
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            bool flag = false;
            int index;
            for (int i = 0; i < size; i++)
            {
                cout << "\nLoop for remove.";

                if (temp[i].getPosition().y <= -10 || temp[i].getPosition().x <= -10 || temp[i].getPosition().x >= 760)
                {
                    cout << "\nIN if condition.";
                    index = i;
                    flag = true;
                    remove(index);
                    cout << "\nBullet 33333333333333333333333 Deleted";
                    break;
                }
            }
        }
    }
}
void ArraynotVector::removeEnemy(int ind)
{
    if (temp == NULL)
    {
        cout << "\nNo enemies to remove" << endl;
    }
    else
    {
        if (temp != NULL && size > 0)
        {
            bool flag = false;
            int index;
            for (int i = 0; i < size; i++)
            {
                if (i == ind)
                {
                    remove(i);
                }
            }
        }
    }
}
float ArraynotVector::getx(Sprite &sp)
{
    box = sp.getGlobalBounds();
    return box.left;
}
float ArraynotVector::gety(Sprite &sp)
{
    box = sp.getGlobalBounds();
    return box.top;
}
float ArraynotVector::getheight(Sprite &sp)
{
    box = sp.getGlobalBounds();
    return box.height;
}
float ArraynotVector::getwidth(Sprite &sp)
{
    box = sp.getGlobalBounds();
    return box.width;
}
void ArraynotVector::display(RenderWindow &window)
{
    cout << "\nIn display\n";
    if (temp != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if ((temp + i) != NULL)
            {
                window.draw(temp[i]);
            }
            /* code */
        }
    }
    cout << "\nOUT display\n";
}
ArraynotVector::~ArraynotVector()
{
    if (size == 1)
    {
        delete[] temp;
        temp = NULL;
        size = 0;
    }
    else
    {
        temp = NULL;
        delete[] temp;
        size = 0;
    }
}
