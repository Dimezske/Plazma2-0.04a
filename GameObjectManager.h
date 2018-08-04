#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <set>

class VisibleGameObject;
class SolidGameObject;
class EventHandlingObject;

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	bool isSolid(const sf::FloatRect &rect) const;

	void Add(std::string name, VisibleGameObject* gameObject);
	void AddSolid(SolidGameObject* gameObject);
	void AddHandled(EventHandlingObject *event);
	void Handle(sf::Event event);
	void Remove(std::string name);
	int GetObjectCount() const;
	
	VisibleGameObject* Get(std::string name) const;
	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;
	std::set<SolidGameObject*> mSolids;
	std::set<EventHandlingObject*> mEvents;
	sf::Clock clock;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};
};