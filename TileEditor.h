#pragma once
#include "VisibleGameObject.h"
#include "Game.h"

class TileEditor : public VisibleGameObject {
public:
	TileEditor();
	~TileEditor();
	void Draw(sf::RenderWindow &window);
	void Show(sf::RenderWindow &window);
	void Hide(sf::RenderWindow &window);

private:
	sf::RectangleShape box;
};