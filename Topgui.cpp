#include "stdafx.h"
#include "Topgui.h"
#include "Player.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "VisibleGameObject.h"



TopGUI::TopGUI()
{
	Load("Images\\GUI2.png");
	GetSprite().setPosition(0, 0);
	GetSprite().setColor(sf::Color(255, 255, 255, 180));
}
TopGUI::~TopGUI()
{

}
void TopGUI::Draw(sf::RenderWindow &window)
{
	m_hudView.reset(sf::FloatRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT));
	window.setView(m_hudView);
	VisibleGameObject::Draw(window);
}

void TopGUI::setView()
{
	
}
void TopGUI::displayTime()
{

}
void TopGUI::displayExp()
{

}