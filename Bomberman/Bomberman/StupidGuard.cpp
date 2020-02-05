#include "StupidGuard.h"



StupidGuard::StupidGuard()
{
}

void StupidGuard::guardMovement(sf::Vector2f playerLocation, std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow & gameWindow)
{
	if (int(m_tictok.getElapsedTime().asSeconds() > rand() %2 +1 || (first)))
	{
		m_direction = getRandDirection();
		first = false;
		m_tictok.restart();
	}	

	getDirection();
	

}

StupidGuard::~StupidGuard()
{
}
