#include "stdafx.h"
#include "Chatbox.h"
#include <iostream>
ChatBox::ChatBox()
{
	Load("Images\\ChatBox2.png");
	
	ChatBox_font.loadFromFile("Fonts\\arial.ttf");
	ChatBox_text.setFont(ChatBox_font);
	
	//setColor(sf::Color(255, 0, 255, 180));
	setColor(sf::Color(255, 255, 255, 180));
	setPosition(0, 775);
	setRenderSize(0, 0);

	setChatPosition(GetSprite().getPosition().x +5, GetSprite().getPosition().y);
	setChatTextSize(0);
	setChatColor(sf::Color(255, 255, 255, 255));

}



void ChatBox::setPosition(int x, int y)
{
	GetSprite().setPosition(x, y);
}
void ChatBox::setRenderSize(float w, float h)
{
	GetSprite().setScale(w, h);
}
void ChatBox::setColor(sf::Color color)
{
	GetSprite().setColor(color);
}


void ChatBox::setChatText(String text)
{
	ChatBox_text.setString(text);

}
String ChatBox::getChatText()
{
	return ChatBox_text.getString();
}
void ChatBox::setChatPosition(int x, int y)
{
	ChatBox_text.setPosition(x, y);
}

void ChatBox::setChatTextSize(float size)
{
	ChatBox_text.setCharacterSize(size);
}

void ChatBox::setChatColor(sf::Color color)
{
	ChatBox_text.setFillColor(color);
}

void ChatBox::Draw(RenderWindow &window)
{
	if (mChatVisible) {
		VisibleGameObject::Draw(window);
		window.draw(ChatBox_text);
	}
}
bool ChatBox::getTextBounds(const sf::FloatRect &textArea) const
{
	sf::FloatRect box;
	box.left = GetPosition().x + 10;
	box.top = GetPosition().y + 22;
	box.width = 10;
	box.height = 22;
	return box.intersects(textArea);
}
void ChatBox::handleClick(float x, float y)
{
	if (GetSprite().getGlobalBounds().intersects(sf::FloatRect(x, y, 0, 0)))
	{
		mTextVisible = true;
	}
}
//void ChatBox::handleEvent(sf::Event mouseEvent)
//{
//	if (mouseEvent.type == sf::Event::MouseButtonPressed)
//	{
//		return handleClick(mouseEvent.mouseButton.x, mouseEvent.mouseButton.y);
//	}
//}

void ChatBox::Toggle() {
	mChatVisible = !mChatVisible;
	if (mChatVisible)
	{
		setRenderSize(2, 1);
		setChatTextSize(16);
		playerInput = "";
		setChatText("");
	}
	if (!mChatVisible)
	{
		setRenderSize(0, 0);
		setChatTextSize(0);
		
	}
}
void ChatBox::Handle(const sf::Event &event)
{
	switch (event.type) {
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Tab)
		{
			std::cout << "Test" << std::endl;
			Toggle(); // not working
		}
		break;
	case sf::Event::TextEntered:
		if (mChatVisible) {
			if (event.text.unicode < 128 && event.text.unicode != '\t')
			{
				playerInput += event.text.unicode;
				ChatBox_text.setString(playerInput);
				ChatBox_text.setString(playerInput + "|");
				if (event.text.unicode == '\r')
				{
					playerInput = "";
					setChatText("");
				}
				if (event.text.unicode == 8)
				{
					if (playerInput.size() > 1)
						playerInput.resize(playerInput.size() - 2);
					setChatText(playerInput);
				}
			}
		}
		break;
	}
}

