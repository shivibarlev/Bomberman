#pragma once
#include <vector>
#include <fstream>
#include <ostream>


class Level
{
public:
	Level(unsigned int num, std::vector<std::string> map, int width, int height, int bombs, int limit);//this function builds the object
	std::vector<std::string>& getMap();//this function returns the map as a string vector
	int getBombLimit();//this function returns the bomb limit.
	int getTimeLimit();//this function returns the time limit
	~Level();
private:
	std::vector<std::string> m_Map;//holds the map
	int m_lvlNum;//holds the level number
	int m_timeLimit;//holds time limit
	int m_bombLimit;//holds bomb limit
	int m_width;//holds width
	int m_height;//holds height
};

