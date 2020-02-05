#include "Door.h"
#include "Bomb.h"
#include "Player.h"
#include "Guard.h"
#include "Box.h"
#include "Wall.h"
#include "Gift.h"



//this function constructs the object.
Door::Door(sf::Vector2f location)
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(4)));
	m_sprite.setPosition(location);
}
//this function draws the object.
void Door::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}
//this function returns the sprite of this object.
sf::Sprite & Door::getStaticSprite()
{
	return m_sprite;
}
//This function handles collusion with the player.
void Door::collide(Player & object)
{
	object.collide(*this);
}
//This function handles collusion with the guard.
void Door::collide(Guard & object)
{
	object.collide(*this);
}
//this function checks if the object is breakable.
bool Door::ifBreakable()
{
	return false;
}


Door::~Door()
{
}