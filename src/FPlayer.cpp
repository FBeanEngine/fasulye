#include "FPlayer.h"

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
