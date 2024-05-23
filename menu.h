
#include "game.h"
#include <SFML/Graphics.hpp>
#include "Highscore.h"
// #include"Highscore.cpp"

class Menu
{
public:
    // int score;
    int level;
    Window window1;
    Texture bg;
    Sprite bgsp;
    Highscore hsdisp;
    // add menu attributes here
    Menu()
    {
        // RenderWindow window1;
        level=0;
        bg.loadFromFile("img/BG.jpg");
        bgsp.setTexture(bg);
        bgsp.setScale(1, 0.8);

        // constructors body
    }

    void display_menu()

    {
        RenderWindow window1(VideoMode(720, 1280), "MENU");
        Text t1;
        Font font;
        string str, str1, str2;
        if (font.loadFromFile("animal-silence/Animal Silence.otf"))
        {
            cout << "\nCould not open font." << endl;
        }
        bool gamebool = false,levelbool=false;
        while (window1.isOpen())
        {
            Event e;
            while (window1.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window1.close();         // close the game
            }
            if (Keyboard::isKeyPressed(Keyboard::Num1)) // If left key is pressed
            {
                gamebool = true;
                window1.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2)) // If left key is pressed
            {
                infodisp();
            }
            if (Keyboard::isKeyPressed(Keyboard::Num4)) // If left key is pressed
            {
                hsdisp.displayhighscore();
                
            }
            if (Keyboard::isKeyPressed(Keyboard::Num5)) // If left key is pressed
            {
                level=leveldisp();
                if(level>0 && level<=3)
                {
                    levelbool=true;
                    window1.close();
                }
            }
            
            window1.clear(Color::Black); // clears the screen
            window1.draw(bgsp);          // setting background
            window1.display();           // Displying all the sprites
        }
        if (gamebool)
        {
            Game g;
            gamebool=false;
            g.start_game();
        }
        if (levelbool)
        {
            Game g1(level);
            levelbool=false;
            g1.start_game();
        }
    }
    int leveldisp()
    {
        int levelselect;
        RenderWindow window2(VideoMode(720,1040),"LEVEL-SELECT");
        Texture twx;
        twx.loadFromFile("img/levelselect.png");
        Sprite spbg;
        spbg.setTexture(twx);
        spbg.setScale(0.8,0.65);
        while (window2.isOpen())
        {
            Event e;
            while (window2.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window2.close();         // close the game
                if (Keyboard::isKeyPressed(Keyboard::Num1))
                {
                    levelselect=1;
                    window2.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Num2))
                {
                    levelselect=2;
                    window2.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Num3))
                {
                    levelselect=3;
                    window2.close();
                }
            }

            window2.clear(Color::Black); // clears the screen
            window2.draw(spbg);            // setting background
            //window2.draw(text1);         // setting background
            window2.display();           // Displying all the sprites
        }

        return levelselect;
    }
    void infodisp()
    {
        RenderWindow window2(VideoMode(720,1080),"INFORMATION");
        Texture twx;
        twx.loadFromFile("img/info.jpg");
        Sprite spbg;
        spbg.setTexture(twx);
        spbg.setScale(1,1);
        while (window2.isOpen())
        {
            Event e;
            while (window2.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window2.close();         // close the game
                
            }

            window2.clear(Color::Black); // clears the screen
            window2.draw(spbg);            // setting background
            //window2.draw(text1);         // setting background
            window2.display();           // Displying all the sprites
        }
    }
};
