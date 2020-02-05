#pragma once
#include "GameObject.h"
#include "StaticObject.h"



class DynamicObject:public GameObject
{
public:
	DynamicObject() {};//this is the contructer for this object
	virtual void draw(sf::RenderWindow &window) {};//this function draws the object
	bool OutOfBoard(sf::RenderWindow &gameWindow, sf::Sprite &sprite);//this checks if the object left the board

	bool ifAlive();//this function checks if the object is alive
	void Death();//this function kills the object

	~DynamicObject() {};

protected:
	bool m_Alive = true;//holds object status
	bool m_nolegitMove = false;//holds if the move was legit
	Direction_t m_direction;//holds the direction to be moved
	sf::Vector2f m_movement;//holds the movement made

	bool m_dynamicOnAction = false;
	sf::Clock m_tictok;//holds object clock
	sf::Time m_oldtictok;//holds object last time.
};

