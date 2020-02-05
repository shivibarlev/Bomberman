#pragma once
#include "DynamicObject.h"

class Player:public DynamicObject
{
public:
	Player ();//this function builds the object
	void setFirstPosition(sf::Vector2f location);//this function sets the players first position
	sf::Sprite &spritePlayer();//this function returns the players sprite
	void move(sf::RenderWindow & gameWindow);//this function moves the player
	void draw(sf::RenderWindow & window);//this function draws the player
	void setMovement();//this function handles animation for the player

	//Winning and gift Handler//
	bool checkWon();
	bool checkTime();
	bool checkBombs();
	void resetWon();
	void resetBombs();
	void resetTime();
	void checkGift(int &timeLimit, int &bombLimit);

	//DeathHandler
	void revive();
	int HowManyLives();
	void resetLife();

	// Inherited via DynamicObject
	virtual void collide(Player & object) override {};
	virtual void collide(Guard & object) override;
	virtual void collide(Door & object) override;
	virtual void collide(Box & object) override;
	virtual void collide(Wall & object) override;
	virtual void collide(Gift & object) override;
	virtual void collide(Bomb & object) override {};
	virtual void collide(Explosion & object) override;
	virtual void collide(GameObject & object) override {};


	~Player();
private:
	sf::Keyboard::Key m_direction;//holds the direction

	int	textTimer = 0;
	float playerWalkCounter = 0;
	float playerMovementSpeed = 250;
	

	sf::Vector2f m_startLocation;
	int m_lives;
	bool m_Won = false;
	bool m_time = false;
	bool m_bombs = false;

};

