#pragma once
#include <vector>
#include <fstream>
#include "Level.h"
#include "Screens.h"
#include "GameObject.h"
#include "Player.h"
#include "StaticObject.h"
#include "Bomb.h"
#include "Guard.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include <iostream>
#include "Wall.h"
#include "Box.h"
#include "Door.h"
#include "Explosion.h"
#include "Gift.h"


/*This class holds and connects all of the game components together.*/
class Controller
{
public:
	Controller(std::string fileName);//this is the constructer for this class.
	void gamePlay();//this function runs the gameplay.
	void setMap(int lvlNum);//this function sets the objects in place on the map.
	void loadLevel(int lvlNum, int &points);//this function loads and handles the current level.
	void toolBar(sf::RenderWindow &gameWindow, sf::Clock & levelTimer, sf::Sprite & time, sf::Sprite & livesLeft,
		sf::Sprite & bombsLeft, sf::Sprite & gamePoints, sf::Text & bombs, sf::Text & levelPoints, sf::Text & timeLeft, 
		int timeLimit, int bombLimit, int &points);//this function runs the tool bar on the screen.
	void guardMovement(sf::RenderWindow &gameWindow);//this function runs the guards movement.
	void draw(sf::RenderWindow &window, sf::Sprite explode);//this function draws the items in the game.
	void drawStatics(sf::RenderWindow & window);//this function draws the static objects.
	void explosionHandler(int &index, sf::Vector2f &location);//this function handles the explosion of the bombs.
	void restartLevel(int &bombLimit, int &timeLimit, sf::Clock &levelTimer, int lvlNum);//this function restarts the current level.
	void checkDynamicCollide(int &points, int numOfGuards);//this function checks collusions between dynamic objects.
	void setGuard(sf::Vector2f location);//this function sets the guards ont the map.

	~Controller();
private:
	Screens m_screens;//this object holds the different screens.
	sf::Sprite m_BackGround;//this sprite holds the games background.
	sf::Vector2f playerPosition;//this member holds the location of the player.
	sf::Clock m_clock;//this member holds the game clock.
	sf::Time m_current;//this member is used for different time applcations.
	Player player;//this object holds the player.
	std::vector<Level> m_levels;//this vector holds the levels of the game.
	std::vector<std::unique_ptr<Bomb>> m_bombs;//this vector holds the bombs the player placed.
	std::vector<std::unique_ptr<Guard>> m_guards;//this vector holds the guards in the game.
	std::vector<std::unique_ptr<StaticObject>> m_statics;//this vector holds the static objects in the game.
	Explosion m_exp;//this object holds the explosion members and functions.

	bool m_win = false;
	bool m_boom = false;
};

