#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
#include "Tilemapping.h"

class VisibleGameObject;
class SolidGameObject;
class TileMap;

class Game
{
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static sf::Event& GetInput();
	static GameObjectManager& GetGameObjectManager();
	
	const static int WINDOW_WIDTH = 1400;
	const static int WINDOW_HEIGHT = 800;

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

private:
	sf::Clock mTimer;
	static TileMap mTileset;
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	static bool SetDefaultTiles();

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
	static GameObjectManager _gameObjectManagerGUI;
	//static GameObjectManager _gameObjectManagerOTE;
};