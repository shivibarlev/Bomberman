#include "Controller.h"
#include <iostream>



//This function cunstructs the controller object.
Controller::Controller(std::string fileName)
{
	std::ifstream levelsFile;//this stream holds the file with the levls.
	std::vector<std::string> map;//this vector holds the level as strings.
	std::string holder;//this string acts as a place holder.

	int lvlNum = 1, width, height, bombs, limit;//these integers hold different information about the level
	bool firstLine = true;//holds if this is the first line of the level that is being read.


	levelsFile.open(fileName);

	if (levelsFile.is_open())
	{
		while (!levelsFile.eof())//this loop reads until the end of the file.
		{
			if (firstLine)//for the level data
			{
				levelsFile >> width >> height >> bombs >> limit;
				firstLine = false;
				std::getline(levelsFile, holder);
			}

			std::getline(levelsFile, holder);//gets the current line in the place holder.

			if (levelsFile.eof())//place in the vector
			{
				map.push_back(holder);
				Level level(lvlNum, map, width, height, bombs, limit);
				m_levels.push_back(level);
				continue;
			}
			if (holder == "")//place in the vector
			{
				Level level(lvlNum, map, width, height, bombs, limit);
				m_levels.push_back(level);
				map.clear();
				lvlNum++;
				firstLine = true;
				continue;
			}

			map.push_back(holder);//place into the map
		}
	}
	levelsFile.close();
}

/*This function controls the gameplay*/
void Controller::gamePlay()
{

	int lvlNum = m_screens.startMenu_window();//select level
	int points = 0;

	while (lvlNum - 1 < m_levels.size())
	{
		loadLevel(lvlNum, points);//run the level

		if (player.checkWon())
		{
			lvlNum++;
			if (lvlNum == m_levels.size() + 1)
			{
				if (m_screens.Winner_window())
					lvlNum = 1;
			}
			else
				m_screens.Next_window();
		}
	}
}



//This function sets the objects on the map.
void Controller::setMap(int lvlNum)
{
	std::vector<std::string> map;//this vector holds the level map.
	map = m_levels[lvlNum - 1].getMap();

	for (size_t i = 0; i < map.size(); i++)//these loops run on the map.
	{
		for (size_t j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] == '#')
			{
				m_statics.push_back(std::make_unique <Wall>(sf::Vector2f(j * 55, i * 55 + 40)));
			}
			if (map[i][j] == '@')
			{
				m_statics.push_back(std::make_unique <Box>(sf::Vector2f(j * 55, i * 55 + 40)));
			}
			if (map[i][j] == 'D')
			{
				m_statics.push_back(std::make_unique <Door>(sf::Vector2f(j * 55, i * 55 + 40)));
			}
			if (map[i][j] == '+')
			{
				m_statics.push_back(std::make_unique <Gift>(sf::Vector2f(j * 55, i * 55 + 40)));
			}
			if (map[i][j] == '!')
			{
				setGuard(sf::Vector2f(j * 55, i * 55 + 40));
			}
			if (map[i][j] == '/')
			{
				playerPosition.x = j * 55;
				playerPosition.y = i * 55 + 40;
			}

		}
	}
}

//this function runs the selected level.
void Controller::loadLevel(int lvlNum, int &points)
{
	player.resetWon();
	int numOfGuards;
	int bombLimit = m_levels[lvlNum - 1].getBombLimit();//holds the bomb limit
	int timeLimit = m_levels[lvlNum - 1].getTimeLimit();//holds the time limit in seconds
	sf::RenderWindow gameWindow(sf::VideoMode((unsigned int)m_levels[lvlNum - 1].getMap()[0].size() * 55, (unsigned int)m_levels[lvlNum - 1].getMap().size() * 55 + 40), "BomberMan");
	gameWindow.setFramerateLimit(30);
	sf::Vector2f explosionLocation;
	sf::Time movement;
	sf::Clock levelTimer;//acts as the levels timer


	//ToolBar Sprites//
	sf::Sprite livesLeft;
	livesLeft.setTexture(*(Graphics::ptr().getTexture(13)));
	livesLeft.setPosition({ 0,0 });

	sf::Sprite bombsLeft;
	bombsLeft.setTexture(*(Graphics::ptr().getTexture(12)));
	bombsLeft.setPosition({ 115,0 });

	sf::Sprite gamePoints;
	gamePoints.setTexture(*(Graphics::ptr().getTexture(11)));
	gamePoints.setPosition({ 190,0 });

	sf::Sprite time;
	time.setTexture(*(Graphics::ptr().getTexture(10)));
	time.setPosition({ 295,0 });
	//End ofToolBar Sprites//

	//toolbar texts//
	sf::Text timeLeft;
	sf::Text bombs;
	sf::Text levelPoints;
	sf::Font font;
	font.loadFromFile("fonts/ALGER.TTF");
	timeLeft.setFont(font);
	bombs.setFont(font);
	levelPoints.setFont(font);
	timeLeft.setPosition({ 215, 0 });
	//end of tool bar texts//

	const int limit = timeLimit;//for viewing the limit.

	
	int explosionIndex = 0;


	setMap(lvlNum);//sets the objects on the map

	numOfGuards = m_guards.size();
	player.setFirstPosition(playerPosition);


	while (gameWindow.isOpen())
	{
		m_BackGround.setTexture(*(Graphics::ptr().getTexture(0)));
		gameWindow.clear();
		gameWindow.draw(m_BackGround); //background


		// handles events
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))//place a bomb
			{
				
				gameWindow.pollEvent(event);
				if (bombLimit > 0)
				{
					m_bombs.push_back(std::make_unique <Bomb> (player.spritePlayer().getPosition()));
					bombLimit--;
				}
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))//restart current level
			{
				gameWindow.pollEvent(event);
				restartLevel(bombLimit, timeLimit, levelTimer, lvlNum);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))//quit game
				exit(EXIT_SUCCESS);


			if (event.type == sf::Event::Closed)//closes window.
			{
				exit(EXIT_SUCCESS);
			}
		}

		player.move(gameWindow);//player movement

		guardMovement(gameWindow);//guard movement

		explosionHandler(explosionIndex, explosionLocation);//in case of explosion

		draw(gameWindow, m_exp.getStaticSprite());//draws the game objects
		
		toolBar(gameWindow, levelTimer, time, livesLeft, bombsLeft, gamePoints, bombs, levelPoints, timeLeft, timeLimit, bombLimit, points);

		if ((int)levelTimer.getElapsedTime().asSeconds() > timeLimit - 1 || !(player.ifAlive()))//restart the level if no time or killed
		{
			restartLevel(bombLimit, timeLimit, levelTimer, lvlNum);
		}

		livesLeft.setTexture(*(Graphics::ptr().getTexture(16 - player.HowManyLives())));//update lives texture.

		gameWindow.draw(time);

		checkDynamicCollide(points, numOfGuards);//handles collusions

		player.checkGift(timeLimit, bombLimit);//handles gifts

		if (player.checkWon())//checks if the player won
		{
			m_statics.clear();
			m_guards.clear();
			m_bombs.clear();
			player.resetLife();
			return;
		
		}


		int lives = player.HowManyLives();

		if (lives == 0)//if completely killed
		{
			gameWindow.close();
			if (m_screens.gameOver_window())
				player.resetLife();
		}
		gameWindow.display();

	}

}

//this function handles guard movement
void Controller::guardMovement(sf::RenderWindow &gameWindow)
{
	for (size_t i = 0; i < m_guards.size(); i++)
		m_guards[i].get()->guardMovement(player.spritePlayer().getPosition(), m_statics, gameWindow);//Polymorphism baby!!

}

//this function draws the objects on the current level
void Controller::draw(sf::RenderWindow & window, sf::Sprite explode)
{
	drawStatics(window);//draws the static objects

	for (size_t i = 0; i < m_bombs.size(); i++)
		m_bombs[i]->draw(window);

	for (size_t i = 0; i < m_guards.size(); i++)
	{
		m_guards[i]->draw(window);
	}

	if (m_boom)
		window.draw(explode);
		player.draw(window);
}

//this function draws the static objects
void Controller::drawStatics(sf::RenderWindow & window)
{
	for (size_t i = 0; i < m_statics.size(); i++)
		m_statics[i]->draw(window);//Polymorphism
	
}

//this function restarts the current level
void Controller::restartLevel(int & bombLimit, int & timeLimit, sf::Clock & levelTimer, int lvlNum)
{
	player.revive();
	player.setFirstPosition(playerPosition);
	m_guards.clear();
	m_statics.clear();
	m_bombs.clear();
	setMap(lvlNum);
	bombLimit = m_levels[lvlNum - 1].getBombLimit();
	timeLimit = m_levels[lvlNum - 1].getTimeLimit();
	levelTimer.restart();
	m_boom = false;
}

//this function check the collusions using Double dispatch
void Controller::checkDynamicCollide(int &points, int numOfGuards)
{
	//these are explosion rectangles that hold the explosion area
	sf::Rect widthRect(m_exp.getStaticSprite().getPosition().x + 33, m_exp.getStaticSprite().getPosition().y + 98, 190.f, 60.f);
	sf::Rect heightRect(m_exp.getStaticSprite().getPosition().x + 98, m_exp.getStaticSprite().getPosition().y + 33, 60.f, 190.f);

	//with Static Objects//
	for (size_t i = 0; i < m_statics.size(); i++)
	{
		if (m_statics[i]->getStaticSprite().getGlobalBounds().contains({ player.spritePlayer().getPosition().x + 15 , player.spritePlayer().getPosition().y + 10 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ player.spritePlayer().getPosition().x + 39, player.spritePlayer().getPosition().y + 55 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ player.spritePlayer().getPosition().x + 15, player.spritePlayer().getPosition().y + 55 }) ||
			m_statics[i]->getStaticSprite().getGlobalBounds().contains({ player.spritePlayer().getPosition().x + 39, player.spritePlayer().getPosition().y + 10 }))
		{
			m_statics[i]->collide(player);
			if (player.checkWon())
				points += 20 * numOfGuards;
			if (!m_statics[i]->isAlive())
			{
				m_statics.erase(m_statics.begin() + i);
			}
		}

		if (widthRect.intersects(player.spritePlayer().getGlobalBounds()) && m_boom)
		{	
			m_exp.collide(player);
		}

	}
	for (size_t i = 0; i < m_statics.size(); i++)
	{
		for (size_t j = 0; j < m_guards.size(); j++)
		{
			if (m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_guards[j]->getSprite().getPosition().x + 15 , m_guards[j]->getSprite().getPosition().y + 10 }) ||
				m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_guards[j]->getSprite().getPosition().x + 39, m_guards[j]->getSprite().getPosition().y + 55 }) ||
				m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_guards[j]->getSprite().getPosition().x + 15, m_guards[j]->getSprite().getPosition().y + 55 }) ||
				m_statics[i]->getStaticSprite().getGlobalBounds().contains({ m_guards[j]->getSprite().getPosition().x + 39, m_guards[j]->getSprite().getPosition().y + 10 }))
			{
				m_statics[i]->collide(*m_guards[j]);
				
			}
			if (m_guards[j]->getSprite().getGlobalBounds().intersects(player.spritePlayer().getGlobalBounds()))
				player.collide(*m_guards[j]);

			if (widthRect.intersects(m_guards[j]->getSprite().getGlobalBounds()) && m_boom)
			{
				m_exp.collide(*m_guards[j]);
				m_guards.erase(m_guards.begin() + j);
				points += numOfGuards * 5;
			}
		}

		if (widthRect.intersects(m_statics[i]->getStaticSprite().getGlobalBounds()) && m_boom)
		{
			m_exp.collide(*m_statics[i]);

			if (m_statics[i]->ifBreakable())
				m_statics.erase(m_statics.begin() + i);
		}
	}
}

//this function sets the guards in the level
void Controller::setGuard(sf::Vector2f location)
{
	int random;
	random = rand() % 6;//randomize if smart or stupid

	if (random % 2 == 0)
	{
		m_guards.push_back(std::make_unique <SmartGuard>());
	}
	else
	{
		m_guards.push_back(std::make_unique <StupidGuard>());
	}

	int size = m_guards.size() - 1;
	m_guards[size]->setPosition(location);
}

//this function handles the explosions
void Controller::explosionHandler(int & index, sf::Vector2f &location)
{
	for (size_t i = 0; i < m_bombs.size(); i++)
		if (m_bombs[i]->check())
		{
			location = { m_bombs[i]->getStaticSprite().getPosition().x - 95, m_bombs[i]->getStaticSprite().getPosition().y - 95 };
			m_exp.setLocation(location);
			m_boom = true;
			m_bombs.erase(m_bombs.begin() + i);
		
			index = 0;
			break;
		}
	m_exp.explosion(index, m_boom);
}

//this function draws and creates the tool bar
void Controller::toolBar(sf::RenderWindow &gameWindow, sf::Clock & levelTimer, sf::Sprite & time, sf::Sprite & livesLeft, sf::Sprite & bombsLeft, sf::Sprite & gamePoints, sf::Text & bombs, sf::Text & levelPoints, sf::Text & timeLeft, int timeLimit, int bombLimit, int &points)
{
	gameWindow.draw(livesLeft);
	gameWindow.draw(bombsLeft);
	bombs.setString(std::to_string(bombLimit));
	bombs.setPosition({ bombsLeft.getPosition().x + 43, 6 });
	gameWindow.draw(bombs);
	gameWindow.draw(gamePoints);
	levelPoints.setString(std::to_string(points));
	levelPoints.setPosition({ gamePoints.getPosition().x + 45, 6 });
	gameWindow.draw(levelPoints);
	gameWindow.draw(time);
	timeLeft.setString(std::to_string(timeLimit - (int)levelTimer.getElapsedTime().asSeconds()));
	timeLeft.setPosition({ time.getPosition().x + 43, 6 });
	gameWindow.draw(timeLeft);
}


Controller::~Controller()
{
	
}
