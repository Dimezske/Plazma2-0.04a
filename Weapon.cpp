#include "stdafx.h"
#include "Weapon.h"
#include "GameObjectManager.h"


Weapon::Weapon()
{
	Load("Images\\CombatKnife.png");
	assert(IsLoaded());
	GetSprite().setTextureRect(sf::IntRect(0, 0, 50, 50));
	
}
Weapon::~Weapon()
{

}
void Weapon::Draw(sf::RenderWindow &window)
{
	VisibleGameObject::Draw(window);
}
void Weapon::EquipLeft()
{

}
void Weapon::EquipRight()
{
	
}

void Weapon::setPosition(sf::Vector2f position, int dir)
{
	Player* player = reinterpret_cast<Player*>(Game::GetGameObjectManager().Get("Player"));
	if (dir == 0) {
		GetSprite().setTextureRect(sf::IntRect(0, 50, 50, 50));
		position.x -= 10;
		position.y += 15;
		GetSprite().setPosition(position);
	}
	if (dir == 1) {
		GetSprite().setTextureRect(sf::IntRect(0, 0, 50, 50));
		position.x += 10;
		position.y += 5;
		GetSprite().setPosition(position);
	}
	if (dir == 2) {
		GetSprite().setTextureRect(sf::IntRect(50, 0, 50, 50));
		position.x -= 10;
		position.y += 5;
		GetSprite().setPosition(position);
	}
	if (dir == 3) {
		GetSprite().setTextureRect(sf::IntRect(50, 50, 50, 50));
		position.x += 10;
		position.y += 5;
		GetSprite().setPosition(position);
	}
}