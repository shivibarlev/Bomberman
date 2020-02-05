#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Screens
{
public:
	Screens();//this is a constructer for this object
	int startMenu_window();//this function handles the start menu
	void levelSelection(sf::RenderWindow &startWindow, int &level);//this function handles the level selection
	void Next_window();//this function sends the user to the next level
	bool Winner_window();//this function displays the winner window

	bool gameOver_window();//this function displays the loser window

	~Screens();
private:
	std::vector<std::string> m_files;//this vector holds the file names
	std::vector<sf::Texture> m_textures;//this vector holds the textures
	std::vector<sf::Sprite> m_sprites;//this vector holds the sprites used.
	int level;//holds the level number
};

