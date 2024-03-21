#include "FGun.h"
#include "FSceneManager.h"
#include "FInputManager.h"
#include <iostream>

FGun::FGun()
{
	TraceLog(LOG_INFO, "FGun::FGun()");
	m_position = {0, 0};
	m_rotation = 0;
	m_fireRate = 1;
}

FGun::~FGun()
{
	std::cout << "FGun::~FGun()" << std::endl;
}

void FGun::Shoot(Vector2 target)
{
	// TraceLog(LOG_INFO, "FGun::Shoot()");
	std::unique_ptr<FAmmo> ammo(new FAmmo(m_position, target, 1, 75, 100, LoadTexture("resources/assets/ammo.png")));
	FSceneManager::AddObjectToActiveScene(std::move(ammo));
}

void FGun::Update(float dt)
{
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