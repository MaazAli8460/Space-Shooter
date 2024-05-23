#include <SFML/Graphics.hpp>
#include <string.h>
#include "ArraynotVector.h"
#include "ArraynotVector.cpp"

#include "Bullet.h"
#include "Bullet.cpp"
#include"AddOn.h"
#include"Fire.h"
#include"Fire.cpp"
#include"lives.h"
#include"lives.cpp"
#include"Powerup.h"
#include"Powerup.cpp"
#include"Danger.h"
#include"Danger.cpp"
#include<cmath>
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	ArraynotVector *firebullet;
	Bullet b1;
	Texture tex1;
	AddOn **addon;
	int playerlives;
	//Clock timepower;
	float speed = 0.4;
	int x, y;

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		tex1.loadFromFile("img/laserRed01.png");
		x = 360-20;
		y = 900;
		b1.setText(tex1);
		b1.setPosition(x,y);
		b1.setScale(1,1);
		sprite.setTexture(tex);
		sprite.setPosition(x,y);
		sprite.setScale(0.80,0.80);
		firebullet = new ArraynotVector(b1.RetBullet());
		addon = new AddOn*[4];
		addon[0] = new Danger();
		addon[1] = new lives();
		addon[2] = new Powerup();
		addon[3] = new Fire();
		playerlives=3;

	}

	void fire(RenderWindow &w)
	{
		float x, y;
		
		x = sprite.getPosition().x + 42;
		y = sprite.getPosition().y - 33;

		cout << "\nNew bullet"<< " x=" << x << " y=" << y;
		b1.setPosition(x,y);
		firebullet->add(b1.RetBullet());
		firebullet->loadtext(tex1);
		firebullet->settext();
		int s;
		s = firebullet->retsize();
		firebullet->setsca(1,1);
		cout<<"\nTotal bullets:"<<s<<endl;
		
	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;

		if (s == "l")
			delta_x = -1;
		else if (s == "r")
			delta_x = 1;
		else if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
		if(sprite.getPosition().x<=-33)
		{
			float y=sprite.getPosition().y;
			sprite.setPosition(700,y);
		}
		if(sprite.getPosition().x>=720)
		{
			float y=sprite.getPosition().y;
			sprite.setPosition(-33,y);
		}
	}
	void managepower()
	{
		if(addon[0]->retflagpu()==true)//danger
		{
			playerlives--;
			addon[0]->setflagpu(0);
		}
		if(addon[1]->retflagpu()==true)
		{
			playerlives++;
			addon[1]->setflagpu(0);
		}
	}

};
