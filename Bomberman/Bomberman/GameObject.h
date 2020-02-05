#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Level.h"
#include "Macros.h"

class Player;
class Guard;
class Door;
class Box;
class Wall;
class Gift;
class Bomb;
class Explosion;

class GameObject
{
public:
	GameObject() {};
	~GameObject() {};

	virtual void collide(GameObject & object) = 0;
	virtual void collide(Player & object) = 0;
	virtual void collide(Guard & object) = 0;
	virtual void collide(Door & object) =0;
	virtual void collide(Box & object) = 0;
	virtual void collide(Wall & object) = 0;
	virtual void collide(Gift & object) = 0;
	virtual void collide(Bomb & object) = 0;
	virtual void collide(Explosion & object) = 0;



protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_startLocation;
};

