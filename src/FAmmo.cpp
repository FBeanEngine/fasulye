#include "FAmmo.h"
#include "utils.h"
#include <cmath>

FAmmo::FAmmo(Vector2 position, Vector2 target, int damage, int range, int bulletSpeed, Texture2D texture)
{
	m_position = position;
	m_target = target;
	m_damage = damage;
	m_range = range;
	m_bulletSpeed = bulletSpeed;
	m_texture = texture;
	isDestroyed = false;

	Vector2 direction = {m_target.x - m_position.x, m_target.y - m_position.y};
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	m_target = {direction.x / length, direction.y / length};
}

FAmmo::~FAmmo()
{
	TraceLog(LOG_INFO, "FAmmo destroyed");
}

void FAmmo::Update(float dt)
{
	m_position.x += m_target.x * m_bulletSpeed * dt * 10;
	m_position.y += m_target.y * m_bulletSpeed * dt * 10;
	m_range -= m_bulletSpeed * dt;
	if (m_range <= 0)
	{
		isDestroyed = true;
		// UnloadTexture(m_texture);
	}
}

void FAmmo::Draw(float dt)
{
	DrawTextureEx(m_texture, m_position, 0, 3, WHITE);
}
