#pragma once
#include "StaticObject.h"




class Gift :public StaticObject
{
public:
	Gift(sf::Vector2f location);//this function builds the object
	char getType();//this function returns the type of the gift
	bool isAlive();//this function checks if the object is alive
	void kill();//this function kills the object
	~Gift();

	// Inherited via StaticObject
	//see staticObject
	virtual void collide(Player & object) override;
	virtual void collide(Guard & object) override {};
	virtual void collide(Door & object) override {};
	virtual void collide(Box & object) override {};
	virtual void collide(Wall & object) override {};
	virtual void collide(Gift & object) override {};
	virtual void collide(Bomb & object) override {};
	virtual void collide(Explosion & object) override {};
	virtual void draw(sf::RenderWindow & window) override;
	virtual void collide(GameObject & object) override {};

	virtual sf::Sprite & getStaticSprite() override;


	virtual bool ifBreakable() override;

private:
	char m_type;//holds gift type
	bool m_alive = true;//holds gift status
};


