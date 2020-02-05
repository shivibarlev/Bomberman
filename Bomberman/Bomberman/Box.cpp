#include "Box.h"
#include "Bomb.h"
#include "Player.h"
#include "Guard.h"
#include "Door.h"
#include "Wall.h"
#include "Gift.h"

//this function constructs the object.
Box::Box(sf::Vector2f location)
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(3)));
	m_sprite.setPosition(location);
}

//this function draws the bomb.
void Box::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

//this function returns the sprite of this object.
sf::Sprite & Box::getStaticSprite()
{
	return m_sprite;
}

//This function handles collusion with the player.
void Box::collide(Player & object)
{
	object.collide(*this);
}
//This function handles collusion with the guard.
void Box::collide(Guard & object)
{
	object.collide(*this);
}
//This function handles collusion with the door.
void Box::collide(Door & object)
{
	object.collide(*this);
}
//This function handles collusion with an object.
void Box::collide(GameObject & object)
{
	object.collide(*this);
}

//this function checks if the object is breakable.
bool Box::ifBreakable()
{
	return true;
}

Box::~Box()
{
}
