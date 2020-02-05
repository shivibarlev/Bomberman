#include "Explosion.h"
#include "Player.h"
#include "Bomb.h"
#include "Guard.h"
#include "Door.h"
#include "Box.h"
#include "Wall.h"
#include "Gift.h"


//This function constructs the object.
Explosion::Explosion()
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(16)));
}

//This function sets the location of the object.
void Explosion::setLocation(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

//This function handles the objects animation.
void Explosion::explosion(int &index, bool &boom)
{
	if (boom)
	{
		m_sprite.setTextureRect(sf::Rect(index * 256, 0, 256, 256));
		index++;
	}
	if (index == 49)
		boom = false;

}

//This function handles collusion with the player.
void Explosion::collide(Player & object)
{
	object.collide(*this);
}
//This function handles collusion with the guards.
void Explosion::collide(Guard & object)
{
	object.collide(*this);
}
//This function handles collusion with the box.
void Explosion::collide(Box & object)
{
	object.collide(*this);
}
//This function handles collusion with the wall.
void Explosion::collide(Wall & object)
{
	object.collide(*this);

}
//This function returns the explosions sprite.
sf::Sprite & Explosion::getStaticSprite()
{
	return m_sprite;
}

//This function checks if the object is breakable.
bool Explosion::ifBreakable()
{
	return false;
}

Explosion::~Explosion()
{
}