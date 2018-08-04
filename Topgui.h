#pragma once
#include "VisibleGameObject.h"
class TopGUI : public VisibleGameObject{
public:
	TopGUI();
	~TopGUI();
	void Draw(sf::RenderWindow &window);
	void setView();
	void displayTime();
	void displayExp();
private:
	sf::View m_hudView;
	sf::Texture GUITEXTURE;
	sf::Sprite GUI;
	sf::Time serverTime;
	sf::Clock serverClock;
};