#pragma once

class TextManagerObject {
public:
	std::vector<sf::Text*> TextHistory;
public:
	sf::Font mNewFont;
	sf::Text mNewText;
};