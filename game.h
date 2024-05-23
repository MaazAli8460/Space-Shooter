
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>
#include "Bullet.h"
#include "Enemy.h"
#include "Invaders.h"
#include "Alpha.h"
#include "Alpha.cpp"
#include "Beta.h"
#include "Beta.cpp"
#include "Monsters.h"
#include "Monsters.cpp"
#include "Dragons.h"
#include "Highscore.h"
#include "Highscore.cpp"
#include "Dragons.cpp"
#include "Gamma.h"
#include "Gamma.cpp"
#include "Bomb.cpp"
#include "Bomb.h"
#include "Levels.h"
#include "Levels.cpp"
#include "Collision.h"
#include "Collision.cpp"
#include "ArraynotVector.h"

using namespace std;
#include "player.h"
const char title[] = "OOP-Project-SPACE_SHOOTER-Spring-2023";
using namespace sf;

class Game
{
public:
    Sprite background, mon, monbullet, drag, dargbullet, power; // Game background sprite
    Texture bg_texture;
    Player *p; // player
    Enemy ***E;
    Enemy *monster, *dragon;
    int x, y;
    Sprite ttpt;
    Texture tetp;
    ArraynotVector bulletb1, bulletm1, powerup, powerup1, powerup2, powerup3, powerup4, powerup5, bulletd1;
    Collision c1;
    int score;
    int level;
    int phase;
    int xtt;
    // add other game attributes
    Game()
    {
        p = new Player("img/tlp.png"); // player_ship
        level = 1;
        phase = 1;
        score = 0;
        bg_texture.loadFromFile("img/pro.png");
        background.setTexture(bg_texture);
        background.setScale(0.7, 0.7);
    }
    Game(int le)
    {
        p = new Player("img/tlp.png"); // player_ship
        phase = 1;
        level = le;
        score = 0;
        bg_texture.loadFromFile("img/pro.png");
        background.setTexture(bg_texture);
        background.setScale(0.7, 0.7);
    }
    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(720, 1000), title);
        Clock clock, fireclock, bombclockalpha, bombclockbeta, bombclockgama, monsterclock, dragonclock, clockdelay, addonclock, clockcp, tt;
        Clock timepower;
        float timer = 0;
        Levels l1;
        Sprite tsp;
        monster = new Monsters();
        dragon = new Dragons();
        Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12;
        Font font;
        string str, str1, str2;
        if (font.loadFromFile("animal-silence/Animal Silence.otf"))
        {
            cout << "\nCould not open font." << endl;
        }
        text1.setFont(font);
        text1.setFillColor(Color::Red);
        text1.setCharacterSize(20);
        text1.setString("SCORE:");
        text1.setPosition(480, 50);
        text3.setFont(font);
        text3.setFillColor(Color::Red);
        text3.setCharacterSize(20);
        text3.setString("Lives:");
        text3.setPosition(480, 20);
        text5.setFont(font);
        text5.setFillColor(Color::Red);
        text5.setCharacterSize(20);
        text5.setString("Level:");
        text5.setPosition(480, 80);
        text7.setFont(font);
        text7.setFillColor(Color::Red);
        text7.setCharacterSize(50);
        text7.setString("PHASE 1");
        text7.setPosition(240, 500);
        // text8;
        text8.setFont(font);
        text8.setFillColor(Color::Red);
        text8.setCharacterSize(50);
        text8.setString("PHASE 2");
        text8.setPosition(240, 500);
        // text9;
        text9.setFont(font);
        text9.setFillColor(Color::Red);
        text9.setCharacterSize(50);
        text9.setString("PHASE 3");
        text9.setPosition(240, 500);
        // text10;
        text10.setFont(font);
        text10.setFillColor(Color::Red);
        text10.setCharacterSize(30);
        text10.setString("MONSTER INCOMMING!!!!");
        text10.setPosition(240, 500);
        // text11;
        text11.setFont(font);
        text11.setFillColor(Color::Red);
        text11.setCharacterSize(30);
        text11.setString("DRAGON INCOMMING!!!!");
        text11.setPosition(240, 500);
        // text12;
        text12.setFont(font);
        text12.setFillColor(Color::Red);
        text12.setCharacterSize(50);
        text12.setString("NEXT LEVEL");
        text12.setPosition(240, 500);
        bool phasenotcleared = true, levelnotcleared = true;
        int count = 0;
        monster->setPosition(0, 0);
        dragon->setPosition(300, 200);
        drag = dragon->retenemy();
        drag.setScale(0.75, 0.75);
        dragon->b.bomb = true;
        dragon->b.setstring("Dragon");
        dargbullet = dragon->b.retbomb();
        mon = monster->retenemy();
        mon.setPosition(-300, -300);
        mon.setScale(0.5, 0.5);
        monster->b.bomb = true;
        monster->b.setstring("Monster");
        monbullet = monster->b.retbomb();
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = true;
        bool flag4 = false;
        bool infinitefire = false, straightshoot = false;
        bool monsterbool = false, dragonbool = false, time1 = true;
        int randnum;
        tetp.loadFromFile("img/shot5_exp1 (copy).png");
        ttpt.setTexture(tetp);
        ttpt.setScale(0.8, 0.8);
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }
            // E->displayenemy(window);
            if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                p->move("l");                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
                p->move("u");                            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
                p->move("d");                            // player will move downwards
            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////

            str = to_string(score);
            text2.setFont(font);
            text2.setFillColor(Color::Red);
            text2.setCharacterSize(20);
            text2.setString(str);
            text2.setPosition(600, 50);
            str1 = to_string(p->playerlives);
            text4.setFont(font);
            text4.setFillColor(Color::Red);
            text4.setCharacterSize(20);
            text4.setString(str1);
            text4.setPosition(600, 20);
            str2 = to_string(level);
            text6.setFont(font);
            text6.setFillColor(Color::Red);
            text6.setCharacterSize(20);
            text6.setString(str2);
            text6.setPosition(600, 80);
            if (addonclock.getElapsedTime().asSeconds() >= 30)
            {
                addonclock.restart();
                xtt = rand() % 4;

                p->addon[xtt]->setflagpu(false);
                power = p->addon[xtt]->retpup();
                power.setPosition(320, 0);
                powerup.add(power);
            }
            if (p->addon[xtt]->retflagpu() == true && timepower.getElapsedTime().asSeconds() <= 5)
            {
                p->managepower();
                if (p->addon[2]->retflagpu() == true)
                {
                    infinitefire = true;
                }
                else if (p->addon[3]->retflagpu() == true)
                {
                    straightshoot = true;
                }
            }
            else
            {
                p->addon[xtt]->setflagpu(false);
                infinitefire = false;
                straightshoot = false;
            }
            if (dragonbool == true)
            {
                if (clockcp.getElapsedTime().asSeconds() <= 5)
                {
                    if (clockdelay.getElapsedTime().asSeconds() >= 0.07f)
                    {
                        dragon->b.bomb = true;
                        dragon->b.setstring("Monster");
                        dargbullet = dragon->b.retbomb();
                        float xtemp = drag.getPosition().x;
                        xtemp = xtemp + (xtemp / 2);
                        float ytemp = drag.getPosition().y + 200;
                        dargbullet.setPosition(xtemp, ytemp);
                        bulletd1.add(dargbullet);
                        clockdelay.restart();
                    }
                }
                else if (clockcp.getElapsedTime().asSeconds() > 5)
                {
                    dragonbool = false;
                    for (int j = 0; j < bulletd1.retsize(); j++)
                    {
                        bulletd1.remove(j);
                    }
                    tt.restart();
                    score += dragon->scoreenemy();
                    bombclockalpha.restart();
                    bombclockbeta.restart();
                    bombclockgama.restart();
                    clockcp.restart();
                    dragonclock.restart();
                }
                else
                {
                    dragonbool = false;
                }
            }
            if (monsterbool == true && dragonbool == false)
            {
                if (mon.getPosition().x <= 200 && flag1 == false)
                {
                    mon.move(0.3, 0);
                }
                else
                {
                    flag1 = true;
                }
                if (mon.getPosition().y <= 200 && flag2 == false)
                {
                    mon.move(0, 0.3);
                }
                else
                {
                    flag2 = true;
                }
                if (flag1 == true && flag2 == true)
                {
                    float x = 200;
                    float y = 400;
                    if (mon.getPosition().x > 0 && flag3 == true)
                    {
                        mon.move(-0.4, 0);
                    }
                    else
                    {
                        flag3 = false;
                    }
                    if (mon.getPosition().x < 400 && flag3 == false)
                    {
                        mon.move(0.4, 0);
                    }
                    else
                    {
                        flag3 = true;
                    }
                    if (monsterclock.getElapsedTime().asSeconds() >= 2 && monsterclock.getElapsedTime().asSeconds() <= 5)
                    {

                        if (clockdelay.getElapsedTime().asSeconds() >= 0.07f)
                        {
                            monster->b.bomb = true;
                            monster->b.setstring("Monster");
                            monbullet = monster->b.retbomb();
                            float xtemp = mon.getPosition().x;
                            xtemp = xtemp + (xtemp / 2);
                            float ytemp = mon.getPosition().y + 200;
                            monbullet.setPosition(xtemp, ytemp);
                            bulletm1.add(monbullet);
                            clockdelay.restart();
                        }
                    }
                    else if (monsterclock.getElapsedTime().asSeconds() > 5)
                    {
                        monsterclock.restart();
                    }
                    else if (flag4 == true)
                    {
                        monsterclock.restart();
                        flag4 = false;
                    }
                }
                if (clockcp.getElapsedTime().asSeconds() >= 15)
                {
                    flag1 = false;
                    flag2 = false;
                    flag3 = false;
                    mon.setPosition(-200, -200);

                    monsterbool = false;
                    tt.restart();
                    clockcp.restart();
                    score += monster->scoreenemy();
                    bombclockalpha.restart();
                    bombclockbeta.restart();
                    bombclockgama.restart();
                }
            }
            else
            {
                monsterbool = false;
            }
            if (infinitefire == true)
            {
                if (fireclock.getElapsedTime().asSeconds() >= 0.7f)
                {

                    ttpt.setPosition(p->sprite.getPosition().x - 5, p->sprite.getPosition().y - 55);
                    powerup1.loadtext(tetp);
                    powerup1.add(ttpt);

                    powerup2.add(ttpt);

                    powerup3.add(ttpt);

                    powerup4.add(ttpt);

                    powerup5.add(ttpt);

                    fireclock.restart();
                }
            }
            if (fireclock.getElapsedTime().asSeconds() >= 0.7f && infinitefire == false)
            {
                p->fire(window);
                fireclock.restart();
                // E->b.bomb=true;
            }
            p->firebullet->moveBullet();
            p->firebullet->removebullet();
            if (level == 1 && (phase == 1 || phase == 2 || phase == 3) && phasenotcleared == true && levelnotcleared == true && time1 == true)
            {
                cout << "level 1 phase 1" << endl;
                count = rand() % 2;
                if (count == 0)
                {
                    l1.setString("Hollowrectangle");
                }
                else
                {
                    l1.setString("Hollowtriangle");
                }
                l1.setshape(E, level, phase);
                randnum = 30; // rand()%60;
                E = l1.E1;
                x = l1.E1_x;
                y = l1.E1_y;
                time1 = false;
                if (phase == 1)
                {
                    window.draw(text7);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 2)
                {
                    window.draw(text8);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 3)
                {
                    window.draw(text9);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
            }
            else if (level == 2 && (phase == 1 || phase == 2 || phase == 3) && phasenotcleared == true && levelnotcleared == true && time1 == true)
            {
                cout << "level 2 phase 1" << endl;
                count = rand() % 2;
                if (count == 0)
                {
                    l1.setString("Hollowcircle");
                }
                else
                {
                    l1.setString("Hollowcross");
                }
                l1.setshape(E, level, phase);
                E = l1.E1;
                x = l1.E1_x;
                y = l1.E1_y;
                time1 = false;
                randnum = 20;
                if (phase == 1)
                {
                    window.draw(text7);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 2)
                {
                    window.draw(text8);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 3)
                {
                    window.draw(text9);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
            }
            else if (level == 3 && (phase == 1 || phase == 2 || phase == 3) && phasenotcleared == true && levelnotcleared == true && time1 == true)
            {
                cout << "level 1 phase 1" << endl;
                count = rand() % 2;
                if (count == 0)
                {
                    l1.setString("filledrectangle");
                }
                else
                {
                    l1.setString("filledtriangle");
                }
                l1.setshape(E, level, phase);
                E = l1.E1;
                x = l1.E1_x;
                y = l1.E1_y;
                time1 = false;
                randnum = 20;
                if (phase == 1)
                {
                    window.draw(text7);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 2)
                {
                    window.draw(text8);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
                if (phase == 3)
                {
                    window.draw(text9);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                }
            }
            if (l1.phaseclear(E))
            {
                phase++;
                if (phase > 3)
                {
                    level++;
                    window.draw(text12);
                    window.display();
                    while (clock.getElapsedTime().asSeconds() <= 1)
                    {
                    }
                    clock.restart();
                    phase = 1;
                }
                time1 = true;
            }

            if (tt.getElapsedTime().asSeconds() >= randnum)
            {
                monsterbool = true;
                tt.restart();
                clockcp.restart();
                window.draw(text10);
                window.display();
                while (clock.getElapsedTime().asSeconds() <= 1)
                {
                }
                clock.restart();
            }
            if (dragonclock.getElapsedTime().asSeconds() >= randnum + 25)
            {
                dragonbool = true;
                tt.restart();
                dragonclock.restart();
                clockcp.restart();
                window.draw(text11);
                window.display();
                while (clock.getElapsedTime().asSeconds() <= 1)
                {
                }
                clock.restart();
            }
            if (monsterbool == false && dragonbool == false)
            {
                l1.levelBomb(E, level, phase, bombclockalpha, bombclockbeta, bombclockgama);
                E = l1.E1;
                for (int i = 0; i < x; i++)
                {
                    for (int j = 0; j < y; j++)
                    {
                        if (E[i][j] != NULL) // adds bomb to array
                        {
                            if (E[i][j]->b.bomb == true)
                            {
                                tsp = E[i][j]->b.retbomb();
                                bulletb1.add(tsp);
                                E[i][j]->b.bomb = false;
                            }
                        }
                    }
                }

                for (int j = 0; j < bulletb1.retsize(); j++)
                {
                    if (c1.is_collided(p->sprite, bulletb1.retsprite(j)))
                    {
                        bulletb1.remove(j);
                        if (p->playerlives > 0)
                        {
                            p->playerlives--;
                        }
                        else
                        {
                            cout << "\nGame over";
                            window.close();
                        }
                    }
                }

                for (int j = 0; j < p->firebullet->retsize(); j++)
                {
                    for (int k = 0; k < x; k++)
                    {
                        for (int i = 0; i < y; i++)
                        {
                            if (E[k][i] != NULL)
                            {
                                tsp = E[k][i]->retenemy();
                                Sprite sp1 = p->firebullet->retsprite(j);
                                if (c1.is_collided(sp1, tsp))
                                {
                                    score += E[k][i]->scoreenemy() * level;
                                    //delete E[k][i];
                                    E[k][i] = NULL;
                                    if (straightshoot == false)
                                    {
                                        p->firebullet->remove(j);
                                    }
                                }
                            }
                        }
                    }
                }
                c1.is_collided1(powerup1, E, x, y, score, level);
                c1.is_collided1(powerup2, E, x, y, score, level);
                c1.is_collided1(powerup3, E, x, y, score, level);
                c1.is_collided1(powerup4, E, x, y, score, level);
                c1.is_collided1(powerup5, E, x, y, score, level);
                // E=c1.E2;
            }
            ////////////////////////////////////////////////
            /////  Functions end here            ////
            //////////////////////////////////////////////

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            window.draw(p->sprite);     // setting player on screen
            if (p->firebullet->retsize() > 0)
            {
                p->firebullet->display(window);
            }
            if (monsterbool == false && dragonbool == false)
            {
                if (powerup1.retsize() > 0)
                {
                    powerup1.moveBullet();
                    powerup1.removebullet();
                    powerup2.moveBullet1();
                    powerup2.removebullet();
                    powerup3.moveBullet2();
                    powerup3.removebullet();
                    powerup4.moveBullet3();
                    powerup4.removebullet();
                    powerup5.moveBullet4();
                    powerup5.removebullet();
                    powerup1.display(window);
                    powerup2.display(window);
                    powerup3.display(window);
                    powerup4.display(window);
                    powerup5.display(window);
                }
                if (powerup.retsize() != 0)
                {
                    powerup.moveBomb();
                    powerup.display(window);
                    powerup.removeBomb();
                    if (c1.is_collided(powerup.retsprite(0), p->sprite))
                    {
                        powerup.remove(0);
                        p->addon[xtt]->setflagpu(true);
                        timepower.restart();
                    }
                }

                if (bulletb1.retsize() != 0)
                {
                    bulletb1.moveBomb();
                    bulletb1.removeBomb();
                    bulletb1.display(window);
                }
                for (int i = 0; i < x; i++)
                {
                    for (int j = 0; j < y; j++)
                    {
                        if (E[i][j] != NULL)
                        {
                            if (E[i][j]->retenemy().getPosition().x != 0 && E[i][j]->retenemy().getPosition().y != 0)
                            {
                                E[i][j]->displayenemy(window);
                            }
                        }
                    }
                    /* code */
                }
            }
            if (monsterbool == true)
            {
                if (c1.is_collided2(bulletm1, p->sprite))
                {
                    if (p->playerlives > 0)
                    {
                        p->playerlives--;
                    }
                    else
                    {
                        cout << "\nGame over";
                        window.close();
                    }
                }
                window.draw(mon);
            }
            if (dragonbool == true)
            {
                if (c1.is_collided2(bulletd1, p->sprite))
                {
                    if (p->playerlives > 0)
                    {
                        p->playerlives--;
                    }
                    else
                    {
                        cout << "\nGame over";
                        window.close();
                    }
                }
                window.draw(drag);
            }
            if (bulletm1.retsize() != 0)
            {
                bulletm1.moveBomb();
                bulletm1.removeBomb();
                bulletm1.display(window);
            }
            if (bulletd1.retsize() != 0)
            {
                bulletd1.moveto(p->sprite.getPosition().x, p->sprite.getPosition().y);
                bulletd1.removeBomb();
                bulletd1.display(window);
            }
            window.draw(text2);
            window.draw(text1);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.draw(text6);
            window.display(); // Displying all the sprites
            if (level > 3 || p->playerlives <= 0)
            {
                window.close();
                recordhs(score);
                // call highscore
            }
        }
    }
    void recordhs(int score)
    {
        Text text1, text2, text3;
        Font font;
        Highscore hscp;
        if (font.loadFromFile("animal-silence/Animal Silence.otf"))
        {
            cout << "\nCould not open font." << endl;
        }
        text1.setFont(font);
        text1.setFillColor(Color::Magenta);
        text1.setCharacterSize(40);
        text1.setString("ENTER YOUR NAME:");
        text1.setPosition(50, 500);
        RenderWindow window1(VideoMode(720, 1024), "GAMEOVER");
        Texture texttp;
        texttp.loadFromFile("img/level1.jpg");
        Sprite sp;
        string name;
        sp.setTexture(texttp);
        sp.setScale(0.5, 0.4);
        while (window1.isOpen())
        {
            Event e;
            while (window1.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window1.close();         // close the game
                if (e.type == sf::Event::TextEntered)
                {
                    // If the user presses a key, add the character to the text box.
                    name += e.text.unicode;
                    text1.setString("ENTER YOUR NAME: " + name);
                }
            }

            window1.clear(Color::Black); // clears the screen
            window1.draw(sp);            // setting background
            window1.draw(text1);         // setting background
            window1.display();           // Displying all the sprites
        }
        cout<<endl<<name;
        cout<<endl<<name;
        cout<<endl<<name;
        cout<<endl<<name;
        cout<<endl<<name;
        cout<<endl<<name;

        hscp.addscore(score, name);//check for errors
    }
};
