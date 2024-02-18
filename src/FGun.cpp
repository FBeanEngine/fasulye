#include "FGun.h"

FGun::FGun()
{
	m_position = {0, 0};
	m_rotation = 0;
	m_fireRate = 1;
}

void FGun::Shoot(Vector2 target)
{
	m_ammos.push_back(FAmmo(m_position, target, 1, 200, 1, LoadTexture("resources/assets/ammo.png")));
}

void FGun::Update(Vector2 position, float dt)
{
	m_position = {position.x + 60, position.y + 36};
	for (size_t i = 0; i < m_ammos.size(); i++)
	{
		m_ammos[i].Update(dt);
		if (m_ammos[i].isDestroyed)
		{
			m_ammos.erase(m_ammos.begin() + i);
		}
	}
}

void FGun::Draw(float dt)
{
	DrawTextureEx(m_texture, m_position, m_rotation, 1.5, WHITE);
	for (size_t i = 0; i < m_ammos.size(); i++)
	{
		m_ammos[i].Draw();
	}
}

void FGun::SetPosition(Vector2 position)
{
	m_position = position;
}

void FGun::SetRotation(float rotation)
{
	m_rotation = rotation;
}

void FGun::SetTexture(Texture2D texture)
{
	m_texture = texture;
}

void FGun::SetFireRate(int fireRate)
{
	m_fireRate = fireRate;
}
