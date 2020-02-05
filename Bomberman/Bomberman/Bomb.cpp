#include "Bomb.h"
#include "Player.h"
#include "Guard.h"
#include "Door.h"
#include "Box.h"
#include "Wall.h"
#include "Gift.h"


//This function constructs the object.
Bomb::Bomb(sf::Vector2f location)
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(6)));
	m_sprite.setPosition(location);
	m_sprite.setTextureRect({ 0,0,31,55 });

}

//This function checks if the bomb exploded and handles the animation.
bool Bomb::check()
{

	sf::Time elapsed = m_timer.getElapsedTime();
	if (elapsed >= sf::seconds(4))
		return true;

	if (elapsed > sf::seconds(0) && elapsed < sf::seconds(1))
		m_sprite.setTextureRect({ 0,0,31,55 });
	if (elapsed > sf::seconds(1) && elapsed < sf::seconds(2))
		m_sprite.setTextureRect({ 31,0,31,55 });
	if (elapsed > sf::seconds(2) && elapsed < sf::seconds(3))
		m_sprite.setTextureRect({ 65,0,31,55 });
	if (elapsed > sf::seconds(3) && elapsed < sf::seconds(4))
		m_sprite.setTextureRect({ 98,0,31,55 });
}

//this function draws the object.
void Bomb::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

//this function returns the sprite of the object.
sf::Sprite & Bomb::getStaticSprite()
{
	return m_sprite;
}

//This function handles collusion with the player.
void Bomb::collide(Player & object)
{
	object.collide(*this);
}
//This function handles collusion with the guard.
void Bomb::collide(Guard & object)
{
	object.collide(*this);

}
//This function handles collusion with the box.
void Bomb::collide(Box & object)
{
	object.collide(*this);
}


Bomb::~Bomb()
{
}

//this function checks if the object is breakable.
bool Bomb::ifBreakable()
{
	return false;
}
