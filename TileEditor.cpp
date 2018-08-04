#include "stdafx.h"
#include "TileEditor.h"
#include "Game.h"

TileEditor::TileEditor()
{
	box.setSize(sf::Vector2f(200, 200));
	box.setFillColor(sf::Color(125, 125, 125, 125));
	box.setOutlineColor(sf::Color(185, 185, 185, 185));
	box.setOutlineThickness(3.0);
	box.setPosition(1197, 597);
}
TileEditor::~TileEditor()
{

}
void TileEditor::Draw(sf::RenderWindow &window)
{
	window.draw(box);
	window.display();
}
void TileEditor::Show(sf::RenderWindow &window)
{
	bool isOpen = true;
	while (isOpen)
	{
		Draw(window);
	}
}
void TileEditor::Hide(sf::RenderWindow &window)
{

}