#include "DynamicObject.h"



//this checks if the object left the board
bool DynamicObject::OutOfBoard(sf::RenderWindow &gameWindow, sf::Sprite &sprite)
{
	if (sprite.getPosition().x + 35 >= gameWindow.getSize().x || sprite.getPosition().x <= -25)
		return true;

	return false;
}

//this function checks if the object is alive
bool DynamicObject::ifAlive()
{
	return m_Alive;
}

//this function kills the object
void DynamicObject::Death()
{
	m_Alive = false;
}
