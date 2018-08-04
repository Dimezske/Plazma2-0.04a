#include "stdafx.h"

/*
// Pine Trees
int Trees::TreeCount;
Trees::Trees(Player *player) {
	mPlayer = player;
	oTexture.loadFromFile("pinetree1.png");
	for (int i = 0; i < 30; ++i) {
		oSprite[i].setTexture(oTexture);
	}
}

Trees::~Trees() {
}

void Trees::Draw(sf::RenderWindow & windowz)
{
	for (int i = 0; i < 30; ++i)
	{
		if (oSprite[i].getGlobalBounds().intersects(mPlayer->GetBoundingRect()))
		{
			oSprite[i].setColor(sf::Color(25, 122, 285, 80));
		}
		else if(!oSprite[i].getGlobalBounds().intersects(mPlayer->GetBoundingRect()))
		{
			oSprite[i].setColor(sf::Color(255, 255, 255, 255));
		}
		windowz.draw(oSprite[i]);
	}
}
sf::Vector2f Trees::getRandomPosition(std::size_t x_range, std::size_t y_range)
{
	return sf::Vector2f(rand() % x_range, rand() % y_range);
}

void Trees::GenerateTrees() {
	
	for (int i = 0; i < 30; ++i)
	{
		oSprite[i].setPosition(getRandomPosition(1500, 1500));
	}
}

// Pine Tree Trunks

TreeTrunks::~TreeTrunks() {
}
void TreeTrunks::Draw(sf::RenderWindow & window) 
{
	for (int i = 0; i < 30; ++i)
	{
		window.draw(dpinetreeSprite[i]);
	}
}
sf::Vector2f TreeTrunks::getTreePosition(std::size_t x_range, std::size_t y_range) {
	return sf::Vector2f(rand() % x_range, rand() % y_range);
}
void TreeTrunks::GenerateTreeTrunks()
{
	for (int i = 0; i < 30; ++i)
	{
		TreeCount = i;
		dpinetreeSprite[i].setPosition(getRandomPosition(1500, 1500));
	}
}

*/