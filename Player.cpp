#include "stdafx.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "Weapon.h"
#include "Chatbox.h"
using namespace std;

sf::Sound footsteps;
sf::SoundBuffer footstepsBuffer;


Player::Player()
{
	Load("Images\\Character1.png");
	assert(IsLoaded());
	GetSprite().setTextureRect(sf::IntRect(50, 0, 50, 50));
	footstepsBuffer.loadFromFile("Sounds\\footstep02.wav");
	footsteps.setBuffer(footstepsBuffer);

	mWeapon = new Weapon();
	Game::GetGameObjectManager().Add("PlayerWeapon", mWeapon);
}

Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & window) {
	VisibleGameObject::Draw(window);
}

float Player::GetVelocity() const
{
	return _velocity;
}

int Player::Dir(int dir)
{
	if (dir == 0) { // Down
		const sf::IntRect walkingAnimationDown_idle(50, 0, 50, 50);
		GetSprite().setTextureRect(walkingAnimationDown_idle);
	}
	if (dir == 1) { // Right
		const sf::IntRect walkingAnimationRight_idle(50, 50, 50, 50);
		GetSprite().setTextureRect(walkingAnimationRight_idle);
	}
	if (dir == 2) { // Left
		const sf::IntRect walkingAnimationLeft_idle(50, 100, 50, 50);
		GetSprite().setTextureRect(walkingAnimationLeft_idle);
	}
	if (dir == 3) { // Up
		const sf::IntRect walkingAnimationUp_idle(50, 150, 50, 50);
		GetSprite().setTextureRect(walkingAnimationUp_idle);
	}
	return dir;
}

// Player Animation DOWN
void Player::playerAnimation_WalkDown()
{
	Dir(0);
	auto elapsedTime = mClock.getElapsedTime().asSeconds();

	const sf::IntRect walkingAnimationDown_idle(50, 0, 50, 50);
	const sf::IntRect walkingAnimationDown1(0, 0, 50, 50);
	const sf::IntRect walkingAnimationDown2(100, 0, 50, 50);
	

	if (elapsedTime < 0.2f) {
		GetSprite().setTextureRect(walkingAnimationDown_idle);
	}
	else if (elapsedTime < 0.3f) {
		GetSprite().setTextureRect(walkingAnimationDown2);
	}
	else if (elapsedTime < 0.4f) {
		GetSprite().setTextureRect(walkingAnimationDown_idle);
	}
	else if (elapsedTime < 0.5f) {
		GetSprite().setTextureRect(walkingAnimationDown1);
	}
	else if (elapsedTime > 0.5f) {
		mClock.restart();
	}
}

// Player Animation RIGHT
void Player::playerAnimation_WalkRight()
{
	Dir(1);
	auto elapsedTime = mClock.getElapsedTime().asSeconds();

	const sf::IntRect walkingAnimationRight_idle(50, 50, 50, 50);
	const sf::IntRect walkingAnimationRight1(0, 50, 50, 50);
	const sf::IntRect walkingAnimationRight2(100, 50, 50, 50);

	if (elapsedTime < 0.2f) {
		GetSprite().setTextureRect(walkingAnimationRight_idle);
	}
	else if (elapsedTime < 0.3f) {
		GetSprite().setTextureRect(walkingAnimationRight2);
	}
	else if (elapsedTime < 0.4f) {
		GetSprite().setTextureRect(walkingAnimationRight_idle);
	}
	else if (elapsedTime < 0.5f) {
		GetSprite().setTextureRect(walkingAnimationRight1);
	}
	else if (elapsedTime > 0.5f) {
		mClock.restart();
	}
}
// Player Animation LEFT
void Player::playerAnimation_WalkLeft()
{
	Dir(2);
	auto elapsedTime = mClock.getElapsedTime().asSeconds();

	const sf::IntRect walkingAnimationLeft_idle(50, 100, 50, 50);
	const sf::IntRect walkingAnimationLeft1(0, 100, 50, 50);
	const sf::IntRect walkingAnimationLeft2(100, 100, 50, 50);

	if (elapsedTime < 0.2f) {
		GetSprite().setTextureRect(walkingAnimationLeft_idle);
	}
	else if (elapsedTime < 0.3f) {
		GetSprite().setTextureRect(walkingAnimationLeft2);
	}
	else if (elapsedTime < 0.4f) {
		GetSprite().setTextureRect(walkingAnimationLeft_idle);
	}
	else if (elapsedTime < 0.5f) {
		GetSprite().setTextureRect(walkingAnimationLeft1);
	}
	else if (elapsedTime > 0.5f) {
		mClock.restart();
	}
}
// Player Animation UP
void Player::playerAnimation_WalkUp()
{
	Dir(3);
	auto elapsedTime = mClock.getElapsedTime().asSeconds();

	const sf::IntRect walkingAnimationUp_idle(50, 150, 50, 50);
	const sf::IntRect walkingAnimationUp1(0, 150, 50, 50);
	const sf::IntRect walkingAnimationUp2(100, 150, 50, 50);

	if (elapsedTime < 0.2f) {
		GetSprite().setTextureRect(walkingAnimationUp_idle);
	}
	else if (elapsedTime < 0.3f) {
		GetSprite().setTextureRect(walkingAnimationUp2);
	}
	else if (elapsedTime < 0.4f) {
		GetSprite().setTextureRect(walkingAnimationUp_idle);
	}
	else if (elapsedTime < 0.5f) {
		GetSprite().setTextureRect(walkingAnimationUp1);
	}
	else if (elapsedTime > 0.5f) {
		mClock.restart();
	}
}
void Player::Update(float elapsedTimer)
{
	int dir = -1;
	float speed = 1.50f;
	sf::Time frameTime = frameClock.restart();
	// if a key was pressed set the correct animation and move correctly
	sf::Vector2f movement(0.f, 0.f);
	sf::Vector2f oldPosition = GetSprite().getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		speed = 3.20f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mMoving = true;
		dir = 2;
			playerAnimation_WalkLeft();
			movement.x += speed;
			GetSprite().move(-movement.x, 0);

			mTime2 = mClock2.getElapsedTime();
			if (mClock2.getElapsedTime().asSeconds() >= .2f)
			{
				footsteps.play();
				mClock2.restart();
			}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mMoving = true;
		dir = 1;
			playerAnimation_WalkRight();
			movement.x += speed;
			GetSprite().move(movement.x, 0);

			mTime2 = mClock2.getElapsedTime();
			if (mClock2.getElapsedTime().asSeconds() >= .2f)
			{
				footsteps.play();
				mClock2.restart();
			}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mMoving = true;
		dir = 3;
			playerAnimation_WalkUp();
			movement.y += speed;
			
			GetSprite().move(0, -movement.y);
			mTime2 = mClock2.getElapsedTime();
			if (mClock2.getElapsedTime().asSeconds() >= .2f)
			{
				footsteps.play();
				mClock2.restart();
			}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		mMoving = true;
		dir = 0;
			playerAnimation_WalkDown();
			movement.y += speed;
			GetSprite().move(0, movement.y);
			
			mTime2 = mClock2.getElapsedTime();
			if (mClock2.getElapsedTime().asSeconds() >= .2f)
			{
				footsteps.play();
				mClock2.restart();
			}
	}
	sf::Vector2f newPosition = GetSprite().getPosition();
	if (oldPosition != newPosition) {
		sf::FloatRect rect;
		rect.left = newPosition.x;
		rect.top = newPosition.y + GetHeight() * 2 / 3;
		rect.width = GetWidth();
		rect.height = GetHeight() / 3;
		if (Game::GetGameObjectManager().isSolid(rect)) {
			GetSprite().setPosition(oldPosition);
		}
		mWeapon->setPosition(GetSprite().getPosition(),dir);
	}
}
Player::PlayerControlState Player::_playerControls = Walking;