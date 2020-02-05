#pragma once
#include "DynamicObject.h"
#include "StaticObject.h"

class Guard: public DynamicObject
{
public:
	Guard();//this function builds the object
	void setPosition(sf::Vector2f location);//this function sets the objects position
	//this function handles the guards movement 
	virtual void guardMovement(sf::Vector2f playerLocation, std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow &gameWindow) {};
	sf::Sprite &getSprite();//this function returns the sprite of the object
	void draw(sf::RenderWindow &window);//this function draws the object
	void getDirection();//this function sets the right movement from the direction
	Direction_t getRandDirection();//this function sets a random direction to move


	// Inherited via DynamicObject
	//see dynamic object
	virtual void collide(Player & object) override;
	virtual void collide(Guard & object) override;
	virtual void collide(Door & object) override;
	virtual void collide(Box & object) override;
	virtual void collide(Wall & object) override;
	virtual void collide(Gift & object) override {};
	virtual void collide(Bomb & object) override;
	virtual void collide(Explosion & object) override;

	// Inherited via DynamicObject
	virtual void collide(GameObject & object) override {};

	 ~Guard();
protected:
	bool m_alive;//holds objects status
	float m_guardSpeed = 2;//holds objects moving speed
	

};

