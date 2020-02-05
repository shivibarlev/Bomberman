#pragma once
#include "StaticObject.h"

class Explosion: public StaticObject
{
public:
	Explosion();//this function constructs the object.
	void setLocation(sf::Vector2f location);//thhis function sets the location of the object.
	void explosion(int &index, bool &boom);//this function handles the explosion sprite.
	~Explosion();



	// Inherited via StaticObject
	//These functions are used to apply different results for different collusions.
	virtual void collide(GameObject & object) override {};
	virtual void collide(Player & object) override;
	virtual void collide(Guard & object) override;
	virtual void collide(Door & object) override {};
	virtual void collide(Box & object) override;
	virtual void collide(Wall & object) override;
	virtual void collide(Gift & object) override {};
	virtual void collide(Bomb & object) override {};
	virtual void collide(Explosion & object) override {};

	virtual void draw(sf::RenderWindow & window) override {};//this function draws the explosion.

	virtual sf::Sprite & getStaticSprite() override;//this function returns the sprite of the object.


	// Inherited via StaticObject
	virtual bool ifBreakable() override;

};

