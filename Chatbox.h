#pragma once
#include "VisibleGameObject.h"
#include "EventHandlingObject.h"
#include "Game.h"

using namespace sf;

class ChatBox : public VisibleGameObject, public EventHandlingObject  {
public:
	ChatBox();
	void setPosition(int x, int y);
	void setRenderSize(float w, float h);
	void setColor(sf::Color color);

	void setChatText(String text);
	String getChatText();
	void setChatPosition(int x, int y);
	void setChatTextSize(float size);
	void setChatColor(sf::Color color);

	bool getTextBounds(const sf::FloatRect &area) const;
	//void handleEvent(sf::Event mouseEvent);
	void handleClick(float x, float y);

	void Draw(RenderWindow &window);
	void Toggle();
	void Handle(const sf::Event &event);
	
private:
	Texture t_chatBox;
	Sprite  s_chatBox;
	
	std::string playerInput;
	Font ChatBox_font;
	Text ChatBox_text;

	String str;
	bool mTextVisible = false;
	bool mChatVisible = false;
};