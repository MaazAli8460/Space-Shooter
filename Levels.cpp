#include "Levels.h"

Levels::Levels()
{
}
void Levels::setString(string str)
{
    shape = str;
}

void Levels::setshape(Enemy ***arr, int level, int phase)
{
    if (shape == "Hollowrectangle")
    {
        E1_x = 4;
        E1_y = 7;
        arr = new Enemy **[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = new Enemy *[7];
            if (i == 3)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                    /* code */
                }
            }
            else if (i == 0)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Beta(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Gamma(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
        }
        float x = 20;
        for (int i = 0; i < 7; i++)
        {
            arr[3][i]->setPosition(x, 400);
            x += 100;
        }

        arr[2][0]->setPosition(20, 300);
        arr[2][6]->setPosition(620, 300);
        arr[1][0]->setPosition(20, 200);
        arr[1][6]->setPosition(620, 200);
        x = 20;
        for (int i = 0; i < 7; i++)
        {
            arr[0][i]->setPosition(x, 100);
            x += 100;
        }
        Sprite sp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                sp = arr[i][j]->retenemy();
                float x = sp.getPosition().x;
                float y = sp.getPosition().y;
                if (x == 0 && y == 0)
                {
                    delete arr[i][j];
                    arr[i][j] = NULL;
                }
                /* code */
            }

            /* code */
        }

        E1 = arr;
    }
    else if (shape == "Hollowtriangle")
    {
        E1_x = 4;
        E1_y = 7;
        arr = new Enemy **[4];
        int temp1 = 0, temp2 = 6;
        for (int i = 0; i < 4; i++)
        {
            arr[i] = new Enemy *[7];
            if (i == 0)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (j == 0 || j == 1 || j == 5 || j == 6)
                    {
                        arr[i][j] = new Beta(); // create new Alpha object and assign it to inv[i][j]
                        arr[i][j]->setPosition(0, 0);
                    }
                    else
                    {
                        arr[i][j] = new Gamma(); // create new gamma object and assign it to inv[i][j]
                        arr[i][j]->setPosition(0, 0);
                    }
                }
            }
            else
            {
                temp1++;
                temp2--;
                for (int j = 0; j < 7; j++)
                {
                    if (j == temp1)
                    {
                        arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                        arr[i][j]->setPosition(0, 0);
                    }
                    else if (j == temp2) //&& temp1!=temp2)
                    {
                        arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                        arr[i][j]->setPosition(0, 0);
                    }
                    else
                    {
                        arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                        arr[i][j]->setPosition(0, 0);
                    }
                }
            }
        }
        float x = 20;
        for (int i = 0; i < 7; i++)
        {
            arr[0][i]->setPosition(x, 100);
            x += 100;
        }
        x = 20;
        temp1 = 0;
        temp2 = 6;
        arr[1][1]->setPosition(120, 250);
        arr[1][5]->setPosition(520, 250);
        arr[2][2]->setPosition(220, 400);
        arr[2][4]->setPosition(420, 400);
        arr[3][3]->setPosition(320, 500);
        Sprite sp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                sp = arr[i][j]->retenemy();
                float x = sp.getPosition().x;
                float y = sp.getPosition().y;
                if (x == 0 && y == 0)
                {
                    delete arr[i][j];
                    arr[i][j] = NULL;
                }
                /* code */
            }

            /* code */
        }
        E1 = arr;
    }
    if (shape == "Hollowcross")
    {
        arr = new Enemy **[5];
        E1_x = 5;
        E1_y = 7;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = new Enemy *[7];
            if (i == 2)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else if (i <= 1)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Gamma(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Beta(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
        }
        float x = 20;
        for (int i = 0; i < 7; i++)
        {
            arr[2][i]->setPosition(x, 300);
            x += 100;
        }
        x = 20;
        arr[0][3]->setPosition(320, 100);
        arr[1][3]->setPosition(320, 200);
        arr[3][3]->setPosition(320, 400);
        arr[4][3]->setPosition(320, 500);
        Sprite sp;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                sp = arr[i][j]->retenemy();
                float x = sp.getPosition().x;
                float y = sp.getPosition().y;
                if (x == 0 && y == 0)
                {
                    delete arr[i][j];
                    arr[i][j] = NULL;
                }
                /* code */
            }

            /* code */
        }
        E1 = arr;
    }
    if (shape == "Hollowcircle")
    {
        arr = new Enemy **[5];
        E1_x = 5;
        E1_y = 5;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = new Enemy *[5];
            if (i == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    arr[i][j] = new Gamma();
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else if (i == 1 || i == 2)
            {
                for (int j = 0; j < 5; j++)
                {
                    arr[i][j] = new Beta();
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    arr[i][j] = new Alpha();
                    arr[i][j]->setPosition(0, 0);
                }
            }
        }

        // 320=ceter
        float x = 220;
        arr[0][1]->setPosition(x, 100);
        x += 100;
        arr[0][2]->setPosition(x, 50); // 320
        x += 100;
        arr[0][3]->setPosition(x, 100); // 420
        x = 160;
        arr[1][0]->setPosition(x, 200);
        x = 500;
        arr[1][4]->setPosition(x, 200);
        x = 100;
        arr[2][0]->setPosition(x, 300);
        x = 560;
        arr[2][4]->setPosition(x, 300);
        x = 160;
        arr[3][0]->setPosition(x, 400);
        x = 500;
        arr[3][4]->setPosition(x, 400);
        x = 220;
        arr[4][1]->setPosition(x, 500);
        x = 420;
        arr[4][3]->setPosition(x, 500);
        x = 320;
        arr[4][2]->setPosition(x, 550);

        Sprite sp;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                sp = arr[i][j]->retenemy();
                float x = sp.getPosition().x;
                float y = sp.getPosition().y;
                if (x == 0 && y == 0)
                {
                    delete arr[i][j];
                    arr[i][j] = NULL;
                }
                /* code */
            }

            /* code */
        }
        E1 = arr;
    }

    if (shape == "filledrectangle")
    {
        E1_x = 4;
        E1_y = 7;
        arr = new Enemy **[4];
        for (int i = 0; i < 4; i++)
        {
            arr[i] = new Enemy *[7];
            if (i == 3)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                    /* code */
                }
            }
            else if (i == 2 || i == 1)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Beta(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Gamma(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
        }
        float x = 20;
        float y = 100;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                arr[i][j]->setPosition(x, y);
                x += 100;
            }
            y += 100;
            x = 20;
        }
        E1 = arr;
    }
    if (shape == "filledtriangle")
    {
        E1_x = 4;
        E1_y = 7;
        arr = new Enemy **[4];
        int temp1 = 0, temp2 = 6;
        for (int i = 0; i < 4; i++)
        {
            arr[i] = new Enemy *[7];
            if (i == 0)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Alpha(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else if (i == 2 || i == 3)
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Beta(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    arr[i][j] = new Gamma(); // create new Alpha object and assign it to inv[i][j]
                    arr[i][j]->setPosition(0, 0);
                }
            }
        }
        float x = 20;
        float y = 100;
        temp1++;
        temp2--;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (i == 0)
                {
                    arr[i][j]->setPosition(x, y);
                    x += 100;
                }
                else if (i == 1)
                {

                    if (j >= 1)
                    {
                        if (j <= 5)
                        {
                            x += 100;
                            arr[i][j]->setPosition(x, y);
                        }
                    }
                }
                else if (i == 2)
                {

                    if (j >= 2)
                    {
                        x += 200;
                        if (j <= 4)
                        {
                            arr[i][j]->setPosition(x, y);
                            x -= 100;
                        }
                    }
                }
                else if (i == 3)
                {
                    x += 300;
                    arr[i][j]->setPosition(x, y);
                    break;
                }
            }
            y += 100;
            temp1++;
            temp2--;
            x = 20;
        }
        Sprite sp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                sp = arr[i][j]->retenemy();
                float x = sp.getPosition().x;
                float y = sp.getPosition().y;
                if (x == 0 && y == 0)
                {
                    delete arr[i][j];
                    arr[i][j] = NULL;
                }
                /* code */
            }

            /* code */
        }
        E1 = arr;
    }
}
void Levels::levelBomb(Enemy ***arr, int level, int phase, Clock &clkalpha, Clock &clkbeta, Clock &clkgama)
{
    if (shape == "Hollowrectangle")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5)
        {
            int x = -1;
            x = rand() % 7;
            if (arr[3][x] != NULL)
            {
                arr[3][x]->b.bomb = true;
                arr[3][x]->b.setstring("Invader");
                Sprite ste = arr[3][x]->retenemy();
                arr[3][x]->b.setposition(ste);

                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3)
        {
            int x = -1;
            x = rand() % 7;
            if (arr[0][x] != NULL)
            {
                arr[0][x]->b.bomb = true;
                arr[0][x]->b.setstring("Invader");
                Sprite ste = arr[0][x]->retenemy();
                arr[0][x]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2)
        {
            int x = -1, y = -1;
            y = rand() % 1 + 1;
            while (x != 0 || x != 6)
            {
                if (x == 0 || x == 6)
                {
                    break;
                }
                x = rand() % 7;
            }
            if (arr[y][x] != NULL)
            {
                arr[y][x]->b.bomb = true;
                arr[y][x]->b.setstring("Invader");
                Sprite ste = arr[y][x]->retenemy();
                arr[y][x]->b.setposition(ste);
                clkgama.restart();
            }
        }
        E1 = arr;
    }
    if (shape == "Hollowtriangle")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5)
        {
            int x = -1, y = -1;
            x = rand() % 7;
            // for(int i=0;i<)
            while (x != 1 || x != 2 || x != 3 || x != 4 || x != 5)
            {
                if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5)
                {
                    break;
                }
                x = rand() % 7;
            }
            y = rand() % 3 + 1;
            if (arr[y][x] != NULL)
            {
                arr[y][x]->b.bomb = true;
                arr[y][x]->b.setstring("Invader");
                Sprite ste = arr[y][x]->retenemy();
                arr[y][x]->b.setposition(ste);
                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3)
        {
            int x = -1;
            x = rand() % 7;
            while (x != 0 || x != 1 || x != 5 || x != 6)
            {
                if (x == 0 || x == 1 || x == 5 || x == 6)
                {
                    break;
                }
                x = rand() % 7;
            }
            if (arr[0][x] != NULL)
            {
                arr[0][x]->b.bomb = true;
                arr[0][x]->b.setstring("Invader");
                Sprite ste = arr[0][x]->retenemy();
                arr[0][x]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2)
        {
            int x = -1;
            x = rand() % 7;
            while (x != 2 || x != 3 || x != 4)
            {
                if (x == 2 || x == 3 || x == 4)
                {
                    break;
                }
                x = rand() % 7;
            }
            if (arr[0][x] != NULL)
            {
                arr[0][x]->b.bomb = true;
                arr[0][x]->b.setstring("Invader");
                Sprite ste = arr[0][x]->retenemy();
                arr[0][x]->b.setposition(ste);
                clkgama.restart();
            }
        }
        E1 = arr;
    }
    if (shape == "Hollowcross")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5)
        {
            int x = -1;
            x = rand() % 7;
            if (arr[2][x] != NULL)
            {
                arr[2][x]->b.bomb = true;
                arr[2][x]->b.setstring("Invader");
                Sprite ste = arr[2][x]->retenemy();
                arr[2][x]->b.setposition(ste);
                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3)
        {
            int x = -1;
            x = rand() % 2;
            if (x == 0)
            {
                x = 3;
            }
            else
            {
                x = 4;
            }
            if (arr[x][3] != NULL)
            {
                arr[x][3]->b.bomb = true;
                arr[x][3]->b.setstring("Invader");
                Sprite ste = arr[x][3]->retenemy();
                arr[x][3]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2)
        {
            int x = -1;
            x = rand() % 2;
            if (arr[x][3] != NULL)
            {
                arr[x][3]->b.bomb = true;
                arr[x][3]->b.setstring("Invader");
                Sprite ste = arr[x][3]->retenemy();
                arr[x][3]->b.setposition(ste);
                clkgama.restart();
            }
        }
        E1 = arr;
    }
    if (shape == "Hollowcircle")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5)
        {
            int x = -1;
            x = rand() % 2;
            if (x == 0)
            {
                x = 3;
            }
            else
            {
                x = 4;
            }
            int y = rand() % 5;
            if (arr[x][y] != NULL)
            {
                arr[x][y]->b.bomb = true;
                arr[x][y]->b.setstring("Invader");
                Sprite ste = arr[x][y]->retenemy();
                arr[x][y]->b.setposition(ste);
                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3)
        {
            int x = -1;
            x = rand() % 2;
            if (x == 0)
            {
                x = 2;
            }
            else
            {
                x = 1;
            }
            int y = rand() % 2;
            if (y == 0)
            {
                y = 0;
            }
            else
            {
                y = 4;
            }
            if (arr[x][y] != NULL)
            {
                arr[x][y]->b.bomb = true;
                arr[x][y]->b.setstring("Invader");
                Sprite ste = arr[x][y]->retenemy();
                arr[x][y]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2)
        {
            int x = -1, y = 0;
            x = rand() % 3;
            if (x == 0)
            {
                x = 1;
            }
            else if (x == 1)
            {
                x = 2;
            }
            else
            {
                x = 3;
            }
            if (arr[y][x] != NULL)
            {
                arr[y][x]->b.bomb = true;
                arr[y][x]->b.setstring("Invader");
                Sprite ste = arr[y][x]->retenemy();
                arr[y][x]->b.setposition(ste);
                clkgama.restart();
            }
        }
        E1 = arr;
    }
    if (shape == "filledrectangle")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5)
        {
            int x = rand() % 7;
            if (arr[3][x] != NULL)
            {
                arr[3][x]->b.bomb = true;
                arr[3][x]->b.setstring("Invader");
                Sprite ste = arr[3][x]->retenemy();
                arr[3][x]->b.setposition(ste);
                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3)
        {
            int x = rand() % 7;
            int y = rand() % 2;
            if (arr[y + 1][x] != NULL)
            {
                arr[y + 1][x]->b.bomb = true;
                arr[y + 1][x]->b.setstring("Invader");
                Sprite ste = arr[y + 1][x]->retenemy();
                arr[y + 1][x]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2)
        {
            int x = rand() % 7;
            if (arr[0][x] != NULL)
            {
                arr[0][x]->b.bomb = true;
                arr[0][x]->b.setstring("Invader");
                Sprite ste = arr[0][x]->retenemy();
                arr[0][x]->b.setposition(ste);
                clkgama.restart();
            }
        }
    }
    if (shape == "filledtriangle")
    {
        if (clkalpha.getElapsedTime().asSeconds() >= 5.0f)
        {
            int x = rand() % 7;
            if (arr[0][x] != NULL)
            {
                arr[0][x]->b.bomb = true;
                arr[0][x]->b.setstring("Invader");
                Sprite ste = arr[0][x]->retenemy();
                arr[0][x]->b.setposition(ste);
                clkalpha.restart();
            }
        }
        if (clkbeta.getElapsedTime().asSeconds() >= 3.0f)
        {
            int x = rand() % 7;
            int y = rand() % 2;
            if (y == 0)
            {
                y = 2;
            }
            else
            {
                y = 3;
            }
            if (y == 2 && (x == 0 || x == 1))
            {
                x += 2;
            }
            else if (y == 2 && (x == 6 || x == 5))
            {
                x -= 2;
            }
            else if (y == 3 && (x == 0 || x == 1 || x == 2))
            {
                x = 3;
            }
            else if (y == 2 && (x == 6 || x == 5 || x == 4))
            {
                x = 3;
            }

            if (arr[y][x] != NULL)
            {
                arr[y][x]->b.bomb = true;
                arr[y][x]->b.setstring("Invader");
                Sprite ste = arr[y][x]->retenemy();
                arr[y][x]->b.setposition(ste);
                clkbeta.restart();
            }
        }
        if (clkgama.getElapsedTime().asSeconds() >= 2.0f)
        {
            int x = rand() % 7;
            if (x == 0)
            {
                x = 1;
            }
            else if (x == 6)
            {
                x -= 1;
            }
            if (arr[1][x] != NULL)
            {
                arr[1][x]->b.bomb = true;
                arr[1][x]->b.setstring("Invader");
                Sprite ste = arr[1][x]->retenemy();
                arr[1][x]->b.setposition(ste);
                clkgama.restart();
            }
        }
    }
}
bool Levels::phaseclear(Enemy ***arr)
{
    bool flag = false;
    for (int i = 0; i < E1_x; i++)
    {
        for (int j = 0; j < E1_y; j++)
        {
            if (arr[i][j] == NULL)
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    // if (flag == true)
    // {
    //     for (int i = 0; i < E1_x; i++)
    //     {
    //         for (int j = 0; j < E1_y; j++)
    //         {
    //             if (arr[i][j] != NULL)
    //             {
    //                 //delete arr[i][j];
    //                 //arr[i][j]=NULL;
    //             }
                
    //         }
    //         arr[i]=NULL;
    //     }
    // }
    return flag;
}

Levels::~Levels()
{
    // write code to delete;
}