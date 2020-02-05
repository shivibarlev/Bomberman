#pragma once
#include "GameObject.h"

class StaticObject:public GameObject
{
public:
	StaticObject() {};
	virtual void draw(sf::RenderWindow &window) =0;
	~StaticObject() {};
	virtual sf::Sprite & getStaticSprite()=0;
	virtual bool isAlive() { return true; };
	virtual bool ifBreakable() = 0;
	

protected:
	bool Breakable = false;

};

