#include "FAmmo.h"
#include "FUtils.h"
#include <cmath>
#include <iostream>

FAmmo::FAmmo(Vector2 position, Vector2 target, int damage, int range, int bulletSpeed, Texture2D texture)
{
	m_position = position;
	m_target = target;
	m_damage = damage;
	m_range = range;
	m_bulletSpeed = bulletSpeed;
	m_texture = texture;

	tag = "ammo";
	SetBoundingBox(m_position.x, m_position.y, m_texture.width * 1.5, m_texture.height * 1.5);
	ActivateBoundingBox();

	Vector2 direction = {m_target.x - m_position.x, m_target.y - m_position.y};
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	m_target = {direction.x / length, direction.y / length};
}

FAmmo::~FAmmo()
{
	std::cout << "FAmmo::~FAmmo()" << std::endl;
	UnloadTexture(m_texture);
}

void FAmmo::Update(float dt)
{
	boundingBox.x = m_position.x;
	boundingBox.y = m_position.y;

	m_position.x += m_target.x * m_bulletSpeed * dt * 10;
	m_position.y += m_target.y * m_bulletSpeed * dt * 10;
	m_range -= m_bulletSpeed * dt;
	if (m_range <= 0)
	{
		isDestroyed = true;
	}
}

void FAmmo::Draw(float dt)
{
	DrawTextureEx(m_texture, m_position, 0, 1.5, WHITE);
}

void FAmmo::Physics(std::string tag, Rectangle collisionBox)
{
	if (tag == "item")
	{
		isDestroyed = true;
	}
}