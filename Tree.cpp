#include "stdafx.h"
#include "Tree.h"
#include "GameObjectManager.h"
#include "Game.h"

Tree::Tree() {
	Load("Images\\deadpinetree.png");
	leavesTexture.loadFromFile("Images\\pinetree_leaves.png");
	leaves.setTexture(leavesTexture);
}
Tree::~Tree() {
}
void Tree::Draw(sf::RenderWindow & windowz)
{
	VisibleGameObject::Draw(windowz);
	Player* player = reinterpret_cast<Player*>(Game::GetGameObjectManager().Get("Player"));
	if (leaves.getGlobalBounds().intersects(player->GetBoundingRect()))
	{
		leaves.setColor(sf::Color(25, 122, 285, 80));
	}
	else if (!leaves.getGlobalBounds().intersects(player->GetBoundingRect()))
	{
		leaves.setColor(sf::Color(255, 255, 255, 255));
	}
	windowz.draw(leaves);
}
bool Tree::isSolid(const sf::FloatRect &area) const
{
	sf::FloatRect trunk;
	trunk.left = GetPosition().x + 130;
	trunk.top = GetPosition().y + 565;
	trunk.width = 25;
	trunk.height = 20;
	return trunk.intersects(area);
}