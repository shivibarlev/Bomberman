#include "Level.h"


//this function builds the object
Level::Level(unsigned int num, std::vector<std::string> map, int width, int height, int bombs, int limit)
{
	m_timeLimit = limit;
	m_bombLimit = bombs;
	m_width = width;
	m_height = height;
	m_lvlNum = num;
	m_Map = map;
}

//this function returns the string map
std::vector<std::string> & Level::getMap()
{
	return m_Map;
}

//this function returns the bomb limit
int Level::getBombLimit()
{
	return m_bombLimit;
}

//this function returns the time limit
int Level::getTimeLimit()
{
	return m_timeLimit;
}


Level::~Level()
{
}
