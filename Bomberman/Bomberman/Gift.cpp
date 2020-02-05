#include "Gift.h"
#include "Bomb.h"
#include "Player.h"
#include "Guard.h"
#include "Door.h"
#include "Box.h"
#include "Wall.h"




Gift::Gift(sf::Vector2f location)
{
	GiftType_t arr[] = { BOMBS, LIFE, TIME };

	int gift = arr[rand() % 3];

	m_sprite.setTexture(*(Graphics::ptr().getTexture(gift)));
	switch (gift)
	{
	case 7:
		m_type = 'B';
		break;
	case 8:
		m_type = 'L';
		break;
	case 9:
		m_type = 'T';
		break;
	}
	m_sprite.setPosition(location);
}

char Gift::getType()
{
	return m_type;;
}

bool Gift::isAlive()
{
	return m_alive;
}


void Gift::kill()
{
	m_alive = false;
}

Gift::~Gift()
{
}

void Gift::collide(Player & object)
{
	object.collide(*this);
	m_alive = false;
}

void Gift::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

sf::Sprite & Gift::getStaticSprite()
{
	// TODO: insert return statement here
	return m_sprite;
}

bool Gift::ifBreakable()
{
	return false;
}


