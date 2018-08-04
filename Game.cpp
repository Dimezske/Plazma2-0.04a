#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Tilemap.h"
#include "Tilemapping.h"
#include "Player.h"
#include "ServiceLocator.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "Topgui.h"
#include "TileEditor.h"
#include "Tree.h"
#include "Weapon.h"
#include "Chatbox.h"
#include "Terminal.h"

//int level[1000][1000] = {};
std::vector<int> level;
bool islevelset = false;

void Game::Start(void)
{

	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Plazma");
	//_mainWindow.setKeyRepeatEnabled(false);
	//_mainWindow.SetFramerateLimit(60);

	SFMLSoundProvider soundProvider;
	ServiceLocator::RegisterServiceLocator(&soundProvider);

	soundProvider.PlaySong("Sounds\\Plazmasplashsounds.ogg", true);
	
	_gameState = Game::ShowingSplash;

	TopGUI *Gui = new TopGUI();
	_gameObjectManagerGUI.Add("GUI", Gui);

	Terminal *terminal = new Terminal();
	_gameObjectManagerGUI.AddHandled(terminal);
	_gameObjectManagerGUI.Add("PlazmaTerminal", terminal);

	Player *player = new Player();
	player->SetPosition((WINDOW_WIDTH / 2) - 45, 400);
	_gameObjectManager.Add("Player", player);
	//Chat 
	ChatBox *chatbox = new ChatBox();
	_gameObjectManagerGUI.AddHandled(chatbox);
	_gameObjectManagerGUI.Add("ChatBox", chatbox);
	


	// Weapons
	Weapon *weapon = new Weapon();
	weapon->EquipRight();
	_gameObjectManager.Add("CombatKnife", weapon);

	// Objects
	Tree *pinetree = new Tree();
	_gameObjectManager.AddSolid(pinetree);
	_gameObjectManager.Add("Pinetree", pinetree);
	
	// TileSet
	TileMapp TILESET;
	TILESET.setLevel(1000,1000);
	mTileset.load("Images\\Grass0.png", sf::Vector2u(16, 16), level, 1000, 1000);

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}
sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	//_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}
GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}
float clamp(float value, float min, float max) {
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}
void Game::GameLoop()
{
	sf::Event currentEvent;
	bool hasEvent = _mainWindow.pollEvent(currentEvent);

	switch (_gameState)
	{
	case Game::ShowingMenu:
	{
		ShowMenu();
		break;
	}
	case Game::ShowingSplash:
	{
		ShowSplashScreen();
		break;
	}
	
	case Game::Playing:
	{
		TileEditor *OTE = new TileEditor();
		_mainWindow.clear(sf::Color(14, 17, 15));
		if (hasEvent) {
			_gameObjectManager.Handle(currentEvent);
			_gameObjectManagerGUI.Handle(currentEvent);
		}
		_gameObjectManager.UpdateAll();
		_gameObjectManagerGUI.UpdateAll();
		//_gameObjectManagerOTE.UpdateAll();

		sf::Vector2f pos = _gameObjectManager.Get("Player")->GetPosition();
		pos.x = clamp(pos.x, Game::WINDOW_WIDTH / 2, 16000 - Game::WINDOW_WIDTH / 2);
		pos.y = clamp(pos.y, Game::WINDOW_HEIGHT / 2, 16000 - Game::WINDOW_HEIGHT / 2);
		_mainWindow.setView({ pos,{ static_cast<float>(Game::WINDOW_WIDTH), static_cast<float>(Game::WINDOW_HEIGHT) } });
		
		_mainWindow.draw(mTileset); // <-- drawing the tileset here, before the objects
		_gameObjectManager.DrawAll(_mainWindow);

		_mainWindow.setView(_mainWindow.getDefaultView());
		_gameObjectManagerGUI.DrawAll(_mainWindow);
		//_gameObjectManagerOTE.DrawAll(_mainWindow);
		_mainWindow.display();

		if (!hasEvent)
			break;

		if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
			if (currentEvent.key.code == sf::Keyboard::F7)
			{
				std::cout << "Test" << std::endl;
				OTE->Show(_mainWindow);
			}
		}
		break;
	}
  }
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}
bool Game::SetDefaultTiles()
{
	
	return true;
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
GameObjectManager Game::_gameObjectManagerGUI;
//GameObjectManager Game::_gameObjectManagerOTE;
TileMap Game::mTileset;