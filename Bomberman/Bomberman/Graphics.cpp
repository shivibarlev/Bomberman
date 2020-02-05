#include "Graphics.h"


//this function constructs the object.
Graphics::Graphics()
{
	m_textures.resize(17);
	m_files.resize(17);

	//game background//
	m_files[0] = "images/screens/background.png";
	
	//GameObject Textures//
	m_files[1] = "images/dynamicObjects/playerSheets.png";
	m_files[2] = "images/dynamicObjects/guard.png";
	m_files[3] = "images/staticObjects/box.png";
	m_files[4] = "images/staticObjects/door.png";
	m_files[5] = "images/staticObjects/wall.png";
	m_files[6] = "images/staticObjects/bomb_sheet2.png";
	m_files[16] = "images/staticObjects/explosion.png";

	//gift textures//
	m_files[7] = "images/staticObjects/bombGift.png";
	m_files[8] = "images/staticObjects/lifeGift.png";
	m_files[9] = "images/staticObjects/timeGift.png";

	//ToolBar
	m_files[10] = "images/toolBar/Clock.png";
	m_files[11] = "images/toolBar/scores.png";
	m_files[12] = "images/toolBar/bombs.png";
	m_files[13] = "images/toolBar/1.png";
	m_files[14] = "images/toolBar/2.png";
	m_files[15] = "images/toolBar/3.png";


	for (size_t i = 0; i < m_textures.size(); i++)
		m_textures[i].loadFromFile(m_files[i]);			
}
//this function return a pointer to itself.
Graphics & Graphics::ptr()
{
	static Graphics ptr;
	return ptr;
}
//this function returns a specific texture as a pointer.
sf::Texture* Graphics::getTexture(int i)
{
		return &m_textures[i];
}
//this function returns the gift textures as pointers.
sf::Texture*  Graphics::getGift(char id)
{
	switch (id)
	{
	case 'B':
		return &m_textures[7];
	case 'L':
		return &m_textures[8];
	case 'T':
		return &m_textures[9];
	}
}




Graphics::~Graphics()
{

}
