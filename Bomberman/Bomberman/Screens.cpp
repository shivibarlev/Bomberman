#include "Screens.h"


//this function builds the object
Screens::Screens()
{
	m_files.resize(11);
	m_textures.resize(11);
	m_sprites.resize(11);

	m_files[0] = "images/screens/startPage.png";
	m_files[1] = "images/screens/play.png";
	m_files[2] = "images/screens/Exit.png";
	m_files[3] = "images/screens/Lvl1.png";
	m_files[4] = "images/screens/Lvl2.png";
	m_files[9] = "images/screens/Lvl3.png";
	m_files[10] = "images/screens/Lvl4.png";

	m_files[5] = "images/screens/gameover.png";
	m_files[6] = "images/screens/again.png";

	m_files[7] = "images/screens/nextlevel.png";
	m_files[8] = "images/screens/winnerscreen.png";


	for (size_t i = 0; i < m_textures.size(); i++)
		m_textures[i].loadFromFile(m_files[i]);

	for (size_t i = 0; i < m_sprites.size(); i++)
		m_sprites[i].setTexture(m_textures[i]);

}

//this function handles the start menu
int Screens::startMenu_window()
{
	sf::RenderWindow startWindow(sf::VideoMode(960, 640), "Start Menu");
	while (startWindow.isOpen())
	{
		int level;
		startWindow.clear();
		startWindow.draw(m_sprites[START]);
		m_sprites[PLAY].setPosition({ (float)355,(float)400 });
		m_sprites[EXIT].setPosition({ (float)355,(float)495 });
		startWindow.draw(m_sprites[PLAY]);
		startWindow.draw(m_sprites[EXIT]);

		sf::Event event1;
		while (startWindow.pollEvent(event1))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				levelSelection(startWindow, level);
				return level;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				exit(EXIT_SUCCESS);


			if (m_sprites[PLAY].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)))
			{
				m_sprites[PLAY].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					startWindow.pollEvent(event1);
					levelSelection(startWindow, level);//select the desired level
					return level;
				}
			}
			else
				m_sprites[PLAY].setColor(sf::Color::White);

			if (m_sprites[EXIT].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)))
			{
				m_sprites[EXIT].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					exit(EXIT_SUCCESS);
			}
			else
				m_sprites[EXIT].setColor(sf::Color::White);

			if (event1.type == sf::Event::Closed)//closes window.
				exit(EXIT_SUCCESS);
		}

		startWindow.display();
	}

}

//this function selects the level from the user
void Screens::levelSelection(sf::RenderWindow &startWindow, int &level)
{
	while (startWindow.isOpen())
	{
		startWindow.clear();
		startWindow.draw(m_sprites[START]);
		m_sprites[LEVEL_ONE].setPosition({ (float)325,(float)300 });
		m_sprites[LEVEL_TWO].setPosition({ (float)480,(float)300 });
		m_sprites[LEVEL_THREE].setPosition({ (float)325,(float)450 });
		m_sprites[LEVEL_FOUR].setPosition({ (float)480,(float)450 });
		startWindow.draw(m_sprites[LEVEL_ONE]);
		startWindow.draw(m_sprites[LEVEL_TWO]);
		startWindow.draw(m_sprites[LEVEL_THREE]);
		startWindow.draw(m_sprites[LEVEL_FOUR]);

		sf::Event event1;
		while (startWindow.pollEvent(event1))
		{
			//select with mouse
			if (m_sprites[LEVEL_ONE].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				m_sprites[LEVEL_ONE].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					level = 1;
					startWindow.close();
				}
			}
			else
				m_sprites[LEVEL_ONE].setColor(sf::Color::White);

			if (m_sprites[LEVEL_TWO].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)))
			{
				m_sprites[LEVEL_TWO].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					level = 2;
					startWindow.close();
				}
			}
			else
				m_sprites[LEVEL_TWO].setColor(sf::Color::White);

			if (m_sprites[LEVEL_THREE].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)))
			{
				m_sprites[LEVEL_THREE].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					level = 3;
					startWindow.close();
				}
			}
			else
				m_sprites[LEVEL_THREE].setColor(sf::Color::White);
			if (m_sprites[LEVEL_FOUR].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(startWindow)))
			{
				m_sprites[LEVEL_FOUR].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					level = 4;
					startWindow.close();
				}
			}
			else
				m_sprites[LEVEL_FOUR].setColor(sf::Color::White);


			//select with keyboard
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				level = 1;
				startWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				level = 2;
				startWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				level = 3;
				startWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				level = 4;
				startWindow.close();
			}

			if (event1.type == sf::Event::Closed)//closes window.
				exit(EXIT_SUCCESS);
		}

		startWindow.display();
	}
}


//this functio handles the loser window
bool Screens::gameOver_window()
{
	sf::RenderWindow gOverWindow(sf::VideoMode(960, 640), "Game Over");
	while (gOverWindow.isOpen())
	{
		gOverWindow.clear();
		gOverWindow.draw(m_sprites[GAMEOVER]);
		m_sprites[AGAIN].setPosition({ (float)355,(float)400 });
		m_sprites[EXIT].setPosition({ (float)355,(float)495 });
		gOverWindow.draw(m_sprites[AGAIN]);
		gOverWindow.draw(m_sprites[EXIT]);

		//	startWindow.display();

		sf::Event event1;
		while (gOverWindow.pollEvent(event1))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				exit(EXIT_SUCCESS);


			if (m_sprites[AGAIN].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(gOverWindow)))
			{
				m_sprites[AGAIN].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					return true;
				}
			}
			else
				m_sprites[AGAIN].setColor(sf::Color::White);

			if (m_sprites[EXIT].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(gOverWindow)))
			{
				m_sprites[EXIT].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					exit(EXIT_SUCCESS);
			}
			else
				m_sprites[EXIT].setColor(sf::Color::White);

			if (event1.type == sf::Event::Closed)//closes window.
				exit(EXIT_SUCCESS);
		}

		gOverWindow.display();
	}
}

//this function moves the user to the next level
void Screens::Next_window()
{
	sf::Clock Timer;

	sf::RenderWindow nextlevelWindow(sf::VideoMode(960, 640), "Next Level");
	while (nextlevelWindow.isOpen())
	{
		nextlevelWindow.clear();
		nextlevelWindow.draw(m_sprites[NEXTLEVEL]);
		nextlevelWindow.display();

		if (Timer.getElapsedTime().asSeconds() > 5)
			nextlevelWindow.close();
	}

}

//this is the winner screen
bool Screens::Winner_window()
{
	sf::RenderWindow winnerWindow(sf::VideoMode(960, 640), "YOU WON!");
	while (winnerWindow.isOpen())
	{
		winnerWindow.clear();
		winnerWindow.draw(m_sprites[WINNER]);
		m_sprites[AGAIN].setPosition({ (float)300,(float)400 });
		m_sprites[EXIT].setPosition({ (float)300,(float)495 });
		winnerWindow.draw(m_sprites[AGAIN]);
		winnerWindow.draw(m_sprites[EXIT]);


		sf::Event event1;
		while (winnerWindow.pollEvent(event1))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				exit(EXIT_SUCCESS);


			if (m_sprites[AGAIN].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(winnerWindow)))
			{
				m_sprites[AGAIN].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					return true;
				}
			}
			else
				m_sprites[AGAIN].setColor(sf::Color::White);

			if (m_sprites[EXIT].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(winnerWindow)))
			{
				m_sprites[EXIT].setColor(sf::Color(255, 255, 255, 200));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					exit(EXIT_SUCCESS);
			}
			else
				m_sprites[EXIT].setColor(sf::Color::White);

			if (event1.type == sf::Event::Closed)//closes window.
				exit(EXIT_SUCCESS);
		}

		winnerWindow.display();
	}
}





Screens::~Screens()
{
}
