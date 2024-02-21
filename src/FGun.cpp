#include "FGun.h"
#include "FSceneManager.h"
#include "FInputManager.h"

FGun::FGun()
{
	TraceLog(LOG_INFO, "FGun::FGun()");
	m_position = {0, 0};
	m_rotation = 0;
	m_fireRate = 1;
}

FGun::~FGun()
{
	TraceLog(LOG_INFO, "FGun::~FGun()");
}

void FGun::Shoot(Vector2 target)
{
	std::unique_ptr<FAmmo> ammo(new FAmmo(m_position, target, 1, 75, 100, LoadTexture("resources/assets/ammo.png")));
	FSceneManager::AddObjectToActiveScene(std::move(ammo));
}

void FGun::Update(float dt)
{
	// for (size_t i = 0; i < m_ammos.size(); i++)
	// {
	// 	m_ammos[i]->Update(dt);
	// 	if (m_ammos[i]->isDestroyed)
	// 	{
	// 		m_ammos.erase(m_ammos.begin() + i);
	// 	}
	// }
	m_position = m_owner->position;
	Vector2 movementVector = FInputManager::GetMovementVector();
	Vector2 aimVector = FInputManager::GetAimVector(m_position);
	PerformedAction action = FInputManager::GetPerfomedAction();
	if (action == PerformedAction::LeftHandUse)
	{
		// animation.BindAnimation("shoot");
		Shoot(m_mousePosition);
	}
}

void FGun::Draw(float dt)
{
	// DrawTextureEx(m_texture, m_position, m_rotation, 5, WHITE);
	// for (size_t i = 0; i < m_ammos.size(); i++)
	// {
	// 	m_ammos[i]->Draw();
	// }
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

void FGun::SetOwner(FObject *const owner)
{
	m_owner = owner;
}