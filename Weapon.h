#pragma once
#include "VisibleGameObject.h"
#include "SolidGameObjects.h"
#include "Game.h"
#include "Player.h"

class Weapon : public VisibleGameObject {
public:
	Weapon();
	~Weapon();
	void Draw(sf::RenderWindow &window);
	void EquipLeft();
	void EquipRight();
	void setPosition(sf::Vector2f position, int dir);
private:
	bool isEquipedLeft;
	bool isEquipedRight;
};