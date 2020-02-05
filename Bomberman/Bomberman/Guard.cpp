#include "Guard.h"
#include "Bomb.h"
#include "Player.h"
#include "Door.h"
#include "Box.h"
#include "Wall.h"
#include "Gift.h"


//this function builds the object
Guard::Guard()
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(2)));
}

//this function sets the objects position
void Guard::setPosition(sf::Vector2f location)
{
	m_startLocation = location;
	m_sprite.setPosition(m_startLocation);
}

//this function returns the objects sprite
sf::Sprite &Guard::getSprite()
{
	return m_sprite;
}

//this function draws the object
void Guard::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

//this function sets the movement according to the direction
void Guard::getDirection()
{
	switch (m_direction)
	{
	case UP:
		m_movement = { 0, -1 };
		break;
	case DOWN:
		m_movement = { 0, 1 };
		break;
	case RIGHT:
		m_movement = { 1, 0 };
		break;
	case LEFT:
		m_movement = { -1, 0 };
		break;
	}
	m_sprite.move(m_movement * m_guardSpeed );

}

//this functions sets a random direction
Direction_t Guard::getRandDirection()
{
	Direction_t arr[] = { LEFT,RIGHT,UP,DOWN };
	return arr[rand() % 4];
}

//these fuctions handle collusions
void Guard::collide(Player & object)
{
	object.collide(*this);
}

void Guard::collide(Guard & object)
{
	m_sprite.move(-(m_movement * m_guardSpeed ));
	m_movement = -(m_movement);
}

void Guard::collide(Door & object)
{
	m_sprite.move(-(m_movement * m_guardSpeed  ));
	m_movement = -(m_movement);
}

void Guard::collide(Box & object)
{
	m_sprite.move(-(m_movement * m_guardSpeed  ));
	m_movement = -(m_movement);
}

void Guard::collide(Wall & object)
{
	m_sprite.move(-(m_movement * m_guardSpeed ));
	m_movement = -(m_movement);
}

void Guard::collide(Bomb & object)
{
	m_sprite.move(-(m_movement * m_guardSpeed ));
	m_movement = -(m_movement);
}

void Guard::collide(Explosion & object)
{
	Death();
}
//end of collusion handle

Guard::~Guard()
{
}
