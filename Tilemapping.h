#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "Game.h"

//extern int level[1000][1000];
extern std::vector<int> level;

class TileMapp {
public:
	void setLevel(int width, int height);
	void spawnLevel();
};