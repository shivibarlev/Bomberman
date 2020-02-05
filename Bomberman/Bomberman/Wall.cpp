#include "Wall.h"
#include "Player.h"
#include "Guard.h"


Wall::Wall(sf::Vector2f location)
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(5)));
	m_sprite.setPosition(location);
}

void Wall::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

sf::Sprite & Wall::getStaticSprite()
{
	return m_sprite;
}


Wall::~Wall()
{
}

void Wall::collide(Player & object)
{
	object.collide(*this);
}

void Wall::collide(Guard & object)
{
	object.collide(*this);
}

bool Wall::ifBreakable()
{
	return false;
}


