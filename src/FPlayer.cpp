#include "FPlayer.h"
#include "raylib.h"
#include <iostream>

FPlayer::FPlayer(Vector2 position)
{
	this->position = position;
	m_hp = 100;
	m_activeGun = -1;
	isDead = false;
}

// FPlayer::FPlayer(Vector2 position, Texture texture){
// TODO
// }

 void FPlayer::Update() {
	bool isVerticalUp = false;
	bool isVerticalDown = false;

	if (IsKeyDown(KEY_W)) {
		this->position.y -= 5;
		isVerticalUp = true;
	}
	else if (IsKeyDown(KEY_S)) {
		this->position.y += 5;
		isVerticalDown = true;
	}

	if (IsKeyDown(KEY_A)) {
		if (isVerticalUp) { 
			this->position.x -= 2.5;
			this->position.y += 2.5;
		} else if (isVerticalDown) {
			this->position.x -= 2.5;
			this->position.y -= 2.5;
		}
		else
		this->position.x -= 5;
	}
	else if (IsKeyDown(KEY_D)) {
		if (isVerticalUp) { 
			this->position.x += 2.5;
			this->position.y += 2.5;
		} else if (isVerticalDown) {
			this->position.x += 2.5;
			this->position.y -= 2.5;
		}
		this->position.x += 5;
	}
}

void FPlayer::Draw() {
	std::cout<< "Draw call for player" << std::endl;
	DrawCircle(this->position.x, this->position.y, 50, RED);
}

void FPlayer::AddItem(FItem item)
{
	m_inventory.push_back(item);
}

void FPlayer::TakeDamage(int damage)
{
	m_hp -= damage;
	if (m_hp <= 0)
	{
		isDead = true;
	}
}

int FPlayer::GetHP()
{
	return m_hp;
}

int FPlayer::Attack()
{
	if (m_activeGun >= 0)
	{
		// TODO: change damage when guns added
		return 25;
	}
	return 0;
}
