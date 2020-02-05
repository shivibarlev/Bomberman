#include "SmartGuard.h"



SmartGuard::SmartGuard()
{
}

void SmartGuard::guardMovement(sf::Vector2f playerLocation, std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow & gameWindow)
{
	if (playerLocation.x < m_sprite.getPosition().x)
	{

		m_direction = LEFT;
		getDirection();
		selfCheck(m_statics, gameWindow);
	}
	if (playerLocation.x > m_sprite.getPosition().x)
	{
		m_direction = RIGHT;
		getDirection();
		selfCheck(m_statics, gameWindow);
	}
	if (playerLocation.y < m_sprite.getPosition().y)
	{
		m_direction = UP;
		getDirection();
		selfCheck(m_statics, gameWindow);
	}
	if (playerLocation.y > m_sprite.getPosition().y)
	{
		m_direction = DOWN;
		getDirection();
		selfCheck(m_statics, gameWindow);
	}
	
	


}
void SmartGuard::selfCheck(std::vector<std::unique_ptr<StaticObject>>& m_statics, sf::RenderWindow &window)
{
	for (size_t i = 0; i < m_statics.size(); i++)
	{
		if (m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_sprite.getPosition().x + 15 , m_sprite.getPosition().y + 10 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_sprite.getPosition().x + 39, m_sprite.getPosition().y + 55 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_sprite.getPosition().x + 15, m_sprite.getPosition().y + 55 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_sprite.getPosition().x + 39, m_sprite.getPosition().y + 10 }) ||
			OutOfBoard(window, m_sprite))
		{
			m_statics[i]->collide(*this);
		}
	}
}

SmartGuard::~SmartGuard()
{
}
