#pragma once
#include "VisibleGameObject.h"
#include "SolidGameObjects.h"
#include "Player.h"

class Tree : public VisibleGameObject, public SolidGameObject {
public:
	Tree();
	virtual ~Tree();
	void Draw(sf::RenderWindow & windowz);
	virtual bool isSolid(const sf::FloatRect &area) const;
private:
	sf::Texture leavesTexture;
	sf::Sprite leaves;
};