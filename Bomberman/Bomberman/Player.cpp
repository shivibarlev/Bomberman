#include "Player.h"
#include "Bomb.h"
#include "Guard.h"
#include "Door.h"
#include "Box.h"
#include "Wall.h"
#include "Gift.h"


//this function builds the player
Player::Player()
{
	m_sprite.setTexture(*(Graphics::ptr().getTexture(1)));
	m_sprite.setTextureRect(sf::IntRect(0, 0, 50, 55));
	m_lives = 3;

}

//this function sets initial position
void Player::setFirstPosition(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

sf::Sprite & Player::spritePlayer()
{
	return m_sprite;
}

void Player::move(sf::RenderWindow & gameWindow)
{
	if (!(m_nolegitMove = OutOfBoard(gameWindow, m_sprite)))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_dynamicOnAction = true;
			m_direction = sf::Keyboard::Left;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_dynamicOnAction = true;
			m_direction = sf::Keyboard::Right;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_dynamicOnAction = true;
			m_direction = sf::Keyboard::Up;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_dynamicOnAction = true;
			m_direction = sf::Keyboard::Down;
		}
		if (m_dynamicOnAction)
		{
			setMovement();
			m_sprite.move(m_movement * playerMovementSpeed * m_tictok.getElapsedTime().asSeconds());

			textTimer++;

			if (textTimer % 2 == 0)
			{
				playerWalkCounter++;
				textTimer = 0;
			}
			if (playerWalkCounter == 3)
				playerWalkCounter = 0;
		}
	}
	
		m_dynamicOnAction = false;


	m_oldtictok = m_tictok.getElapsedTime();
	m_tictok.restart();
}
void Player::setMovement()
{
	

	switch (m_direction)
	{
	case sf::Keyboard::Right:
		m_movement = { 1,0 };
		m_sprite.setTextureRect(sf::IntRect(playerWalkCounter * 65, 325, 50, 60));
		break;
	case sf::Keyboard::Left:
		m_movement = { -1,0 };
		m_sprite.setTextureRect(sf::IntRect(playerWalkCounter * 65, 130, 50, 60));
		break;
	case sf::Keyboard::Up:
		m_movement = { 0,-1 };
		m_sprite.setTextureRect(sf::IntRect(playerWalkCounter * 65, 65, 50, 60));
		break;
	case sf::Keyboard::Down:
		m_movement = { 0, 1 };
		m_sprite.setTextureRect(sf::IntRect(playerWalkCounter * 65, 0, 50, 60));
		break;
	}
}

bool Player::checkWon()
{
	return m_Won;
}
bool Player::checkTime()
{
	return m_time;
}
bool Player::checkBombs()
{
	return m_bombs;
}
void Player::resetWon()
{
	m_Won = false;
}
void Player::resetBombs()
{
	m_bombs = false;
}
void Player::resetTime()
{
	m_time = false;
}
void Player::checkGift(int & timeLimit, int & bombLimit)
{
	if (m_bombs)
	{
		bombLimit += 4;
		m_bombs = false;
	}
	if (m_time)
	{
		timeLimit += 40;
		m_time = false;
	}
}

void Player::revive()
{
	m_Alive = true;
}

int Player::HowManyLives()
{
	return m_lives;
}

void Player::resetLife()
{
	m_lives = 3;
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Player::collide(Guard & object)
{
	if(m_Alive == true)
		m_lives--;

	Death();
}

void Player::collide(Door & object)
{
	m_Won = true;
}

void Player::collide(Box & object)
{
	m_sprite.move(-(m_movement*playerMovementSpeed*m_oldtictok.asSeconds()));
}

void Player::collide(Wall & object)
{
	m_sprite.move(-(m_movement*playerMovementSpeed*m_oldtictok.asSeconds()));
}

void Player::collide(Gift & object)
{
	switch (object.getType())
	{
	case 'T':
		m_time = true;
		break;
	case 'B':
		m_bombs = true;
	case 'L':
		resetLife();
	}
}

void Player::collide(Explosion & object)
{
	if (m_Alive == true)
		m_lives--;

	Death();
}


Player::~Player()
{
}