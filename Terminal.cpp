#include "stdafx.h"
#include "Terminal.h"
#include <iostream>
/*This Class is for the Staff Terminal so Staff can enter commands to effect the server
	it will be a light blackish box with opacity and a black 1px outline with light green text
	commands will start with a '/' then enter the command name
	/help  - This shows all of the commands
	/add -name-  - This create a command with the desired name
	/rm -name- -This removes the user added commands, predefined commands cannot be deleted
	
	***PREDEFINED COMMANDS***
		/setlevelsize x,y    ;e.g /setlevelsize 100 100
		/makestaff -playername- (tag)
		/kickstaff -playername-
*/


Terminal::Terminal()
{
	Load("Images\\Terminal.png");
	
	Terminal_font.loadFromFile("Fonts\\arial.ttf");
	Terminal_text.setFont(Terminal_font);

	setColor(sf::Color(255, 20, 25, 200));
	setPosition(100, 300);
	setRenderSize(0.0, 0.0);
	
	setTerminalTextPosition(GetSprite().getPosition().x + 5, GetSprite().getPosition().y + 25);
	setTerminalTextSize(12.0);
	setTerminalTextColor(sf::Color(255, 155, 0, 255));

}



void Terminal::setPosition(float x, float y)
{
	GetSprite().setPosition(x, y);
}
void Terminal::setRenderSize(float w, float h)
{
	GetSprite().setScale(w, h);
}
void Terminal::setColor(sf::Color color)
{
	GetSprite().setColor(color);
}


void Terminal::setTerminalText(String text)
{
	Terminal_text.setString(text);

}
String Terminal::getTerminalText()
{
	return Terminal_text.getString();
}
void Terminal::setTerminalTextPosition(float x, float y)
{
	Terminal_text.setPosition(x, y);
}

void Terminal::setTerminalTextSize(float size)
{
	Terminal_text.setCharacterSize(size);
}

void Terminal::setTerminalTextColor(sf::Color color)
{
	Terminal_text.setFillColor(color);
}

void Terminal::Draw(RenderWindow &window)
{
	if (mTerminalVisible) {
		VisibleGameObject::Draw(window);
		window.draw(Terminal_text);
	}
}

bool Terminal::getTextBounds(const sf::FloatRect &textArea) const
{
	sf::FloatRect box;
	box.left = GetPosition().x + 10;
	box.top = GetPosition().y + 22;
	box.width = 10;
	box.height = 22;
	return box.intersects(textArea);
}

void Terminal::handleClick(float x, float y)
{
	if (GetSprite().getGlobalBounds().intersects(sf::FloatRect(x, y, 0, 0)))
	{
		mTerminalTextVisible = true;
	}
}

void Terminal::Toggle()
{
	mTerminalVisible = !mTerminalVisible;
	if (mTerminalVisible)
	{
		setRenderSize(1.0, 1.0);
		setTerminalTextSize(12.0);
		playerInput = "";
		setTerminalText("");
	}
	if (!mTerminalVisible)
	{
		setRenderSize(0.0, 0.0);
		setTerminalTextSize(0.0);
	}
}
void Terminal::Handle(const sf::Event &event)
{
	switch (event.type) {
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Tilde)
		{
			std::cout << "Test" << std::endl;
			Toggle();
		}
		break;
	case sf::Event::TextEntered:
		if (mTerminalVisible) {
			if (event.text.unicode < 128 && event.text.unicode != 96)
			{
				symbol = ">>::";
				playerInput += event.text.unicode;
				Terminal_text.setString(symbol + playerInput + "|");
				std::cout << playerInput << std::endl;
				if (event.text.unicode == '\r')
				{
					playerInput.clear();
					setTerminalText(symbol);
				}
				if (event.text.unicode == 8)
				{
					if (playerInput.size() > 1)
						playerInput.resize(playerInput.size() - 2);
					    setTerminalText(symbol + playerInput + (char)256u);
						if (playerInput.size() == 1)
							setTerminalText(symbol + playerInput);
				}
			}
		}
		break;
	}
}
void Terminal::Commands() 
{
	
}
