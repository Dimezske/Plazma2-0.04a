#include "stdafx.h"
#include <algorithm>
#include "GameObjectManager.h"
#include "VisibleGameObject.h"
#include "SolidGameObjects.h"
#include "EventHandlingObject.h"
#include "Game.h"


class SolidGameObject;


GameObjectManager::GameObjectManager() 
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::AddSolid(SolidGameObject *object)
{
	mSolids.insert(object);
}
void GameObjectManager::AddHandled(EventHandlingObject *event)
{
	mEvents.insert(event);
}
void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		mSolids.erase(reinterpret_cast<SolidGameObject*>(results->second));
		mEvents.erase(reinterpret_cast<EventHandlingObject*>(results->second));
		delete results->second;
		_gameObjects.erase(results);
	}

}
bool GameObjectManager::isSolid(const sf::FloatRect &rect) const {
	sf::FloatRect levelBounds{ rect.width - 15, rect.height + 5, 16000 - rect.width - 18, 16000 - rect.height - 15 };
	if (!levelBounds.intersects(rect))
		return true;

	for (const auto &p : mSolids) {
		if (p->isSolid(rect)) {
			return true;
		}
	}
	return false;
}
void GameObjectManager::Handle(sf::Event event) {
	for (auto eho : mEvents)
		eho->Handle(event);
}
VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;

}

int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::vector<VisibleGameObject*> objects;
	for (const auto &p : _gameObjects)
		objects.push_back(p.second);

	std::sort(objects.begin(), objects.end(), [](const VisibleGameObject *left, const VisibleGameObject *right) {
		return left->GetPosition().y + left->GetHeight() < right->GetPosition().y + right->GetHeight();
	});

	for (const auto p : objects) {
		p->Draw(renderWindow);
	}
}
void GameObjectManager::UpdateAll()
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while (itr != _gameObjects.end())
	{
		itr->second->Update(timeDelta);
		itr++;
	}


}