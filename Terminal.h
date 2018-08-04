#pragma once
#include "VisibleGameObject.h"
#include "EventHandlingObject.h"
#include "Game.h"

using namespace sf;

class Terminal : public VisibleGameObject, public EventHandlingObject {
public:
	Terminal();
	void setPosition(float x, float y);
	void setRenderSize(float w, float h);
	void setColor(sf::Color color);

	void setTerminalText(String text);
	String getTerminalText();
	void setTerminalTextPosition(float x, float y);
	void setTerminalTextSize(float size);
	void setTerminalTextColor(sf::Color color);

	bool getTextBounds(const sf::FloatRect &area) const;
	void handleClick(float x, float y);

	void Draw(RenderWindow &window);
	void Toggle();
	void Handle(const sf::Event &event);
	void Commands();
private:
	sf::RectangleShape terminalBox;

	Texture t_TerminalBox;
	Sprite  s_TerminalBox;

	std::string playerInput;
	std::string symbol;
	Font Terminal_font;
	Text Terminal_text;

	String str;
	bool mTerminalTextVisible = false;
	bool mTerminalVisible = false;

};