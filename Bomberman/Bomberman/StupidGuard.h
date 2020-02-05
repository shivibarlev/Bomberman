#pragma once
#include "Guard.h"
class StupidGuard :public Guard
{
public:
	StupidGuard();
	virtual void guardMovement(sf::Vector2f playerLocation, std::vector<std::unique_ptr<StaticObject>> &m_statics, sf::RenderWindow &gameWindow);
	~StupidGuard();

private:
	bool first = true;
};


