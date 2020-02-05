#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics();//this function constructs the object.
	static Graphics & ptr();//this function return a pointer to itself.
	sf::Texture* getTexture(int i);//this function returns a specific texture as a pointer.
	sf::Texture* getGift(char id);//this function returns the gift textures as pointers.

	~Graphics();
private:
	std::vector<std::string> m_files;//holds the files name.
	std::vector<sf::Texture> m_textures;//holds the textures.

};

