#pragma once
#include "StaticObject.h"
class Door : public StaticObject
{
public:
	Door(sf::Vector2f location);//this function constructs the object.
	void draw(sf::RenderWindow &window);//this function draws the object.
	virtual sf::Sprite & getStaticSprite();//this function returns the sprite of this object.
	~Door();

	// Inherited via StaticObject
	//These functions are used to apply different results for different collusions.
	virtual void collide(Player & object) override;
	virtual void collide(Guard & object) override;
	virtual void collide(Door & object) override {};
	virtual void collide(Box & object) override {};
	virtual void collide(Wall & object) override {};
	virtual void collide(Gift & object) override {};
	virtual void collide(Bomb & object) override {};
	virtual void collide(Explosion & object) override {};

	// Inherited via StaticObject
	virtual void collide(GameObject & object) override {};

	// Inherited via StaticObject
	virtual bool ifBreakable() override;
};

