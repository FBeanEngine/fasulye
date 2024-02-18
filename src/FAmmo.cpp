#include "FAmmo.h"
#include "utils.h"

FAmmo::FAmmo(Vector2 position, Vector2 target, int damage, int range, int bulletSpeed, Texture2D texture)
{
	m_position = position;
	m_target = target;
	m_damage = damage;
	m_range = range;
	m_bulletSpeed = bulletSpeed;
	m_texture = texture;
	isDestroyed = false;
}

void FAmmo::Update(float dt)
{
	m_position = LerpVector2(m_position, m_target, m_bulletSpeed * dt);
	Vector2 distance = Vector2Distance(m_position, m_target);
	if (distance.x < 10 && distance.y < 10)
	{
		isDestroyed = true;
	}
}

void FAmmo::Draw()
{
	DrawTextureEx(m_texture, m_position, 0, 3, WHITE);
}
