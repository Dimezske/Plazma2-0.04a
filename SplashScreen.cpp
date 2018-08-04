#include "StdAfx.h"
#include "SplashScreen.h"

using namespace std;

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture splashscreen_image;
	if (splashscreen_image.loadFromFile("Images\\Plazma.png") != true)
	{
		return;
	}

	sf::Sprite sprite(splashscreen_image);

	sf::Font font;
	sf::Font font2;
	if (!font.loadFromFile("Fonts\\TektonPro-BoldObl.otf"))
	{
		// error...
	}
	if (!font2.loadFromFile("Fonts\\arial.ttf"))
	{
		// error...
	}
	sf::Text text;
	sf::Text version;
	text.setFont(font);
	text.setString("Press any key to continue.");
	text.setCharacterSize(24);
	text.setPosition(600, 700);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	version.setFont(font2);
	version.setString("Version Alpha 00.4");
	version.setCharacterSize(14);
	version.setPosition(1230, 780);
	version.setFillColor(sf::Color::Green);
	version.setStyle(sf::Text::Bold);
	
	sf::Event event;
	sf::Clock gClock;
	bool elapsed = false;
	while (true)
	{
		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.draw(version);
		if (elapsed) { 
			renderWindow.draw(text);
			
		}     
		renderWindow.display();
		if (gClock.getElapsedTime().asSeconds() >= 3.0f) {
			elapsed = true;
		}

		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				
				return;
			}
		}
	}
}