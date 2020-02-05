#pragma once
#include "StaticObject.h"
class Wall :
	public StaticObject
{
public:
	Wall(sf::Vector2f location);
	void draw(sf::RenderWindow &window);
	virtual sf::Sprite & getStaticSprite();
	~Wall();

	// Inherited via StaticObject
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

