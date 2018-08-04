#pragma once
#include "VisibleGameObject.h"

class SolidGameObject {
public:
	virtual bool isSolid(const sf::FloatRect &area) const = 0;
};





/*
class Trees : public VisibleGameObject{
public:
	Trees(Player *player);
	~Trees();
	static int TreeCount;
	void Draw(sf::RenderWindow & window);
	sf::Vector2f getRandomPosition(std::size_t x_range, std::size_t y_range);
    void GenerateTrees();
	Player * mPlayer;
	std::size_t xrand;
	std::size_t yrand;
private:
	sf::Texture oTexture;
	sf::Sprite oSprite[30];
};
class TreeTrunks : private Trees, public VisibleGameObject 
{
public:
	Player * mPlayer;
	TreeTrunks(Player * player) : Trees(player) {
		mPlayer = player;
		dpinetreeTexture.loadFromFile("deadpinetree.png");
		for (int i = 0; i < 30; ++i) {
			dpinetreeSprite[i].setTexture(dpinetreeTexture);
		}
	};
	~TreeTrunks();
	void Draw(sf::RenderWindow & window);
	sf::Vector2f getTreePosition(std::size_t x_range, std::size_t y_range);
	void GenerateTreeTrunks();
private:
	sf::Texture dpinetreeTexture;
	sf::Sprite dpinetreeSprite[30];
};*/