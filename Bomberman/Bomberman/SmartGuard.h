#pragma once
#include "Guard.h"
#include <queue>
class SmartGuard :public Guard
{
public:
	SmartGuard();
	virtual void guardMovement(sf::Vector2f playerLocation, std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow &gameWindow);
	void selfCheck(std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow &window);


	~SmartGuard();

private:
	std::vector<std::vector<sf::Vector3f>> Tree;
};

